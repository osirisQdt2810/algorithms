#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 1979 - Find Greatest Common Divisor of Array
 *
 * Best solution: One linear scan to capture min and max, then a single
 * Euclidean gcd. This is optimal — every element must be inspected to know
 * which is smallest and which is largest, so O(n) is a lower bound, and the
 * gcd itself is only logarithmic.
 *
 * Time:  O(n + log(min)) — n comparisons for the min/max scan; Euclid on
 *        (min, max) terminates in O(log(min)) steps because each modulo step
 *        at least halves the smaller operand (Fibonacci worst case).
 * Space: O(1) — only two running scalars plus the swap temp; nothing is
 *        allocated proportional to n.
 *
 * Approach (detail):
 *   1. The problem does NOT ask for the gcd of the whole array — only
 *      gcd(smallest element, largest element). So no fold over all n values is
 *      needed; two extremes suffice.
 *   2. Seed min_ele = max_ele = nums[0], then sweep i = 1..n-1 updating each
 *      extreme with a plain comparison. One pass, no sort — sorting would cost
 *      an unnecessary O(n log n).
 *   3. Run the iterative Euclidean algorithm on the pair: repeatedly replace
 *      (a, b) with (b, a mod b) until the divisor hits 0. Here the loop keeps
 *      min_ele as the divisor: tmp = min_ele; min_ele = max_ele % tmp;
 *      max_ele = tmp. When min_ele becomes 0, max_ele holds the gcd.
 *   4. Why correct: gcd(a, b) = gcd(b, a mod b) since any common divisor of
 *      a and b also divides a - qb, and vice versa — the divisor set is
 *      invariant across steps, so the last nonzero remainder is the gcd. Note
 *      the loop is direction-agnostic: even if the first modulo is taken with
 *      the larger operand on the right, the pair self-orders after one step.
 *   5. Constraints guarantee n >= 2 and nums[i] >= 1, so min_ele is never 0
 *      at entry and the result is always a valid positive divisor.
 */

class Solution {
    public:
        int findGCD(vector<int>& nums) {
            int min_ele = nums[0], max_ele = nums[0];
            for (int i = 1; i < nums.size(); ++i){
                if (nums[i] < min_ele) min_ele = nums[i];
                if (nums[i] > max_ele) max_ele = nums[i];
            }
            while (min_ele){
                int tmp = min_ele;
                min_ele = max_ele % tmp;
                max_ele = tmp;
            }
            return max_ele;
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