#include <unordered_map>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
LC 1143 - Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/

Problem:
    Given two strings text1 and text2, return the length of their longest common
    subsequence. If there is no common subsequence, return 0.
    A subsequence of a string is a new string generated from the original string
    with some characters (can be none) deleted without changing the relative order
    of the remaining characters (e.g. "ace" is a subsequence of "abcde"). A common
    subsequence of two strings is a subsequence that is common to both strings.

    Constraints:
        1 <= text1.length, text2.length <= 1000
        text1 and text2 consist of only lowercase English characters.

Examples:
    Input: text1 = "abcde", text2 = "ace"
    Output: 3
    Explanation: The longest common subsequence is "ace" and its length is 3.

    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.

    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.

Best solution:
    Classic two-string LCS dynamic programming, kept to two rolling rows so the
    table never has to be materialised in full.

Time & Space complexity:
    Time:  O(M*N) - every (prefix, prefix) pair is settled once in O(1).
    Space: O(min(M, N)) - only the previous and current DP row, with the shorter
           string chosen as the row axis.

Approach (detail):
    1. Let dp[i][j] be the LCS length of the prefixes text1[0..i) and text2[0..j).
       The empty prefix has no common subsequence, so dp[0][*] = dp[*][0] = 0.
    2. Recurrence on the last characters:
       - if text1[i-1] == text2[j-1], that shared character can always be appended
         to a best LCS of the two shorter prefixes, so dp[i][j] = dp[i-1][j-1] + 1;
       - otherwise the last characters cannot both be used, so at least one of them
         is dropped: dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
    3. Why the match case needs no max: dp is monotone non-decreasing in each index,
       and dp[i-1][j] and dp[i][j-1] are both at most dp[i-1][j-1] + 1, so taking
       the diagonal + 1 already dominates them. Including the max is harmless but
       redundant.
    4. Fill row by row; the answer is dp[M][N].
    5. Space reduction: row i depends only on row i-1 and on the entry to its left,
       so two rows of length min(M, N) + 1 suffice (or one row plus a saved
       diagonal). Iterating with the shorter string on the row axis bounds memory
       by min(M, N).
    6. O(M*N) time is the practical optimum here: general LCS has no known
       strongly-subquadratic algorithm, and a truly subquadratic one would refute
       the Strong Exponential Time Hypothesis.

Your solution:
    SUBOPTIMAL - the recurrence and the loop order are exactly the optimal DP and
    the running time is O(M*N), which matches the best known. The gap is memory: the
    code allocates the entire (M+1) x (N+1) table, so Space is O(M*N) against the
    O(min(M, N)) of the rolling-row form - 1001*1001 ints, about 4 MB at the
    constraint limit, which passes comfortably but is ~1000x more than needed.
*/

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int M = text1.size(), N = text2.size();
            vector<vector<int>> dp(M+1, vector<int>(N+1, 0));

            for (int i = 0; i < M; ++i){
                for (int j = 0; j < N; ++j){
                    if (text1[i] == text2[j]){
                        dp[i+1][j+1] = dp[i][j] + 1;
                    }
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
                }
            }
            return dp[M][N];
        }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
