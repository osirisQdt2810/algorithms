#include <bits/stdc++.h>

using namespace std;

class String {
    public:
        static inline vector<int> z_algo(const string &s) {
            int n(s.size());
            vector<int> z(n);

            int l(0), r(0);
            for (int i=1; i<n; i++) {
                if (i > r) {
                    l = r = i;
                    while (r<n && s[r-l]==s[r]) r += 1;
                    z[i] = r - l;
                    r -= 1;
                } else if (z[i-l] < r-i+1) {
                    z[i] = z[i-l];
                } else {
                    l = i;
                    while (r<n && s[r-l]==s[r]) r += 1;
                    z[i] = r - l;
                    r -= 1;
                }
            }
            return z;
        }

        static inline vector<int> pattern_matching(const string& s, const string& pattern){
            static const char DELIMITER = '.';
            string T = pattern + DELIMITER + s;
            auto z_res = z_algo(T);
            vector<int> res;
            for (int i = 0; i < z_res.size(); ++i)
                if (z_res[i] == static_cast<int>(pattern.length()))
                    res.push_back(i - pattern.length() - 1);
            return res;
        }

        static inline bool contains(const string& s, const string& pattern){
            static const char DELIMITER = '.';
            string T = pattern + DELIMITER + s;
            auto z_res = z_algo(T);
            for (int i = 0; i < z_res.size(); ++i)
                if (z_res[i] == static_cast<int>(pattern.length()))
                    return true;
            return false;
        }
};

class Solution {
    public:
        vector<string> stringMatching(vector<string>& words) {
            int n = words.size();
            vector<string> res;
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (i != j && String::contains(words[j], words[i])){
                        res.push_back(words[i]);
                        break;
                    }
                }
            }
            return res;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    vector<string> words = {"mass","as","hero","superhero"};
    Solution sol;

    for (auto r : sol.stringMatching(words))
        cout << r << " ";

    return 0;
}