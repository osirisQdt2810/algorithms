#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            using ic = pair<int, char>;
            deque<ic> digits;
            deque<ic> chars;
            int n = s.size();
            for (int i = 0; i < n; ++i){
                if ('0' <= s[i] && s[i] <= '9'){
                    if (chars.empty()){
                        digits.push_back({i, s[i]});
                    }
                    else {
                        chars.pop_back();
                    }
                }
                else {
                    chars.push_back({i, s[i]});
                }
            }

            string target = "";
            while (!chars.empty() || !digits.empty()){
                if (chars.empty()){
                    while (!digits.empty()){
                        target += digits.front().second;
                        digits.pop_front();
                    }
                    break;
                }
                if (digits.empty()){
                    while (!chars.empty()){
                        target += chars.front().second;
                        chars.pop_front();
                    }
                    break;
                }
                auto [i1, c1] = chars.front();
                auto [i2, c2] = digits.front();
                if (i1 < i2){
                    target += c1;
                    chars.pop_front();
                }
                else {
                    target += c2;
                    digits.pop_front();
                }
            }

            return target;
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
    vector<int> nums = {2,3,4,6};

    string s = "ag3";
    cout << sol.clearDigits(s);

    return 0;
}