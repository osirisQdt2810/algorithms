#ifndef DSA_STRING_STRING_MATCHING_HPP
#define DSA_STRING_STRING_MATCHING_HPP

#include "arithmetic/algebra.hpp"
#include "string/pattern_search.hpp"
#include "string/rolling_hash.hpp"
#include <string>
#include <vector>

namespace dsa::string {
    class StringMatching {
        public:
            /**
             * @brief Find all occurrences of pattern in s using Z-function.
             */
            static inline std::vector<int> z_matching(const std::string& s, const std::string& pattern) {
                static const char DELIMITER = '.';
                std::string T = pattern + DELIMITER + s;
                auto z = PatternSearch::z_function(T);

                std::vector<int> res;
                int p_size = static_cast<int>(pattern.size());
                for (int i = p_size + 1; i < static_cast<int>(T.size()); ++i) {
                    if (z[i] == p_size)
                        res.push_back(i - p_size - 1);
                }
                return res;
            }

            /**
             * @brief Find all occurrences of pattern in s using KMP (prefix function).
             */
            static inline std::vector<int> kmp_matching(const std::string& s, const std::string& pattern) {
                std::string T = pattern + '#' + s;
                auto pi = PatternSearch::prefix_function(T);

                std::vector<int> res;
                int p_size = static_cast<int>(pattern.size());
                for (int i = p_size + 1; i < static_cast<int>(T.size()); ++i) {
                    if (pi[i] == p_size)
                        res.push_back(i - 2 * p_size);
                }
                return res;
            }

            /**
             * @brief Find all occurrences of pattern in s using Rabin-Karp rolling hash.
             * @param assurance if true, verifies hash matches with direct string comparison
             */
            static inline std::vector<int> rabin_karp(const std::string& s, const std::string& pattern) {
                int p_size = pattern.size(), s_size = s.size();
                std::vector<int> res;

                HashType pattern_hash = StringHash<HashPolicy::Backward>::hash(pattern);
                HashType scale = Algebra::mod_power(HASH_BASE, p_size, HASH_MOD);
                auto hasher = StringHash<HashPolicy::Backward>(s);
                for (int i = 0; i < s_size - p_size + 1; ++i) {
                    HashType h = (hasher.hash(i + p_size - 1) - hasher.hash(i - 1) * scale % HASH_MOD + HASH_MOD) % HASH_MOD;
                    if (h == pattern_hash)
                        res.push_back(i);
                }
                return res;
            }
    };

}  // namespace dsa::string

#endif  // DSA_STRING_STRING_MATCHING_HPP
