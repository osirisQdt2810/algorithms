#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/*
LC 3471 - Find the Largest Almost Missing Integer
https://leetcode.com/problems/find-the-largest-almost-missing-integer/

Problem:
    You are given an integer array nums and an integer k.
    An integer x is almost missing from nums if x appears in exactly one subarray
    of size k within nums. Return the largest almost missing integer from nums.
    If no such integer exists, return -1.
    (A subarray is a contiguous sequence of elements within an array.)

    Constraints:
        1 <= nums.length <= 50
        0 <= nums[i] <= 50
        1 <= k <= nums.length

Examples:
    Input: nums = [3,9,2,1,7], k = 3
    Output: 7
    Explanation: 1 appears in 2 subarrays of size 3; 2 in 3; 3 in 1; 7 in 1;
    9 in 2. We return 7, the largest value appearing in exactly one subarray.

    Input: nums = [3,9,7,2,1,7], k = 4
    Output: 3
    Explanation: only 3 appears in exactly one subarray of size 4 ([3,9,7,2]).

    Input: nums = [0,0], k = 1
    Output: -1
    Explanation: no integer appears in only one subarray of size 1.

Best solution:
    Frequency counting plus a positional case split on k (O(n) counting), rather
    than enumerating all O(n*k) windows.

Time & Space complexity:
    Time:  O(n) - one pass to build the frequency map, one pass to scan it.
    Space: O(n) - the frequency map holds at most n distinct values.

Approach (detail):
    1. Index i is covered by the windows starting at max(0, i-k+1) .. min(i, n-k),
       so the number of size-k subarrays containing position i is
       min(i, n-k) - max(0, i-k+1) + 1.
    2. Case k == n: there is only one window, which contains every position, so
       every value present appears in exactly one subarray. Answer = max(nums).
    3. Case k == 1: each window is a single element, so a value appears in exactly
       one window iff it occurs exactly once in nums. Answer = the largest value
       with frequency 1.
    4. Case 1 < k < n: position 0 is covered only by the window starting at 0, and
       position n-1 only by the window starting at n-k; every interior position is
       covered by at least two windows. So a value is almost missing iff it sits at
       index 0 or index n-1 AND occurs exactly once in the whole array (a second
       occurrence would add more covering windows).
    5. Answer is the max over the surviving candidates, or -1 when none exist.

Your solution:
    MATCHES BEST - the code builds a frequency map once and applies exactly the
    three-case split above (k >= n -> max element; k > 1 -> only nums[0] and
    nums[n-1] with frequency 1; k == 1 -> largest value with frequency 1), running
    in O(n) time and O(n) space, and returns -1 when no candidate qualifies.
*/

class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) {
            int n = nums.size();
            if (k >= n) return *std::max_element(nums.begin(), nums.end());
            unordered_map<int, int> freq;
            for (auto& num : nums) freq[num]++;
            int res = -1;
            if (k > 1){
                if (freq[nums[0]] == 1) res = max(res, nums[0]);
                if (freq[nums[n-1]] == 1) res = max(res, nums[n-1]);
                return res;
            }
            for (auto& [num, f] : freq){
                if (f == 1) res = max(res, num);
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