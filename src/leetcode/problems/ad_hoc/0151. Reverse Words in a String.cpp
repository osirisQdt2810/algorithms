#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            s = ' ' + s + ' ';
            int n = s.size();
            int prev = n - 1, pos = n - 1;
            while (pos >= 0){
                while (pos >= 0 && s[pos] != ' ') --pos;
                if (pos < 0) break;
                if (pos + 1 < prev) s += ' ';
                for (int i = pos + 1; i <= prev - 1; ++i) s += s[i];
                prev = pos;
                --pos;
            }

            s.erase(s.begin(), s.begin() + n);
            s.erase(s.begin());
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
    // string s = "the sky is blue";
    // string s = "  hello world  ";
    string s = "a good   example";
    string t =  sol.reverseWords(s);
    cout << " |" << t << "|\n";

    return 0;
}