#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/*
LC 2091 - Removing Minimum and Maximum From Array
https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

Problem:
    You are given a 0-indexed array of distinct integers nums. There is an element
    in nums that has the lowest value and an element that has the highest value.
    We call them the minimum and the maximum respectively. Your goal is to remove
    both these elements from the array.

    A deletion is defined as either removing an element from the front of the
    array or removing an element from the back of the array.

    Return the minimum number of deletions it would take to remove both the
    minimum and maximum element from the array.

    Constraints:
        1 <= nums.length <= 10^5
        -10^5 <= nums[i] <= 10^5
        The integers in nums are distinct.

Examples:
    Input: nums = [2,10,7,5,4,1,8,6]
    Output: 5
    Explanation: The minimum element is nums[5] = 1 and the maximum is
    nums[1] = 10. Removing 2 elements from the front and 3 from the back removes
    both, for 2 + 3 = 5 deletions, which is the minimum possible.

    Input: nums = [0,-4,19,1,8,-2,-3,5]
    Output: 3
    Explanation: The minimum is nums[1] = -4 and the maximum is nums[2] = 19.
    Removing 3 elements from the front removes both, for only 3 deletions.

    Input: nums = [101]
    Output: 1
    Explanation: The single element is both the minimum and the maximum, so one
    deletion suffices.

Best solution:
    One linear pass to locate the two extreme indices, then take the minimum of
    the only three removal shapes that can cover both of them.

Time & Space complexity:
    Time:  O(n) - a single scan finds both extreme indices, and the answer is then
           a constant-size minimum over three candidates.
    Space: O(1) - only the two indices and their values are kept.

Approach (detail):
    1. The values themselves are irrelevant beyond locating them: every deletion
       peels one element off the front or the back, so the surviving elements are
       always a contiguous middle segment. What decides the cost is purely where
       the minimum and the maximum sit.
    2. Scan once, recording min_idx and max_idx. Normalise them into a = the
       smaller index and b = the larger index, so a <= b and both extremes are
       covered exactly when the prefix reaches a or the suffix reaches a, and
       likewise for b.
    3. Any deletion plan is "remove a prefix of length p and a suffix of length q".
       To cover both a and b, exactly one of three shapes is optimal:
         - front only: delete through index b, costing b + 1;
         - back only: delete back through index a, costing n - a;
         - split: delete the front through a and the back through b, costing
           (a + 1) + (n - b).
       Any other (p, q) that still covers both is dominated by one of these three,
       because enlarging p past b or q past n-1-a only wastes deletions.
    4. Return the minimum of the three candidates. The single-element case falls
       out for free: a = b = 0 gives min(1, 1, 2) = 1.

Your solution:
    MATCHES BEST - the committed code runs exactly this algorithm: one pass to get
    min_idx/max_idx, then min(b+1, a+1+(n-b), n-a), at O(n) time and O(1) space.
*/

class Solution {
    public:
        int minimumDeletions(vector<int>& nums) {
            int min_idx = 0, max_idx = 0;
            int min_ele = nums[0], max_ele = nums[0];
            int n = nums.size();
            for (int i = 1; i < n; ++i){
                if (nums[i] < min_ele){
                    min_idx = i;
                    min_ele = nums[i];
                }
                if (nums[i] > max_ele){
                    max_idx = i;
                    max_ele = nums[i];
                }
            }
            int a = min(min_idx, max_idx);
            int b = max(min_idx, max_idx);
            int res = min(b+1, a+1+(n-b));
            return min(res, n-a);
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