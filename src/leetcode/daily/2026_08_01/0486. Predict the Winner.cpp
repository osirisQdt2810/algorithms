#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 486 - Predict the Winner
 * https://leetcode.com/problems/predict-the-winner/
 *
 * Problem:
 *   You are given an integer array nums. Two players are playing a game with
 *   this array: player 1 and player 2.
 *
 *   Player 1 and player 2 take turns, with player 1 starting first. Both players
 *   start the game with a score of 0. At each turn, the player takes one of the
 *   numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1])
 *   which reduces the size of the array by 1. The player adds the chosen number
 *   to their score. The game ends when there are no more elements in the array.
 *
 *   Return true if Player 1 can win the game. If the scores of both players are
 *   equal, then player 1 is still the winner, and you should also return true.
 *   You may assume that both players are playing optimally.
 *
 *   Constraints:
 *     - 1 <= nums.length <= 20
 *     - 0 <= nums[i] <= 10^7
 *
 * Examples:
 *   Example 1:
 *     Input:  nums = [1,5,2]
 *     Output: false
 *     Explanation: Initially, player 1 can choose between 1 and 2. If he chooses
 *       2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2
 *       chooses 5, then player 1 will be left with 1 (or 2). So, final score of
 *       player 1 is 1 + 2 = 3, and player 2 is 5. Hence, player 1 will never be
 *       the winner and you need to return false.
 *
 *   Example 2:
 *     Input:  nums = [1,5,233,7]
 *     Output: true
 *     Explanation: Player 1 first chooses 1. Then player 2 has to choose between
 *       5 and 7. No matter which number player 2 choose, player 1 can choose
 *       233. Finally, player 1 has more score (234) than player 2 (12), so you
 *       need to return True representing player1 can win.
 *
 * Best solution: Interval DP on the *score difference* (minimax collapsed to a
 * single value). Optimal for this formulation — there are O(n^2) reachable
 * subarray states and each is resolved in O(1).
 *
 * Time:  O(n^2) — one state per interval [i, j], each computed from two
 *        already-solved sub-intervals in constant time.
 * Space: O(n^2) for the memo table; reducible to O(n) by iterating interval
 *        lengths bottom-up and keeping a single rolling row.
 *
 * Approach (detail):
 *   1. Key insight: do not track the two scores separately. Define
 *      f(i, j) = the maximum value of (current player's score - opponent's
 *      score) achievable from the subarray nums[i..j], with the current player
 *      to move. Collapsing two numbers into one difference is what makes the
 *      state space O(n^2) instead of exponential.
 *   2. This works because the game is zero-sum and symmetric: whoever moves next
 *      faces the same problem on a smaller interval, just with the sign of the
 *      difference flipped from the parent's point of view. There is no need to
 *      record whose turn it is.
 *   3. Recurrence — the mover takes either end:
 *        f(i, j) = max( nums[i] - f(i+1, j),      // take the left end
 *                       nums[j] - f(i, j-1) )     // take the right end
 *      The subtraction encodes the turn flip: after taking nums[i], the
 *      opponent becomes the "current player" on [i+1, j] and secures f(i+1, j)
 *      *for themselves*, which counts against us.
 *   4. Base case: f(i, i) = nums[i] — a single element is taken by the mover and
 *      the opponent scores nothing.
 *   5. Memoize on (i, j) with a sentinel (kNil = INT_MIN) marking "not yet
 *      computed"; a plain 0 sentinel would be wrong since a genuine difference
 *      of 0 is reachable (e.g. nums = [1,1]).
 *   6. Answer: player 1 moves first on the whole array, so they win or tie iff
 *      f(0, n-1) >= 0.
 *   7. Both players "playing optimally" is exactly the max in step 3 applied at
 *      every level — the opponent maximizing their own difference is identical
 *      to minimizing ours, so a single max-with-negation handles both roles.
 */

class Solution {
    private:
        static inline const int kNil = INT_MIN;

        int dp(int i, int j, vector<vector<int>>& memo, vector<int>& nums){
            if (memo[i][j] != kNil) return memo[i][j];
            if (i == j) return memo[i][j] = nums[i];
            return memo[i][j] = max(nums[i] - dp(i+1, j, memo, nums), nums[j] - dp(i, j-1, memo, nums));
        }

    public:
        bool predictTheWinner(vector<int>& nums) {
            // f(i,j) = max(nums[i] - f(i+1,j), nums[j] - f(i, j-1))
            int n = nums.size();
            vector<vector<int>> memo(n, vector<int>(n, kNil));   // dp[l][r]
            return dp(0, n-1, memo, nums) >= 0;
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

    return 0;
}