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
LC 3876 - Construct Uniform Parity Array II
https://leetcode.com/problems/construct-uniform-parity-array-ii/

Problem:
    You are given an array nums1 of n distinct integers.

    You want to construct another array nums2 of length n such that the elements
    in nums2 are either all odd or all even.

    For each index i, you must choose exactly one of the following (in any order):
        nums2[i] = nums1[i]
        nums2[i] = nums1[i] - nums1[j], for an index j != i, such that
                   nums1[i] - nums1[j] >= 1

    Return true if it is possible to construct such an array, otherwise return
    false.

    Constraints:
        1 <= n == nums1.length <= 10^5
        1 <= nums1[i] <= 10^9
        nums1 consists of distinct integers.

Examples:
    Input: nums1 = [1,4,7]
    Output: true
    Explanation: Set nums2[0] = nums1[0] = 1, nums2[1] = nums1[1] - nums1[0] = 3
    and nums2[2] = nums1[2] = 7. nums2 = [1, 3, 7], and all elements are odd.

    Input: nums1 = [2,3]
    Output: false
    Explanation: It is not possible to construct nums2 such that all elements have
    the same parity.

    Input: nums1 = [4,6]
    Output: true
    Explanation: Set nums2[0] = nums1[0] = 4 and nums2[1] = nums1[1] = 6.
    nums2 = [4, 6], and all elements are even.

Best solution:
    A single pass computing the minimum and an "is there any odd element" flag: the
    answer is (minimum is odd) OR (every element is even).

Time & Space complexity:
    Time:  O(n) - one scan of the array; no sorting is required.
    Space: O(1) - two scalars, and the input is left untouched.

Approach (detail):
    1. The added condition nums1[i] - nums1[j] >= 1 means, since the values are
       distinct, exactly that nums1[j] < nums1[i]. So index i may only subtract an
       element of strictly smaller value - the donor relation is now a strict order
       rather than "anything else", which is the whole difference from LC 3875.
    2. Consequently the minimum element has no legal donor and must keep itself.
       Its parity therefore *dictates* the target parity of the whole array: nums2
       is uniform of that parity or not uniform at all.
    3. Suppose the minimum is odd, so the target is all-odd. Every odd element
       keeps itself. Every even element may subtract the minimum, which is odd and
       strictly smaller than it, producing an odd value. So a valid construction
       always exists: minimum odd => true.
    4. Suppose the minimum is even, so the target is all-even. Even elements keep
       themselves and are fine. An odd element i must reach even parity, which
       needs a donor of odd parity strictly smaller than it. Look at the *smallest*
       odd element: no odd value lies below it, so it has no legal donor and the
       construction fails. Hence with an even minimum the answer is true only when
       the array contains no odd element at all.
    5. Combining: true iff the minimum is odd, or all elements are even. (Verified
       against brute force on all small arrays.)
    6. n = 1 falls out of the same rule: the single element is the minimum and is
       kept, so the result is trivially uniform - and indeed either it is odd
       (minimum odd) or the array is entirely even.
    7. Sorting is a natural way to reach this insight - it makes "only earlier
       positions may donate" explicit - but the final rule only ever consults the
       minimum, so the sort is not needed in the finished solution.

Your solution:
    SUBOPTIMAL - the committed code is correct but sorts first, running in
    O(n log n) time and O(1) extra space versus the O(n) / O(1) single-pass scan
    above, a log-factor gap. After sorting it sets must_odd from the parity of
    nums1[0] (the minimum), which is precisely step 2, and then returns false at
    the first odd element whenever the minimum is even (step 4) and true otherwise
    (step 3) - so the decision it computes is exactly the documented rule. It
    passes comfortably: at n <= 10^5 the sort is negligible. Two minor notes: it
    reorders the caller's array in place, and its has_even flag is written but
    never read.
*/

class Solution {
    public:
        bool uniformArray(vector<int>& nums1) {
            sort(nums1.begin(), nums1.end());
            int n = nums1.size();
            if (n == 1) return true;
            bool has_odd = (nums1[0] % 2), has_even = !has_odd;
            bool must_odd = (nums1[0] % 2);
            for (int i = 1; i < n; ++i){
                if (nums1[i] % 2){  // odd
                    if (must_odd){
                        has_odd = true;
                        continue;
                    };
                    // must be even => need j < i: nums[i]-nums[j] even <=> nums[j] odd
                    if (!has_odd) return false;
                }
                else {  // even
                    has_even = true;
                    if (!must_odd) continue;
                    // must be odd => need j < i: nums[i]-nums[j] odd <=> nums[j] odd
                    if (!has_odd) return false;
                }
            }
            return true;
        }
};

int main(){
    Solution sol;

    return 0;
}