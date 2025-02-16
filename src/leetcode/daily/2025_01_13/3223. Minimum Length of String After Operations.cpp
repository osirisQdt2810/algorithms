#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minimumLength(string s) {
            unordered_map<char, int> chars;
            for (char c : s){
                if (chars.find(c) == chars.end())
                    chars[c] = 0;

                ++chars[c];
            }
            
            int counter = 0;
            for (auto& [c, f] : chars)
                counter += (f % 2) ? 1 : 2; 
            
            return counter;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();