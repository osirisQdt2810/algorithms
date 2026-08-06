#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3345 - Smallest Divisible Digit Product I
 * https://leetcode.com/problems/smallest-divisible-digit-product-i/
 *
 * Problem:
 *   You are given two integers n and t. Return the smallest number greater than
 *   or equal to n such that the product of its digits is divisible by t.
 *
 *   Constraints:
 *     - 1 <= n <= 100
 *     - 1 <= t <= 10
 *
 * Examples:
 *   Example 1:
 *     Input:  n = 10, t = 2
 *     Output: 10
 *     Explanation: The digit product of 10 is 0, which is divisible by 2, making
 *       it the smallest number greater than or equal to 10 that satisfies the
 *       condition.
 *
 *   Example 2:
 *     Input:  n = 15, t = 3
 *     Output: 16
 *     Explanation: The digit product of 16 is 6, which is divisible by 3, making
 *       it the smallest number greater than or equal to 15 that satisfies the
 *       condition.
 *
 * Best solution: Linear upward scan from n, testing the digit product of each
 * candidate. This is optimal here, because the scan is provably O(1)-bounded —
 * see step 4 — so no cleverer construction can beat it asymptotically.
 *
 * Time:  O(1) — the loop runs at most 10 iterations (proof in step 4), and each
 *        digit-product test is O(number of digits) = O(1) for these bounds.
 * Space: O(1) — a couple of integers.
 *
 * Approach (detail):
 *   1. The answer is by definition the first integer at or above n satisfying
 *      the predicate, so scanning upward from n and returning the first hit is
 *      correct by construction — there is nothing to prove about optimality of
 *      the *value*, only about the cost of finding it.
 *   2. is_valid(N, T): peel digits off N with repeated % 10 and / 10,
 *      multiplying them into `prod`, then test prod % T == 0.
 *   3. A subtlety that makes the problem easy: any number containing the digit 0
 *      has digit product 0, and 0 is divisible by every t >= 1. So every such
 *      number satisfies the predicate immediately.
 *   4. Termination bound: among any 10 consecutive integers >= 10 there is at
 *      least one whose last digit is 0, and by step 3 that one is always valid.
 *      Hence the scan halts within 10 steps of n. (For n < 10 the single-digit
 *      candidates are checked first and 10 itself is reached in at most 10
 *      steps, so the bound holds throughout.)
 *   5. Return the first valid candidate. Because the scan is strictly ascending
 *      and starts exactly at n, the value returned is the minimum over all valid
 *      candidates >= n.
 *   6. Note the constraints (n <= 100, t <= 10) are what license the direct
 *      scan; the harder sequel raises the bounds so that a digit-DP / factor
 *      analysis over powers of 2, 3, 5, 7 becomes necessary.
 */

class Solution {
    public:
        int smallestNumber(int n, int t) {
            auto is_valid = [&](int N, int T){
                int prod = 1;
                while (N){
                    prod *= (N % 10);
                    N /= 10;
                }
                return (prod % T == 0);
            };

            int res = n;
            while (!is_valid(res, t)){
                ++res;
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