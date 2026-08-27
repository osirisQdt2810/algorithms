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
LC 3718 - Smallest Missing Multiple of K
https://leetcode.com/problems/smallest-missing-multiple-of-k/

Problem:
    Given an integer array nums and an integer k, return the smallest positive
    multiple of k that is missing from nums. A multiple of k is any positive
    integer divisible by k.

    Constraints:
        1 <= nums.length <= 100
        1 <= nums[i] <= 100
        1 <= k <= 100

Examples:
    Input: nums = [8,2,3,4,6], k = 2
    Output: 10
    Explanation: The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the
    smallest multiple missing from nums is 10.

    Input: nums = [1,4,7,10,15], k = 5
    Output: 5
    Explanation: The multiples of k = 5 are 5, 10, 15, 20... and the smallest
    multiple missing from nums is 5.

Best solution:
    Hash the values of nums into a set, then walk the multiples of k in increasing
    order (k, 2k, 3k, ...) and return the first one absent from the set.

Time & Space complexity:
    Time:  O(n) - building the set is O(n), and the scan of multiples stops after
           at most n + 1 steps (see step 3), so both phases are linear in n.
    Space: O(n) - the hash set holds at most n distinct values of nums.

Approach (detail):
    1. The answer is the smallest element of the infinite increasing sequence
       k, 2k, 3k, ... that does not appear in nums. Because that sequence is
       already sorted, the first miss found while walking it upward is the answer;
       no sorting of nums and no search over candidate answers is needed.
    2. Membership must be tested many times, so pre-load nums into an
       unordered_set for O(1) average lookups. Duplicates in nums collapse
       naturally, which is fine - only presence matters, not multiplicity.
    3. Termination bound (why the loop is not unbounded): nums holds at most n
       distinct values, so it can cover at most n of the multiples k, 2k, ...
       Hence among the first n + 1 multiples at least one is missing, and the loop
       exits within n + 1 iterations. With n <= 100 and k <= 100 the returned
       value is at most 101 * 100, so plain int arithmetic cannot overflow.
    4. Return i * k for the first i >= 1 whose multiple is not in the set. Note
       the multiple must be *positive*, so the walk starts at i = 1, never i = 0.

Your solution:
    MATCHES BEST - the committed code builds the unordered_set from nums and scans
    i = 1, 2, 3, ... returning the first i * k not present, i.e. exactly the
    documented algorithm at O(n) time and O(n) space. The trailing return -1 after
    the while (true) is unreachable dead code (by the bound in step 3) and only
    silences a missing-return warning; it does not affect behaviour.
*/

class Solution {
    public:
        int missingMultiple(vector<int>& nums, int k) {
            unordered_set<int> uniques(nums.begin(), nums.end());
            int i = 1;
            while (true){
                int mul = i * k;
                if (!uniques.count(mul)){
                    return mul;
                }
                ++i;
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