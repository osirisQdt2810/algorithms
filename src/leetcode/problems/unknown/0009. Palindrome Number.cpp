#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Given an integer x, return true if x is a palindrome, and false otherwise.
 * @cond
 *      -2^31 <= x <= 2^31 - 1
 * @example
        Example 1:

        Input: x = 121
        Output: true
        Explanation: 121 reads as 121 from left to right and from right to left.
        Example 2:

        Input: x = -121
        Output: false
        Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
        Example 3:

        Input: x = 10
        Output: false
        Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */
class Solution {
    public:
        bool isPalindrome2(int x) {
            if (x < 0) return false;
            vector<int> digits;
            while (x){
                digits.push_back(x % 10);
                x /= 10;
            }
            int l = 0, r = digits.size() - 1;
            while (r - l >= 1){
                if (digits[l] != digits[r]) return false;
                ++l;
                --r;
            }
            return true;
        }

        bool isPalindrome(int x) {
            if (x < 0) return false;
            int revNum = 0, clone = x;
            while (x){
                revNum = (revNum * 10) + (x % 10);
                x /= 10;
            }
            return revNum == clone;
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
    cout << (sol.isPalindrome(121) ? "true" : "false") << "\n";
    return 0;
}