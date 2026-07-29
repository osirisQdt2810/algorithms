#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 1464 - Maximum Product of Two Elements in an Array
 *
 * Best solution: Single linear pass tracking the top two values, then return
 * (max1 - 1) * (max2 - 1). Optimal — every element must be read to know the two
 * largest, so O(n) is a lower bound, and this hits it with O(1) space and no
 * sorting.
 *
 * Time:  O(n) — one sweep, at most two comparisons per element.
 * Space: O(1) — two running scalars; the input is neither copied nor sorted.
 *
 * Approach (detail):
 *   1. We must choose two distinct indices i != j maximizing
 *      (nums[i] - 1) * (nums[j] - 1). Constraints give nums[i] >= 1, so every
 *      factor (nums[k] - 1) is >= 0 — all non-negative. That removes the
 *      two-negatives case entirely, so the maximum is simply attained by the
 *      two largest elements: x -> x - 1 is strictly increasing, and on
 *      non-negative factors a larger pair never gives a smaller product.
 *   2. Seed the pair from the first two elements without assuming order:
 *      max_num = max(nums[0], nums[1]), secmax_num = min(nums[0], nums[1]).
 *      This handles n == 2 correctly with no loop iterations at all.
 *   3. Sweep i = 2..n-1 with the cascading top-2 update:
 *      - nums[i] > max_num: demote the old champion (secmax_num = max_num)
 *        before installing the new one (max_num = nums[i]). The demotion step
 *        is what keeps the runner-up valid;
 *      - else if nums[i] > secmax_num: only the runner-up improves.
 *   4. Duplicates are handled by strict `>`: a value tying max_num falls to the
 *      second branch and becomes the runner-up, which is exactly right since
 *      the two picks only need distinct *indices*, not distinct *values*
 *      (e.g. [3, 3] → 2 * 2 = 4).
 *   5. Return (max_num - 1) * (secmax_num - 1). With nums[i] <= 10^3 the
 *      product stays well inside 32-bit range.
 */

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int max_num = max(nums[0], nums[1]);
            int secmax_num = min(nums[0], nums[1]);
            int n = nums.size();
            for (int i = 2; i < n; ++i){
                if (nums[i] > max_num){
                    secmax_num = max_num;
                    max_num = nums[i];
                }
                else if (nums[i] > secmax_num){
                    secmax_num = nums[i];
                }
            }
            return (max_num - 1) * (secmax_num - 1);
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