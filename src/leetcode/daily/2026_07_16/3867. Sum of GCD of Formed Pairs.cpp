#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3867 - Sum of GCD of Formed Pairs
 *
 * Best solution: Prefix-GCD transform + sort + two-pointer pairing (direct
 * simulation of the mandated construction). This is optimal — every element
 * must be read, and the sort is the dominant cost.
 *
 * Time:  O(n log n + n log M), where M = max(nums).
 *        - Building prefixGcd: n gcd calls, each O(log M) via Euclid.
 *        - Sort: O(n log n).
 *        - Two-pointer pass: n/2 gcd calls, each O(log M).
 * Space: O(1) auxiliary (in-place transform; ignoring the sort's O(log n)
 *        stack and Euclid's O(log M) recursion depth).
 *
 * Approach (detail):
 *   1. Build prefixGcd in place. Sweep left-to-right keeping mx = running
 *      prefix maximum of nums[0..i]; set nums[i] = gcd(mx, nums[i]). Because
 *      mx >= nums[i] at each step, this exactly realizes the problem's
 *      prefixGcd[i] = gcd(nums[i], max(nums[0..i])).
 *   2. Sort prefixGcd in non-decreasing order.
 *   3. Pair the smallest unpaired with the largest unpaired: two pointers
 *      l=0, r=n-1, moving inward, accumulating gcd(nums[l], nums[r]). The
 *      loop condition l < r stops before they meet, so when n is odd the
 *      lone middle element is naturally skipped (ignored), as required.
 *   4. Return the accumulated sum (use long long — up to n/2 gcd values,
 *      each up to max(nums), can overflow 32-bit).
 */

class Solution {
    private:
        int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }

    public:
        long long gcdSum(vector<int>& nums) {
            int max_ele = -1, n = nums.size();
            for (int i = 0; i < n; ++i){
                max_ele = max(max_ele, nums[i]);
                nums[i] = gcd(max_ele, nums[i]);
            }
            sort(nums.begin(), nums.end());
            int l = 0, r = n-1;
            long long sum = 0;
            while (l < r){
                sum += gcd(nums[l++], nums[r--]);
            }
            return sum;
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