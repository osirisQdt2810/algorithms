#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isValidLength(const string& s, int sz, int len){
            map<char, int> freqs;
            map<char, int> counter;
            for (char c = 'a'; c <= 'z'; ++c){
                freqs[c] = 0;
                counter[c] = 0;
            }

            for (int i = 0; i < len; ++i){
                ++freqs[s[i]];
                if (i == len - 1 && freqs[s[i]] == len){
                    ++counter[s[i]];
                }
            }

            for (int i = len; i < sz; ++i){
                --freqs[s[i - len]];
                ++freqs[s[i]];
                if (freqs[s[i]] == len){
                    ++counter[s[i]];
                    if (counter[s[i]] >= 3){
                        return true;
                    }
                }
            }
            return false;
        }

        int maximumLength(string s) {
            int n = s.size();
            int l = 0, r = n - 2, ans = -1;
            while (l <= r){
                int m = (l + r) / 2;
                if (isValidLength(s, n, m)){
                    ans = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            return ans;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // string s = "aaaa";
    string s = "cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde";

    Solution sol;
    cout << sol.maximumLength(s);

    return 0;
}