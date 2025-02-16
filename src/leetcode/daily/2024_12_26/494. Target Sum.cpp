#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static inline const int SUP = 20000;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        if (N == 0) return 0;

        vector<vector<int>> dp(N, vector<int>(2 * SUP, 0));
        if (nums[0] != 0)
            dp[0][SUP + nums[0]] = dp[0][SUP - nums[0]] = 1;
        else 
            dp[0][SUP] = 2;

        for (int i = 1; i < N; ++i){
            for (int t = 0; t < 2 * SUP; ++t){
                if (t + nums[i] < 2 * SUP)
                    dp[i][t] += dp[i - 1][t + nums[i]];
                if (t >= nums[i])
                    dp[i][t] += dp[i - 1][t - nums[i]];
            }
        }

        return dp[N-1][SUP + target];
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // vector<int> nums = {1, 1, 1, 1, 1}; int target = 3;
    vector<int> nums = {0, 0, 1}; int target = 1;

    Solution sol;
    cout << sol.findTargetSumWays(nums, target);

    return 0;
}