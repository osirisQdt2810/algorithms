#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);

        for (int i = 0; i < n; ++i){
            if ('a' <= word[i] && word[i] <= 'z')
                lower[word[i]-'a'] = i;
            else {
                if (upper[word[i]-'A'] < 0)
                    upper[word[i]-'A'] = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i){
            if (lower[i] >= 0 && upper[i] >= 0){
                ans += (lower[i] < upper[i]);
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
    Solution sol;

    string word = "abBCab";
    cout << sol.numberOfSpecialChars(word) << "\n";
    return 0;
}