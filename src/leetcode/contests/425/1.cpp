#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int N = nums.size();
        vector<int> sum(N + 1, 0);
        sum[0] = 0;
        for (int i = 1; i <= N; ++i){
            sum[i] = sum[i - 1]  + nums[i - 1];     // s[i] = a[0] + ... + a[i - 1] <=> a[i] + ... + a[j] = s[j + 1] - s[i], 1
        }

        int res = INT_MAX;
        for (int i = 0; i < N; ++i){
            for (int j = i; j < N; ++j){
                // find: a[a] + ... + a[b] = s[b + 1] - s[a]
                int sum_ij = sum[j + 1] - sum[i];
                int size_ij = j - i + 1;
                if (sum_ij > 0 && size_ij >= l && size_ij <= r){
                    res = min(res, sum_ij);
                }
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};

int main(){
    // vector<int> nums = {-2, 2, -3, 1};
    // int l = 2, r = 3;

    vector<int> nums = {3, -2, 1, 4};
    int l = 2, r = 3;

    Solution s;
    cout << s.minimumSumSubarray(nums, l, r);

    return 0;
}