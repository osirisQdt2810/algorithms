#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

/*
LC 3069 - Distribute Elements Into Two Arrays I
https://leetcode.com/problems/distribute-elements-into-two-arrays-i/

Problem:
    You are given a 1-indexed array of distinct integers nums of length n.
    You need to distribute all the elements of nums between two arrays arr1 and
    arr2 using n operations. In the first operation, append nums[1] to arr1. In
    the second operation, append nums[2] to arr2. Afterwards, in the i-th
    operation:
        If the last element of arr1 is greater than the last element of arr2,
        append nums[i] to arr1. Otherwise, append nums[i] to arr2.
    The array result is formed by concatenating arr1 and arr2. Return result.

    Constraints:
        3 <= n <= 50
        1 <= nums[i] <= 100
        All elements in nums are distinct.

Examples:
    Input: nums = [2,1,3]
    Output: [2,3,1]
    Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1]. In the
    3rd operation, the last element of arr1 is greater than that of arr2 (2 > 1),
    so nums[3] goes to arr1. arr1 = [2,3], arr2 = [1], result = [2,3,1].

    Input: nums = [5,4,3,8]
    Output: [5,3,4,8]
    Explanation: arr1 = [5], arr2 = [4]. 3rd operation: 5 > 4, so arr1 = [5,3].
    4th operation: 4 > 3, so arr2 = [4,8]. result = [5,3,4,8].

Best solution:
    Direct simulation of the stated process - the rule only inspects the two
    current tails, so no lookahead, sorting, or search structure buys anything.

Time & Space complexity:
    Time:  O(n) - one append decision per element, each O(1) amortised.
    Space: O(n) - the two buckets together hold all n elements.

Approach (detail):
    1. The process is fully deterministic and depends on nothing but the current
       tails of arr1 and arr2, so the answer is uniquely determined; there is no
       choice to optimise over and simulation is exact.
    2. Seed the two buckets: arr1 gets nums[0], arr2 gets nums[1] (0-indexed,
       matching the problem's 1-indexed nums[1] and nums[2]). n >= 3 guarantees
       both seeds exist.
    3. For i from 2 to n-1, compare arr1.back() with arr2.back() and append
       nums[i] to arr1 when arr1.back() > arr2.back(), otherwise to arr2. Both
       buckets are non-empty from step 2 on, so back() is always valid.
    4. Elements are distinct, so the comparison never ties and the "otherwise"
       branch is only reached when arr2.back() is strictly greater.
    5. Concatenate arr1 then arr2 to build result.
    6. Lower bound: every element must be read and placed, so O(n) is optimal.

Your solution:
    MATCHES BEST - the code is exactly this simulation: seed arr1/arr2 with the
    first two elements, drive the tail comparison from i = 2, then write arr1
    followed by arr2 back into nums and return it. Time O(n), Space O(n).
    Overwriting nums in place is safe because every value has already been copied
    into arr1 or arr2 before the write-back begins.
*/

class Solution {
    public:
        vector<int> resultArray(vector<int>& nums) {
            vector<int> arr1, arr2;
            int n = nums.size();
            arr1.push_back(nums[0]);
            arr2.push_back(nums[1]);
            for (int i = 2; i < n; ++i){
                if (arr1.back() > arr2.back()){
                    arr1.push_back(nums[i]);
                }
                else {
                    arr2.push_back(nums[i]);
                }
            }
            for (int i = 0; i < arr1.size(); ++i){
                nums[i] = arr1[i];
            }
            for (int i = 0; i < arr2.size(); ++i){
                nums[i+arr1.size()] = arr2[i];
            }
            return nums;
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