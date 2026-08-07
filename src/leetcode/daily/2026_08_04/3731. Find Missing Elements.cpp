#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3731 - Find Missing Elements
 * https://leetcode.com/problems/find-missing-elements/
 *
 * Problem:
 *   You are given an integer array nums consisting of unique integers.
 *
 *   Originally, nums contained every integer within a certain range. However,
 *   some integers might have gone missing from the array.
 *
 *   The smallest and largest integers of the original range are still present in
 *   nums.
 *
 *   Return a sorted list of all the missing integers in this range. If no
 *   integers are missing, return an empty list.
 *
 *   Constraints:
 *     - 2 <= nums.length <= 100
 *     - 1 <= nums[i] <= 100
 *
 * Examples:
 *   Example 1:
 *     Input:  nums = [1,4,2,5]
 *     Output: [3]
 *     Explanation: The smallest integer is 1 and the largest is 5, so the full
 *       range should be [1,2,3,4,5]. Among these, only 3 is missing.
 *
 *   Example 2:
 *     Input:  nums = [7,8,6,9]
 *     Output: []
 *     Explanation: The smallest integer is 6 and the largest is 9, so the full
 *       range is [6,7,8,9]. All integers are already present, so no integer is
 *       missing.
 *
 *   Example 3:
 *     Input:  nums = [5,1]
 *     Output: [2,3,4]
 *     Explanation: The smallest integer is 1 and the largest is 5, so the full
 *       range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.
 *
 * Best solution: Min/max scan + a presence bitmap over the range, then a single
 * ascending sweep. Optimal — the output is required in sorted order and the
 * sweep produces it directly, with no comparison sort needed.
 *
 * Time:  O(n + R) where R = max - min + 1 is the range width — two passes over
 *        nums plus one pass over the range. Bounded by O(100) here.
 * Space: O(R) for the presence array, excluding the output.
 *
 * Approach (detail):
 *   1. The "original range" is fully pinned down by the guarantee that its
 *      endpoints survive: since the smallest and largest of the original range
 *      are still in nums, the range is exactly [min(nums), max(nums)]. No other
 *      inference is needed — this is the whole reason the problem is
 *      well-defined.
 *   2. First pass: compute min_ele and max_ele over nums, seeding both with
 *      nums[0] (safe because the constraints guarantee nums.length >= 2, so the
 *      array is never empty).
 *   3. Allocate a boolean array `existed` of length max_ele - min_ele + 1,
 *      indexed by value - min_ele. Offsetting by min_ele keeps the array exactly
 *      as wide as the range rather than as wide as the value domain — the
 *      standard trick when values are dense within a window but the window may
 *      start far from 0.
 *   4. Second pass: mark existed[num - min_ele] = true for each num. The
 *      uniqueness guarantee means no slot is ever set twice, though the
 *      algorithm would be correct even with duplicates.
 *   5. Sweep values v ascending from min_ele to max_ele and append v to the
 *      result whenever existed[v - min_ele] is false. Because the sweep runs in
 *      increasing order, the result is sorted by construction.
 *   6. The endpoints are always present by hypothesis, so they are never
 *      emitted; if nothing is missing the result is naturally empty.
 */

class Solution {
    public:
        vector<int> findMissingElements(vector<int>& nums) {
            int min_ele = nums[0], max_ele = nums[0];
            for (auto num : nums){
                min_ele = min(min_ele, num);
                max_ele = max(max_ele, num);
            }
            vector<bool> existed(max_ele - min_ele + 1, false);
            for (auto num : nums){
                existed[num - min_ele] = true;
            }

            vector<int> res;
            for (int i = min_ele; i <= max_ele; ++i){
                if (existed[i - min_ele]) continue;
                res.push_back(i);
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