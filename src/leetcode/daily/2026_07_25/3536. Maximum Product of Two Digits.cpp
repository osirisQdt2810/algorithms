#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3536 - Maximum Product of Two Digits
 *
 * Best solution: Single pass over the decimal digits, tracking only the two
 * largest seen so far. Optimal — every digit must be examined at least once,
 * and this does exactly one constant-work visit per digit with no allocation.
 *
 * Time:  O(d) = O(log n) — one iteration per decimal digit of n, each doing a
 *        modulo, a divide, and at most two comparisons.
 * Space: O(1) — two scalars; the digits are never materialized into an array,
 *        so no sort and no O(d) buffer.
 *
 * Approach (detail):
 *   1. The product of two chosen digits is maximized by the two largest
 *      digits. All digits are in [0, 9] — non-negative — so unlike the
 *      general "max product of two array elements" case there is no
 *      two-negatives trick to consider: bigger factors always win.
 *   2. Extract digits right-to-left with d = n % 10 then n /= 10, looping
 *      until n becomes 0.
 *   3. Maintain a running top-2 (max_d, secmax_d), both seeded to -1:
 *      - if d > max_d: shift the old maximum down (secmax_d = max_d) and set
 *        max_d = d;
 *      - else if d > secmax_d: only the runner-up improves.
 *      The `else if` chain is what keeps the pair correct — the shift-down in
 *      the first branch is essential, otherwise a new maximum would silently
 *      discard the previous one.
 *   4. Using strict `>` (rather than `>=`) is still correct for repeated
 *      digits: a duplicate d equal to max_d falls into the second branch and
 *      correctly becomes the runner-up, so inputs like 77 yield 7 * 7 = 49.
 *   5. Return max_d * secmax_d. Constraints guarantee n has at least two
 *      digits, so secmax_d is always overwritten from its -1 sentinel.
 */

class Solution {
    public:
        int maxProduct(int n) {
            int max_d = -1, secmax_d = -1;
            while (n){
                int d = n % 10;
                if (d > max_d){
                    secmax_d = max_d;
                    max_d = d;
                }
                else if (d > secmax_d){
                    secmax_d = d;
                }
                n /= 10;
            }
            return max_d * secmax_d;
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