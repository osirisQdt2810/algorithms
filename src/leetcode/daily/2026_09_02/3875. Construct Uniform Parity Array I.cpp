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
LC 3875 - Construct Uniform Parity Array I
https://leetcode.com/problems/construct-uniform-parity-array-i/

Problem:
    You are given an array nums1 of n distinct integers.

    You want to construct another array nums2 of length n such that the elements
    in nums2 are either all odd or all even.

    For each index i, you must choose exactly one of the following (in any order):
        nums2[i] = nums1[i]
        nums2[i] = nums1[i] - nums1[j], for an index j != i

    Return true if it is possible to construct such an array, otherwise return
    false.

    Constraints:
        1 <= n == nums1.length <= 100
        1 <= nums1[i] <= 100
        nums1 consists of distinct integers.

Examples:
    Input: nums1 = [2,3]
    Output: true
    Explanation: Choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1 and
    nums2[1] = nums1[1] = 3. nums2 = [-1, 3], and both elements are odd.

    Input: nums1 = [4,6]
    Output: true
    Explanation: Choose nums2[0] = nums1[0] = 4 and nums2[1] = nums1[1] = 6.
    nums2 = [4, 6], and all elements are even.

Best solution:
    Parity case analysis, which collapses to a constant: the answer is
    unconditionally true, so return true without inspecting the array.

Time & Space complexity:
    Time:  O(1) - the answer does not depend on the input at all.
    Space: O(1) - nothing is stored.

Approach (detail):
    1. Only parities matter. Write p_i = nums1[i] & 1. Then nums1[i] - nums1[j] has
       parity p_i XOR p_j, so each index i can realise parity p_i (keep itself) or
       p_i XOR p_j for any j != i.
    2. The choices at different indices are independent, and nothing forbids two
       indices from subtracting the *same* j. That is the crucial freedom: one
       suitable donor j serves every index at once.
    3. Aim for all-odd. An odd element keeps itself and is already odd. An even
       element i needs some odd j; since i is even and j is odd, j != i holds
       automatically, so any odd element in the array works as the donor.
       Therefore all-odd is achievable whenever at least one odd element exists.
    4. Aim for all-even in the remaining case. If the array contains no odd element
       at all, then every element is even and keeping all of them already gives a
       uniformly even nums2.
    5. Cases 3 and 4 are exhaustive - either the array has at least one odd element
       or it has none - so a valid nums2 always exists and the answer is always
       true. (Verified by brute force over all small arrays.)
    6. n = 1 is consistent: the lone element has no j to pair with, but keeping it
       yields a one-element array, which is trivially uniform in its own parity.
    7. Contrast with the sequel LC 3876, which additionally demands
       nums1[i] - nums1[j] >= 1. That restriction forces j to be strictly smaller,
       stranding the minimum with no donor, and the answer stops being constant.

Your solution:
    MATCHES BEST - the committed code returns true unconditionally, which is
    exactly the documented optimal solution, at O(1) time and O(1) space.
*/

class Solution {
    public:
        bool uniformArray(vector<int>& nums1) {
            return true;
        }
};

int main(){
    Solution sol;

    return 0;
}