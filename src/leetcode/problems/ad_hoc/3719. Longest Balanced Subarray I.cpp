#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
    LC 3719 - Longest Balanced Subarray I
    https://leetcode.com/problems/longest-balanced-subarray-i/

    Problem:
        You are given an integer array nums.
        A subarray is called balanced if the number of distinct even numbers in the subarray is equal
        to the number of distinct odd numbers.
        Return the length of the longest balanced subarray.

        Constraints:
          - 1 <= nums.length <= 1500
          - 1 <= nums[i] <= 10^5

    Examples:
        Example 1:
            Input: nums = [2,5,4,3]
            Output: 4
            Explanation:
            - The longest balanced subarray is [2, 5, 4, 3].
            - It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the
              answer is 4.

        Example 2:
            Input: nums = [3,2,2,5,4]
            Output: 5
            Explanation:
            - The longest balanced subarray is [3, 2, 2, 5, 4].
            - It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the
              answer is 5.

        Example 3:
            Input: nums = [1,2,3,2]
            Output: 3
            Explanation:
            - The longest balanced subarray is [2, 3, 2].
            - It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.

    Best solution:
        Fix the left end and sweep the right end, maintaining the two distinct-value counts
        incrementally - O(n^2) over all pairs, which is what the n <= 1500 bound is sized for.

    Time & Space complexity:
        Time:  O(n^2)
               - n choices of left end, and for each one the right end advances n times doing O(1)
                 work per step; ~1500^2 / 2 ≈ 1.1M steps at the constraint limit.
        Space: O(n)
               - the two membership structures hold at most n values between them; they are reset
                 once per left end.

    Approach (detail):
        1. The balance condition counts *distinct* values, not occurrences, so it is not a prefix-sum
           quantity: adding an element changes a count only when that value is new to the window. A
           plain "difference of prefix counts" trick therefore does not apply, and enumerating windows
           is the natural approach.
        2. Enumerate the left end l from 0 to n-1. For each l, clear two sets - `odd` for distinct odd
           values seen and `even` for distinct even ones.
        3. Extend the right end r from l upward. Insert nums[r] into `odd` if it is odd, otherwise
           into `even`. Because these are sets, the size grows only on a genuinely new value, so
           odd.size() and even.size() are exactly the distinct counts of the window [l, r] at all
           times - each step is O(1) and no recomputation over the window is needed.
        4. Whenever odd.size() == even.size(), the window [l, r] is balanced; record its length
           r - l + 1 against the running maximum.
        5. This is exhaustive over all O(n^2) subarrays, so the maximum it records is the true answer.
           Note the empty-count case is handled for free: a window with zero distinct odds and zero
           distinct evens cannot occur for a non-empty window, since every element is odd or even.
        6. Constant-factor refinement (same complexity): replace the hash sets with a single int array
           indexed by value plus a "last seen l" stamp, or with two counters updated via a
           last-occurrence check, avoiding hashing and the per-l clear.

    Your solution:
        MATCHES BEST - the code is exactly the documented O(n^2) time / O(n) space enumeration: outer
        loop over l with two fresh unordered_sets, inner loop extending r while inserting nums[r] into
        the odd or even set by parity, and taking the running maximum whenever the two sizes match.
        That is the intended complexity for this version's n <= 1500 bound (the harder variant of this
        problem is where a sub-quadratic method would be required).
*/

class Solution {
    public:
        int longestBalanced(vector<int>& nums) {
            int n = nums.size();
            int res = 0;
            for (int l = 0; l < n; ++l) {
                unordered_set<int> odd, even;
                for (int r = l; r < n; ++r) {
                    (nums[r] % 2) ? odd.insert(nums[r]) : even.insert(nums[r]);
                    if (odd.size() == even.size()) res = max(res, r - l + 1);
                }
            }
            return res;
        }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main() {
    Solution sol;
    return 0;
}
