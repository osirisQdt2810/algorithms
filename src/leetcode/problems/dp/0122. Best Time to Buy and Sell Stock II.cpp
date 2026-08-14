#include <unordered_map>
#include <set>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/*
    LC 122 - Best Time to Buy and Sell Stock II
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

    Problem:
        You are given an integer array prices where prices[i] is the price of a given stock on the
        i-th day.
        On each day, you may decide to buy and/or sell the stock. You can only hold at most one share
        of the stock at any time. However, you can sell and buy the stock multiple times on the same
        day, ensuring you never hold more than one share of the stock.
        Find and return the maximum profit you can achieve.

        Constraints:
          - 1 <= prices.length <= 3 * 10^4
          - 0 <= prices[i] <= 10^4

    Examples:
        Example 1:
            Input: prices = [7,1,5,3,6,4]
            Output: 7
            Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
            Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
            Total profit is 4 + 3 = 7.

        Example 2:
            Input: prices = [1,2,3,4,5]
            Output: 4
            Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
            Total profit is 4.

        Example 3:
            Input: prices = [7,6,4,3,1]
            Output: 0
            Explanation: There is no way to make a positive profit, so we never buy the stock to
            achieve the maximum profit of 0.

    Best solution:
        Greedy: sum every positive consecutive-day price difference. (Equivalently, the collapsed
        O(1)-space form of the two-state hold/free DP - both are O(n), the greedy with O(1) space.)

    Time & Space complexity:
        Time:  O(n)
               - a single pass comparing each day to the previous one.
        Space: O(1)
               - one running accumulator; no table is materialised.

    Approach (detail):
        1. Model the problem as the two-state DP over days: free[i] = best profit on day i holding
           nothing, hold[i] = best profit on day i holding one share.
             free[i] = max(free[i-1], hold[i-1] + prices[i])
             hold[i] = max(hold[i-1], free[i-1] - prices[i])
           with free[0] = 0, hold[0] = -prices[0]; the answer is free[n-1]. Unlimited transactions is
           what makes this a plain two-state recurrence with no transaction counter.
        2. This DP admits a closed form. Any profitable strategy is a set of disjoint
           buy-day/sell-day intervals, and the profit of an interval [b, s] telescopes into the sum of
           its consecutive daily deltas: prices[s] - prices[b] = sum of (prices[j] - prices[j-1]) for
           j in (b, s].
        3. So the total profit of any strategy is a sum of a chosen subset of the n-1 daily deltas,
           subject only to the chosen deltas forming disjoint runs. Because single days count as valid
           intervals, *every* subset of deltas is achievable - buying at the close of day j-1 and
           selling on day j realises delta j on its own, and same-day sell-then-rebuy chains adjacent
           deltas at no cost.
        4. Maximising a freely chosen subset sum means taking exactly the positive deltas and skipping
           the non-positive ones. Hence profit = sum over j of max(0, prices[j] - prices[j-1]).
        5. Correctness of the greedy therefore does not rest on an exchange argument about which peaks
           to pick: the delta decomposition shows the feasible set is the full power set of deltas, so
           the pointwise-best choice is globally optimal. It also automatically returns 0 for a
           monotonically decreasing sequence, matching Example 3.

    Your solution:
        MATCHES BEST - the code adds prices[i] - prices[i-1] whenever it is positive, which is exactly
        the documented greedy closed form, at O(n) time and O(1) space. Note the algorithm actually
        run here is the greedy, not an explicit DP table; it is filed under the dp/ topic because it is
        the collapsed form of the hold/free recurrence in step 1 and LeetCode tags the problem as
        dynamic programming as well as greedy.
*/

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            int n = prices.size();
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
