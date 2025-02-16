#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int waysToSplitArray(vector<int>& nums) {
            int ans = 0, n = nums.size();
            long long currSum = 0, sum = 0; for (auto& num : nums) sum += num;

            for (int i = 0; i < n - 1; ++i){
                currSum += nums[i];
                ans += (2 * currSum >= sum);
            }
            return ans;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    vector<int> nums = {10,4,-8,7};

    Solution sol;
    cout << sol.waysToSplitArray(nums);
    return 0;
}