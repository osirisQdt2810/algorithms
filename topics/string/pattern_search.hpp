#ifndef DSA_STRING_PATTERN_SEARCH_HPP
#define DSA_STRING_PATTERN_SEARCH_HPP

#include <string>
#include <vector>

namespace dsa::string {

    class PatternSearch {
        public:
            /**
             * @brief z[i] = length of longest substring starting at s[i] that is also a prefix of s
             */
            static inline std::vector<int> z_function(const std::string& s) {
                // we call [l, r) is the largest prefix substring array before current iteration `i`, which means: s[0...r-l-1] = s[l...r-1]
                //                  0..............r-l ________________ l .............r
                // case 1: i < r    0...i-l........r-l _______________________i
                //       meanwhile: s[0...z[i-l]-1] = s[i-l, i-l+z[i-l]-1]
                //      => at least we have [i...r) = [i-l, r-l] => z[i] = min(z[i-l], r-i)
                // case 2: i > r    easily increase i until s[i+z[i]] != s[z[i]]
                // update new (l, r)
                int n = s.size();
                std::vector<int> z(n);
                int l = 0, r = 0;
                for (int i = 1; i < n; ++i){
                    if (i < r) z[i] = std::min(r - i, z[i-l]);
                    while (i+z[i] < n && s[i+z[i]] == s[z[i]]) ++z[i];
                    if (i + z[i] > r){
                        l = i;
                        r = i + z[i];
                    }
                }
                return z;
            }

            /**
             * @brief pi[i] = length of longest proper prefix of s[0..i] that is also a suffix (KMP failure function)
             */
            static inline std::vector<int> prefix_function(const std::string& s) {
                // 0...p[i-1]....i-1 i
                // target in index i: find all suffixes end by `s[i]` (s[k->i]), which matched with prefix string [0->(i-k)]
                // 1. we have T1=p[i-1]: [0.........T1-1] T1 .... [T1(i-1)....i-1] i 
                //      => have: s[0.........T1-1] = s[T1(i-1)....i-1]
                //      => check: if s[T1] = s[i] or not
                //          - if yes: => obviously p[i] = T1+1
                //          - otherwise:  
                //              2. we have T2=p[T1-1]: [0...T2-1] T2 ... [X(T1)...T1-1] ..... [T2(i-1)...i-1] i
                //              => have: s[0...T2-1] = s[X(T1)...T1-1] = s[T2(i-1)...i-1]
                //              => check: if s[T2] = s[i] or not
                //                  - if yes => obviously p[i] = T2+1
                //                  - otherwise: continously doing with T3 = p[T2-1]
                int n = s.size();
                std::vector<int> p(n);
                for (int i = 1; i < n; ++i){
                    int j = p[i-1];
                    while (j > 0 && s[j] != s[i]) j = p[j-1];
                    if (s[j] == s[i]) ++j;
                    p[i] = j;
                }
                return p;
            }
    };
}  // namespace dsa::string

#endif  // DSA_STRING_PATTERN_SEARCH_HPP
