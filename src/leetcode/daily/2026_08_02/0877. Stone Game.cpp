#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 1406 - Stone Game III
 * https://leetcode.com/problems/stone-game-iii/
 * (note: the filename says 0877 "Stone Game", but the code below solves
 *  stoneGameIII — LC 1406 — so this annotation documents LC 1406)
 *
 * Problem:
 *   Alice and Bob continue their games with piles of stones. There are several
 *   stones arranged in a row, and each stone has an associated value which is an
 *   integer given in the array stoneValue.
 *
 *   Alice and Bob take turns, with Alice starting first. On each player's turn,
 *   that player can take 1, 2, or 3 stones from the first remaining stones in
 *   the row.
 *
 *   The score of each player is the sum of the values of the stones taken. The
 *   score of each player is 0 initially.
 *
 *   The objective of the game is to end with the highest score, and the winner
 *   is the player with the highest score and there could be a tie. The game
 *   continues until all the stones have been taken.
 *
 *   Assume Alice and Bob play optimally.
 *
 *   Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they
 *   will end the game with the same score.
 *
 *   Constraints:
 *     - 1 <= stoneValue.length <= 5 * 10^4
 *     - -1000 <= stoneValue[i] <= 1000
 *
 * Examples:
 *   Example 1:
 *     Input:  stoneValue = [1,2,3,7]
 *     Output: "Bob"
 *     Explanation: Alice will always lose. Her best move will be to take three
 *       piles and the score become 6. Now the score of Bob is 7 and Bob wins.
 *
 *   Example 2:
 *     Input:  stoneValue = [1,2,3,-9]
 *     Output: "Alice"
 *     Explanation: Alice must choose all the three piles at the first move to
 *       win and leave Bob with negative score. If Alice chooses one pile her
 *       score will be 1 and the next move Bob's score becomes 5. In the next
 *       move, Alice will take the pile with value = -9 and lose. If Alice
 *       chooses two piles her score will be 3 and the next move Bob's score
 *       becomes 3. In the next move, Alice will take the pile with value = -9
 *       and also lose.
 *
 *   Example 3:
 *     Input:  stoneValue = [1,2,3,6]
 *     Output: "Tie"
 *     Explanation: Alice cannot win this game. She can end the game in a draw if
 *       she decided to choose all the first three piles, otherwise she will
 *       lose.
 *
 * Best solution: 1-D suffix DP on the *score difference* (minimax collapsed to a
 * single value). Optimal — n states, each resolved from three already-computed
 * successors in O(1).
 *
 * Time:  O(n) — exactly one state per suffix start index, constant work each
 *        (the branching factor is the fixed constant 3).
 * Space: O(n) for the memo; reducible to O(1) by iterating i downward and
 *        keeping only the next three values in a rolling window.
 *
 * Approach (detail):
 *   1. Key insight: because stones may only be taken from the *front* of the
 *      remaining row, every reachable position is a suffix stoneValue[i..n-1].
 *      That is a single index, not an interval — which is what makes this O(n)
 *      rather than the O(n^2) of interval games like LC 486.
 *   2. As in any zero-sum turn game, track the difference rather than two
 *      scores. Define f(i) = the best achievable (current player's score -
 *      opponent's score) over the suffix starting at i, with the current player
 *      to move. Whose turn it is need not be stored: the position alone
 *      determines the value from the mover's perspective.
 *   3. Recurrence — the mover takes 1, 2, or 3 stones:
 *        f(i) = max( v[i]                     - f(i+1),
 *                    v[i] + v[i+1]            - f(i+2),
 *                    v[i] + v[i+1] + v[i+2]   - f(i+3) )
 *      guarding the second and third options against running past the end. The
 *      minus sign is the turn flip: after the move, the opponent faces the
 *      remaining suffix as the new "current player" and secures f(i+k) for
 *      themselves, which counts against us.
 *   4. Base case: f(n) = 0 — no stones remain, so the difference is 0.
 *   5. Memoize with a sentinel (kNil = INT_MIN) for "not yet computed"; 0 would
 *      be an unusable sentinel because a genuine difference of 0 is common (any
 *      tie position, e.g. Example 3).
 *   6. Note that negative stone values do not break the greedy-free DP — taking
 *      more stones is not always better, which is exactly why all three options
 *      must be enumerated rather than heuristically choosing the largest prefix.
 *   7. Decide the winner from d = f(0), Alice's optimal difference over the
 *      whole row: d > 0 -> "Alice", d < 0 -> "Bob", d == 0 -> "Tie".
 *   8. Caveat on the recursive form: with n up to 5*10^4 the recursion depth can
 *      reach n, so the bottom-up rolling-window version is the safer shape for
 *      the true worst case.
 */

class Solution {
    private:
        static inline const int kNil = INT_MIN;

        int dp(int i, vector<int>& memo, vector<int>& nums){
            if (i == nums.size()) return 0;
            if (memo[i] != kNil) return memo[i];
            memo[i] = nums[i] - dp(i+1, memo, nums);
            if (i + 1 < nums.size()) memo[i] = max(memo[i], nums[i] + nums[i+1] - dp(i+2, memo, nums));
            if (i + 2 < nums.size()) memo[i] = max(memo[i], nums[i] + nums[i+1] + nums[i+2] - dp(i+3, memo, nums));
            return memo[i];
        }

    public:
        string stoneGameIII(vector<int>& stoneValue) {
            // f(i) = max(nums[i] - f(i+1), nums[i] + nums[i+1] - f(i+2), nums[i] + nums[i+1] + nums[i+2] - f(i+3))
            int n = stoneValue.size();
            vector<int> memo(n, kNil);   // dp[l][r]
            int diff = dp(0, memo, stoneValue);
            if (diff > 0) return "Alice";
            if (diff < 0) return "Bob";
            return "Tie";
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