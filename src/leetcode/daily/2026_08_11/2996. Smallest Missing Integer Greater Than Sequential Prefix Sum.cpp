#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
    LC 2996 - Smallest Missing Integer Greater Than Sequential Prefix Sum
    https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

    Problem:
        You are given a 0-indexed array of integers nums.
        A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In
        particular, the prefix consisting only of nums[0] is sequential.
        Return the smallest integer x missing from nums such that x is greater than or equal to the
        sum of the longest sequential prefix.

        Constraints:
          - 1 <= nums.length <= 50
          - 1 <= nums[i] <= 50

    Examples:
        Example 1:
            Input: nums = [1,2,3,2,5]
            Output: 6
            Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not
            in the array, therefore 6 is the smallest missing integer greater than or equal to the
            sum of the longest sequential prefix.

        Example 2:
            Input: nums = [3,4,5,1,12,14,13]
            Output: 15
            Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13,
            and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing
            integer greater than or equal to the sum of the longest sequential prefix.

    Best solution:
        One linear scan for the longest sequential prefix and its sum, then a linear upward probe
        over a hash set of the array's values.

    Time & Space complexity:
        Time:  O(n)
               - one pass walks the sequential prefix; the upward probe advances only while the
                 candidate is present in nums, and nums holds at most n distinct values, so the
                 probe makes at most n + 1 steps.
        Space: O(n)
               - the hash set holding nums' values.

    Approach (detail):
        1. Insert every value of nums into a hash set `unique`, giving O(1) membership tests.
        2. Starting from sum = nums[0], walk i = 1, 2, ... while nums[i] == nums[i-1] + 1, adding
           nums[i] to sum. Stop at the first index that breaks the +1 chain.
        3. That sum is the sum S of the *longest* sequential prefix. There is nothing to maximise
           over: a sequential prefix must be anchored at index 0 and must be an unbroken +1 chain,
           so the longest one ends exactly where the chain first breaks - it is unique.
        4. Set x = S and advance x while x is in `unique`. The first x absent from the set is the
           answer: it satisfies x >= S by construction, and each candidate skipped along the way was
           skipped only because it appears in nums, so no smaller valid answer was passed over.
        5. Termination is guaranteed because nums contains at most n distinct values, so at most n
           consecutive integers can be skipped before an absent one is reached.

    Your solution:
        MATCHES BEST - the code builds the value set, finds the sequential-prefix sum in one pass,
        then probes upward from that sum, i.e. exactly the documented O(n) time / O(n) space
        algorithm. The `nums.push_back(-1)` before the scan is a sentinel trick: `unique` was already
        built from the original values so the appended -1 never pollutes membership tests, and since
        nums[i] >= 1 the sentinel can never extend a +1 chain - it only guarantees the loop breaks
        instead of reading past the end when the entire array is sequential. It does mutate the
        caller's vector, which is harmless here.
*/

class Solution {
    public:
        int missingInteger(vector<int>& nums) {
            unordered_set<int> unique(nums.begin(), nums.end());
            nums.push_back(-1);
            int n = nums.size();
            int sum = nums[0];
            for (int i = 1; i < n; ++i) {
                if (nums[i] != nums[i - 1] + 1) {
                    break;
                }
                sum += nums[i];
            }
            while (unique.count(sum)) {
                ++sum;
            }
            return sum;
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
