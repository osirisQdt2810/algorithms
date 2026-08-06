#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3499 - Maximize Active Section with Trade I
 * https://leetcode.com/problems/maximize-active-section-with-trade-i/
 *
 * Problem:
 *   You are given a binary string s of length n, where:
 *     - '1' represents an active section.
 *     - '0' represents an inactive section.
 *
 *   You can perform at most one trade to maximize the number of active sections
 *   in s. In a trade, you:
 *     - Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
 *     - Afterward, convert a contiguous block of '0's that is surrounded by '1's
 *       to all '1's.
 *
 *   Return the maximum number of active sections in s after making the optimal
 *   trade.
 *
 *   Note: Treat s as if it is augmented with a '1' at both ends, forming
 *   t = '1' + s + '1'. The augmented '1's do not contribute to the final count.
 *
 *   Constraints:
 *     - 1 <= n == s.length <= 10^5
 *     - s[i] is either '0' or '1'
 *
 * Examples:
 *   Example 1:
 *     Input:  s = "01"
 *     Output: 1
 *     Explanation: Because there is no block of '1's surrounded by '0's, no
 *       valid trade is possible. The maximum number of active sections is 1.
 *
 *   Example 2:
 *     Input:  s = "0100"
 *     Output: 4
 *     Explanation: String "0100" -> Augmented to "101001". Choose "0100",
 *       convert "101001" -> "100001" -> "111111". The final string without
 *       augmentation is "1111". The maximum number of active sections is 4.
 *
 *   Example 3:
 *     Input:  s = "1000100"
 *     Output: 7
 *     Explanation: String "1000100" -> Augmented to "110001001". Choose
 *       "000100", convert "110001001" -> "110000001" -> "111111111". The final
 *       string without augmentation is "1111111". The maximum number of active
 *       sections is 7.
 *
 * Best solution: Run-length decomposition + a single scan maximizing the pair
 * of zero-runs flanking one interior one-run. Optimal in time; the space can be
 * reduced to O(1) by carrying only the previous two run lengths instead of
 * materializing the full run list.
 *
 * Time:  O(n) — one pass builds the runs, one pass scans them; the number of
 *        runs is at most n.
 * Space: O(1) auxiliary in the streaming formulation (the version here stores
 *        the run list, which is O(n) in the worst case, e.g. "010101...").
 *
 * Approach (detail):
 *   1. Reframe the trade. Pick an interior block of '1's whose immediate
 *      neighbours on both sides are '0' blocks. Zeroing that one-run makes the
 *      three runs [zeros_left][ones_mid][zeros_right] fuse into a single
 *      contiguous zero-run. That fused run is bounded by '1' on both sides (by
 *      construction in t = '1' + s + '1', which is exactly what the
 *      augmentation guarantees at the borders), so step two may flip the whole
 *      fused run to '1's.
 *   2. Net effect: the ones_mid we destroyed are handed straight back, and we
 *      additionally gain zeros_left + zeros_right newly active sections. So
 *      answer = total_ones + max over valid mid-runs of (zeros_left + zeros_right),
 *      and "do nothing" (gain 0) is always allowed.
 *   3. Decompose s into alternating runs. Here `blocks` holds
 *      [ones_0, zeros_1, ones_1, zeros_2, ones_2, ...]: even indices are
 *      one-run lengths, odd indices are zero-run lengths. The leading one-run
 *      is emitted first (possibly length 0 when s starts with '0'), which keeps
 *      the even/odd parity invariant for the whole array.
 *   4. total_ones is the sum over even indices. Initialize the answer to it,
 *      covering the no-trade case.
 *   5. Scan even indices i (the one-runs). A run is tradeable only when it is
 *      non-empty and strictly interior — i > 0 and i < nb - 1 — so that
 *      blocks[i-1] and blocks[i+1] are real zero-runs. A leading or trailing
 *      one-run is excluded precisely because in t it merges with an augmented
 *      '1' and therefore is not "surrounded by '0's".
 *   6. For each such run, take the candidate total_ones + blocks[i-1] +
 *      blocks[i+1] and keep the maximum.
 *   7. Early exit: if s is all '1's there is no zero at all, so no trade exists
 *      and the answer is n.
 *   8. Why one pass suffices: the trades are mutually exclusive (only one is
 *      permitted), and each candidate's gain depends solely on its own two
 *      neighbouring zero-runs, so the best trade is just the best single term —
 *      no interaction between candidates to reason about.
 */

class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            vector<int> blocks;
            int i = 0, n = s.size();
            while (i < n && s[i] == '1') ++i;
            if (i == n) return n;
            blocks.push_back(i);
            while (i < n){
                int j = i;
                while (j < n && s[j] == '0') ++j;
                int k = j;
                while (k < n && s[k] == '1') ++k;
                blocks.push_back(j - i);
                blocks.push_back(k - j);
                i = k;
            }
            int nb = blocks.size(), total_actives = 0;
            for (int i = 0; i < nb; i += 2){
                total_actives += blocks[i];
            }

            int res = total_actives;
            for (int i = 0; i < nb; i += 2){
                if (!blocks[i]) continue;
                if (i > 0 && i<nb-1 && blocks[i-1] && blocks[i+1]){
                    res = max(res, total_actives + blocks[i-1] + blocks[i+1]);
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

    return 0;
}