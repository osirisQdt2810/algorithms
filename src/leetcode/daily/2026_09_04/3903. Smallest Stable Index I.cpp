#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

/*
LC 3903 - Smallest Stable Index I
https://leetcode.com/problems/smallest-stable-index-i/

Problem:
    You are given an integer array nums of length n and an integer k.

    For each index i, define its instability score as
    max(nums[0..i]) - min(nums[i..n-1]), where max(nums[0..i]) is the largest
    value among the elements from index 0 to index i, and min(nums[i..n-1]) is the
    smallest value among the elements from index i to index n-1.

    An index i is called stable if its instability score is less than or equal to
    k. Return the smallest stable index. If no such index exists, return -1.

    Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 10^9
        0 <= k <= 10^9

Examples:
    Input: nums = [5,0,1,4], k = 3
    Output: 3
    Explanation: The instability scores are 5-0 = 5 at index 0, 5-0 = 5 at index 1,
    5-1 = 4 at index 2 and 5-4 = 1 at index 3. Index 3 is the first with a score
    at most k = 3.

    Input: nums = [3,2,1], k = 1
    Output: -1
    Explanation: Every index has instability score 3 - 1 = 2, which exceeds k = 1.

    Input: nums = [0], k = 0
    Output: 0
    Explanation: At index 0 the score is 0 - 0 = 0 <= k = 0.

Best solution:
    Precompute the prefix maxima and the suffix minima in two linear sweeps, then
    scan left to right for the first index whose difference is at most k.

Time & Space complexity:
    Time:  O(n) - three independent linear passes, each doing O(1) work per index.
    Space: O(n) - the two auxiliary arrays of prefix maxima and suffix minima.

Approach (detail):
    1. The score at index i couples a quantity that only looks left with one that
       only looks right, so neither can be maintained by a single sweep alone.
       Compute them separately and join them afterwards.
    2. Forward sweep: max_ele[i] = max(max_ele[i-1], nums[i]) with
       max_ele[0] = nums[0]. This is exactly max(nums[0..i]) by induction, since
       the maximum of a prefix is either the previous prefix maximum or the new
       element.
    3. Backward sweep: min_ele[i] = min(min_ele[i+1], nums[i]) with
       min_ele[n-1] = nums[n-1], giving min(nums[i..n-1]) by the mirror argument.
    4. Scan i from 0 upward and return the first i with
       max_ele[i] - min_ele[i] <= k. Scanning upward is what makes the answer the
       *smallest* stable index; the score is not monotone in i (both terms are
       non-decreasing, so their difference can move either way), which is why a
       binary search is not available and a left-to-right scan is required.
    5. If the scan finishes without a hit, no stable index exists, so return -1.
    6. Note that i is included in both halves, so max_ele[i] >= nums[i] >=
       min_ele[i] and the score is never negative.

Your solution:
    MATCHES BEST - the committed code builds the prefix-maximum and suffix-minimum
    arrays in two sweeps and returns the first index whose difference is at most k,
    at O(n) time and O(n) space.
*/

class Solution {
    public:
        int firstStableIndex(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> max_ele(n, INT_MIN);
            vector<int> min_ele(n, INT_MAX);
            for (int i = 0; i < n; ++i){
                max_ele[i] = (i > 0) ? max(max_ele[i-1], nums[i]) : nums[i];
            }

            for (int i = n-1; i >= 0; --i){
                min_ele[i] = (i < n-1) ? min(min_ele[i+1], nums[i]) : nums[i];
            }

            for (int i = 0; i < n; ++i){
                int instability = max_ele[i] - min_ele[i];
                if (instability <= k) return i;
            }
            return -1;
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