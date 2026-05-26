#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

/*
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.




*/
class Solution {
private:
    bool is_lower(char c){
        return 'a' <= c && c <= 'z';
    }

public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        char l, r;
        int res = 0;

        vector<int> lower(26, false), upper(26, false);

        for (auto c : word){
            if (is_lower(c)){
                l = c - 'a';
                r = c - 32 - 'A';
                res += (!lower[l] && upper[r]);
                lower[l] = true;
            }
            else {
                l = c + 32 - 'a';
                r = c - 'A';
                res += (lower[l] && !upper[r]);
                upper[r] = true;
            }
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
    Solution sol;

    string word = "abBCab";
    cout << sol.numberOfSpecialChars(word) << "\n";
    return 0;
}