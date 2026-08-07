#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 628 - Maximum Product of Three Numbers
 *
 * Best solution: One linear pass tracking the three largest and the two
 * smallest values, then take max(max1*max2*max3, min1*min2*max1). This beats
 * the sort-based variant: it needs no ordering of the full array, only five
 * running extremes, so it is O(n) time / O(1) space and is optimal (every
 * element must be read).
 *
 * Time:  O(n) — a single sweep with a constant number of comparisons per
 *        element. (The sort-based formulation is O(n log n), asymptotically
 *        worse though it computes the same answer.)
 * Space: O(1) — five scalars, and the input is not mutated.
 *
 * Approach (detail):
 *   1. Key insight: with exactly three factors, only two candidate shapes can
 *      ever be optimal, because the sign pattern of a triple product is fully
 *      determined by how many negative factors it uses:
 *      a. the three largest values (max1*max2*max3) — wins when the array is
 *         all non-negative, or when using zero negatives is best;
 *      b. the two most negative values times the single largest value
 *         (min1*min2*max1) — two negatives multiply to a large positive, so
 *         this wins when the array holds large-magnitude negatives, e.g.
 *         [-100, -98, 1, 2, 3] → (-100)*(-98)*3 = 29400 > 1*2*3.
 *      Any triple using exactly one or exactly three negatives yields a
 *      product no better than one of these two (flipping a negative factor for
 *      a larger one never hurts), so no other combination needs checking.
 *   2. Maintain max1 >= max2 >= max3 and min1 <= min2 with the standard
 *      cascading update: on each element, compare against max1 first and shift
 *      the chain down (max3 = max2, max2 = max1, max1 = x), else against
 *      max2, else max3; symmetrically for the two minima. Seed the maxima to
 *      INT_MIN and the minima to INT_MAX so the first elements populate them.
 *   3. Return the larger of the two candidate products. Constraints (n >= 3,
 *      |nums[i]| <= 1000) keep the product within 32-bit range, so no widening
 *      to long long is required.
 *
 * Note: the code below implements the equivalent sort-then-index version —
 * sort ascending, then compare nums[n-3]*nums[n-2]*nums[n-1] against
 * nums[0]*nums[1]*nums[n-1]. Same two candidates, same answer, but O(n log n).
 */

class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
            // a * b * c lớn nhất
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int max_prod = nums[n-3] * nums[n-2] * nums[n-1];
            max_prod = max(max_prod, nums[0] * nums[1]  * nums[n-1]);
            return max_prod;
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