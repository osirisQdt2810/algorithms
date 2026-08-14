#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int longestArithSeqLength(vector<int>& nums) {
            int N = nums.size();
            auto maxNum = *std::max_element(nums.begin(), nums.end());
            vector<vector<int>> dp(N, vector<int>(2 * maxNum + 1, 1));
            int res = -1;
            // for (auto& num : nums) cout << num << " ";
            // cout << "\n\n";
            for (int i = 0; i < N; ++i){
                for (int j = 0; j < i; ++j){
                    int diff = nums[i] - nums[j] + maxNum;
                    dp[i][diff] = dp[j][diff] + 1;
                    // if (res < dp[i][diff]){
                        // std::cout << "i = " << i << " j = " << j << " diff = " << diff << " - dp = " << dp[i][diff] << "\n";
                    // }
                    res = max(res, dp[i][diff]);
                }
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
    // vector<int> arr = {0,8,45,88,48,68,28,55,17,24};
    //                 0  1  2  3  4 5  6 7 8
    vector<int> arr = {24,13,1,100,0,94,3,0,3};

    Solution s;
    cout << s.longestArithSeqLength(arr);

    return 0;
}