#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
    public:
        int maximumJumps(vector<int>& nums, int target) {
            int n = nums.size();
            // dp[i]: maximum jumps from 0 -> i (i included) which complies that: all (j, k) in jump path satisfies abs(nums[j] - nums[k]) <= target
            vector<int> dp(n, -1);
            dp[0] = 0;
            for (int i = 1; i < n; ++i){
                for (int j = 0; j < i; ++j){
                    if (abs(nums[i] - nums[j]) <= target && dp[j] != -1){
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            return dp[n-1];
        }
};

int main(){
    Solution sol;

    vector<int> nums = { 0, 2, 1, 3};
    int target = 1;
    cout << sol.maximumJumps(nums, target);
    return 0;
}