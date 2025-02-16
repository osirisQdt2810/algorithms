#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool areAlmostEqual(string s1, string s2) {
            int diffPos = 0, n = s1.length();
            vector<char> sd1, sd2;
            for (int i = 0; i < n; ++i){
                if (s1[i] != s2[i]){
                    if (++diffPos > 2) return false;
                    sd1.push_back(s1[i]);
                    sd2.push_back(s2[i]);
                }
            }

            if (diffPos == 0) return true;
            if (diffPos != 2) return false;
            return sd1[0] == sd2[1] && sd1[1] == sd2[0];
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
    string s1 = "bank", s2 = "kanb";
    cout << (sol.areAlmostEqual(s1, s2) ? "true" : "false");

    return 0;
}