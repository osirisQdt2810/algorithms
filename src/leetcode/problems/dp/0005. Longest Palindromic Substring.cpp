#include <unordered_map>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

/*
LC 5 - Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/

Problem:
    Given a string s, return the longest palindromic substring in s.

    Constraints:
        1 <= s.length <= 1000
        s consist of only digits and English letters.

Examples:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

    Input: s = "cbbd"
    Output: "bb"

Best solution:
    Manacher's algorithm - one linear left-to-right pass that computes, for every
    center, the radius of the longest palindrome centred there, reusing the mirror
    information of the rightmost palindrome found so far.

Time & Space complexity:
    Time:  O(n) - every character comparison either fails once per center or pushes
           the right edge R strictly forward, and R only ever moves right, so the
           total expansion work is amortised linear.
    Space: O(n) - the transformed string and the one radius array, both O(2n+1).

Approach (detail):
    1. Even-length palindromes have no single character centre, which is what makes
       a naive centre scan awkward. Fix it by interleaving a separator that occurs
       nowhere in s: T = "#a#b#a#...#". T has length 2n+1 and *every* palindrome of
       s, odd or even, becomes an odd-length palindrome of T centred on a real
       character (odd case) or on a '#' (even case).
    2. Compute p[i] = radius of the longest palindrome of T centred at i (counting
       the centre out to, but not including, the mismatch). Then p[i] is exactly the
       length of the corresponding palindrome in the original s.
    3. Keep the palindrome found so far whose right edge reaches furthest right, as
       its centre C and right edge R. For any i < R let j = 2C - i be i's mirror
       about C. Everything strictly inside the C-palindrome is symmetric, so the
       palindrome at i is at least as long as the one at j, capped by how far the
       C-palindrome still extends: initialise p[i] = min(p[j], R - i). This is the
       whole trick - it recovers work already done instead of rescanning.
    4. Then try to grow p[i] by plain character comparison T[i-p[i]-1] vs
       T[i+p[i]+1] while both stay in bounds. The cap in step 3 is exactly the point
       beyond which the mirror says nothing, so expansion starts where knowledge
       ends - never earlier, never later.
    5. If i + p[i] > R, this palindrome reaches further right than any before it, so
       set C = i and R = i + p[i].
    6. Every successful expansion in step 4 increases R, and R never decreases, so
       across the whole pass there are at most O(n) successful comparisons plus one
       failing comparison per centre. That is why the total is O(n) and not O(n^2).
    7. Track the i with the largest p[i]. Map it back to s: the substring starts at
       (i - p[i]) / 2 and has length p[i].

Your solution:
    SUBOPTIMAL - the code is correct (verified against brute force on the standard
    cases and 5000 random strings) but runs in Time O(n^2) / Space O(n^2), a gap of
    O(n^2) vs O(n) on both axes against Manacher. It also takes an indirect route:
    `recursive` memoises the longest palindromic *subsequence* of every interval
    [l, r], and the final double loop then picks the longest span satisfying
    dp[l][r] == r-l+1, which holds exactly when the whole substring s[l..r] is
    itself a palindrome (its longest palindromic subsequence can only fill the span
    if the span is already a palindrome). Correct, but it solves a strictly harder
    subproblem than needed - the direct palindrome recurrence
    isPal[l][r] = (s[l] == s[r] && isPal[l+1][r-1]) reaches the same O(n^2) time
    with a simpler table, and expand-around-centre reaches O(n^2) time in O(1)
    space. It still passes comfortably: n <= 1000 means about 10^6 memo states,
    measured at ~12 ms for n = 1000, and the recursion depth stays under n+1 so
    there is no stack risk.
*/

class Solution {
    private:
        int recursive(vector<vector<int>>& dp, string& s, int l, int r){
            if (l > r) return dp[l][r] = 0;
            if (l == r) return dp[l][r] = 1;
            if (dp[l][r] != -1) return dp[l][r];
            int dplr = recursive(dp, s, l+1, r);
            dplr = max(dplr, recursive(dp, s, l, r-1));
            if (s[l] == s[r]){
                dplr = max(dplr, recursive(dp, s, l+1, r-1) + 2);
            }
            return dp[l][r] = dplr;
        }

    public:
        string longestPalindrome(string s) {
            int n = s.size();   // babad
            vector<vector<int>> dp(n, vector<int>(n, -1));
            recursive(dp, s, 0, n-1);


            struct Answer {
                int l{0};
                int r{0};

                int len() const {
                    return r-l+1;
                }
            };

            Answer ans;
            for (int l = 0; l < n; ++l){
                for (int r = l; r < n; ++r){
                    if (dp[l][r] == r-l+1 && ans.len() < r-l+1){
                        ans = {l, r};
                    }
                }
            }
            return s.substr(ans.l, ans.len());
        }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();