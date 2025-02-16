#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), ans = 0;
        for (char c = 'a'; c <= 'z'; ++c){
            int l = 0, r = n-1;
            while (l < n && s[l] != c) ++l;
            if (l == n) continue;
            while (r >= 0 && s[r] != c) --r;
            if (r == l) continue;

            std::unordered_set<char> uniques;
            for (int m = l + 1; m <= r - 1; ++m)
                if (uniques.find(s[m]) == uniques.end())
                    uniques.insert(s[m]);
            
            ans += uniques.size();
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
    // string boxes = "110";
    // string s = "abc";
    // vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};

    string s = "bbcbaba";

    Solution sol;
    cout << sol.countPalindromicSubsequence(s);
    return 0;
}