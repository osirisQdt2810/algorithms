#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
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

        int findLeftMostOccurence(const string& s, const string& pattern){
            static const char DELIMITER = '.';
            string T = pattern + DELIMITER + s;
            auto z_res = z_algo(T);
            vector<int> res;
            for (int i = 0; i < z_res.size(); ++i)
                if (z_res[i] == static_cast<int>(pattern.length()))
                    return i - pattern.length() - 1;
            
            return -1;
        }

        string trim(string& s, int start_pos, int len){
            return s.erase(start_pos, len);
        }

    public:
        string removeOccurrences(string s, string part) {
            int pos = findLeftMostOccurence(s, part);
            while (pos != -1){
                s = trim(s, pos, part.length());
                pos = findLeftMostOccurence(s, part);
            }
            return s;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    string s = "ag33asdasd", part = "3";

    cout << sol.removeOccurrences(s, part);

    return 0;
}