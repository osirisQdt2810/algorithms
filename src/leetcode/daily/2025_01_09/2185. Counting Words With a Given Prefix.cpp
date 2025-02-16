#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int prefixCount(vector<string>& words, string pref) {
            int count = 0;
            for (auto& word : words)
                count += (word.find(pref) == 0);
            return count;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();