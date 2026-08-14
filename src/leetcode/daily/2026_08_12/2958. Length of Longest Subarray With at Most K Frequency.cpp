#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

/*
    LC 2958 - Length of Longest Subarray With at Most K Frequency
    https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

    Problem:
        You are given an integer array nums and an integer k.
        The frequency of an element x is the number of times it occurs in an array.
        An array is called good if the frequency of each element in this array is less than or equal
        to k.
        Return the length of the longest good subarray of nums.
        A subarray is a contiguous non-empty sequence of elements within an array.

        Constraints:
          - 1 <= nums.length <= 10^5
          - 1 <= nums[i] <= 10^9
          - 1 <= k <= nums.length

    Examples:
        Example 1:
            Input: nums = [1,2,3,1,2,3,1,2], k = 2
            Output: 6
            Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2,
            and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and
            [3,1,2,3,1,2] are also good. It can be shown that there are no good subarrays with
            length more than 6.

        Example 2:
            Input: nums = [1,2,1,2,1,2,1,2], k = 1
            Output: 2
            Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur
            at most once in this subarray. Note that the subarray [2,1] is also good. It can be
            shown that there are no good subarrays with length more than 2.

        Example 3:
            Input: nums = [5,5,5,5,5,5,5], k = 4
            Output: 4
            Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4
            times in this subarray. It can be shown that there are no good subarrays with length
            more than 4.

    Best solution:
        Sliding window (two pointers) with a hash-map frequency counter.

    Time & Space complexity:
        Time:  O(n)
               - each of the n right-end advances is O(1) amortised, and the left pointer only ever
                 moves forward, so together the two pointers perform at most 2n hash-map operations.
        Space: O(n)
               - the frequency map holds at most one entry per distinct value in the window.

    Approach (detail):
        1. Maintain a window [l, r] and a map freqs of value -> count inside it, keeping the
           invariant "every count in freqs is <= k" at the end of each iteration.
        2. Extend the window by one element: ++freqs[nums[r]].
        3. That single insertion can only have broken the invariant for nums[r] itself - no other
           count changed - so it suffices to shrink from the left while freqs[nums[r]] > k,
           decrementing freqs[nums[l]] and advancing l. The loop must terminate because eventually l
           passes an earlier occurrence of nums[r], dropping its count back to k.
        4. After the shrink the window is good, so record res = max(res, r - l + 1).
        5. Why this finds the optimum: the "good" property is monotone under taking subarrays - any
           subarray of a good array is good - so for each right end r there is a smallest feasible
           left end, and it is non-decreasing in r. The two-pointer sweep visits exactly that
           smallest l for every r, hence it considers the longest good subarray ending at each
           position, and the maximum over all r is the global answer.

    Your solution:
        MATCHES BEST - the code runs the documented O(n) time / O(n) space sliding window: it grows
        the window at r, shrinks from l only while the freshly incremented count freqs[nums[r]]
        exceeds k, and takes the running maximum of the window length.
*/

class Solution {
    public:
        int maxSubarrayLength(vector<int>& nums, int k) {
            unordered_map<int, int> freqs;
            int res = 0, n = nums.size();
            for (int l = 0, r = 0; r < n; ++r) {
                freqs[nums[r]]++;
                while (freqs[nums[r]] > k) {
                    --freqs[nums[l]];
                    ++l;
                }
                res = max(res, r - l + 1);
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
