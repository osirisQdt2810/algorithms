#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int res = 0, n = s.size();
            int lastPos = n - 1;
            while (lastPos >= 0 && s[lastPos] == ' ') --lastPos;

            while (lastPos >= 0 && s[lastPos] != ' '){
                ++res;
                --lastPos;
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
    
    return 0;
}