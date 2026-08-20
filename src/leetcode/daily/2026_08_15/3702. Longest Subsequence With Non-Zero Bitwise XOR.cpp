#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

/*
LC 3702 - Longest Subsequence With Non-Zero Bitwise XOR
https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/

Problem:
    You are given an integer array nums.
    Return the length of the longest subsequence in nums whose bitwise XOR is
    non-zero. If no such subsequence exists, return 0.

    Constraints:
        1 <= nums.length <= 10^5
        0 <= nums[i] <= 10^9

Examples:
    Input: nums = [1,2,3]
    Output: 2
    Explanation: One longest subsequence is [2, 3]. 2 XOR 3 = 1, which is non-zero.

    Input: nums = [2,3,4]
    Output: 3
    Explanation: The longest subsequence is [2, 3, 4]. 2 XOR 3 XOR 4 = 5, non-zero.

Best solution:
    Single pass over the whole-array XOR (greedy / bit trick), no DP needed.

Time & Space complexity:
    Time:  O(n) - one pass to accumulate the XOR of every element.
    Space: O(1) - only the running XOR and one boolean flag.

Approach (detail):
    1. Let X = nums[0] ^ nums[1] ^ ... ^ nums[n-1] be the XOR of the entire array.
    2. If X != 0, the whole array already qualifies, so the answer is n. No longer
       subsequence exists, so this is optimal.
    3. If X == 0, the full array fails, so the best we can hope for is n-1: drop
       exactly one element nums[i]. The XOR of the remaining n-1 elements is
       X ^ nums[i] = 0 ^ nums[i] = nums[i]. So dropping nums[i] succeeds exactly
       when nums[i] != 0.
    4. Therefore when X == 0: if any element is non-zero, answer is n-1; if every
       element is 0, every subsequence XORs to 0, so the answer is 0.
    5. Key insight: removing one element from a zero-XOR array leaves a XOR equal
       to the removed element, which turns the search into "does a non-zero
       element exist?".

Your solution:
    MATCHES BEST - the code accumulates the full XOR in one pass and returns
    n / n-1 / 0 by exactly the case split above (Time O(n), Space O(1)). The
    non_zero flag is only scanned from index 1, which is still correct: if X == 0
    and nums[0] != 0, then some other element must also be non-zero (a single
    non-zero element would make X != 0), so the flag never misses a valid drop.
*/

class Solution {
    public:
        int longestSubsequence(vector<int>& nums) {
            int n = nums.size();
            int xorn = nums[0];
            bool non_zero = false;
            for (int i = 1; i < n; ++i){
                xorn ^= nums[i];
                non_zero |= nums[i];
            }
            return (xorn) ? n : ((non_zero) ? n-1 : 0);
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