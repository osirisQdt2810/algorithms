#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<vector<long long>> mod(k, vector<long long>());
        int N = nums.size();
        long long sum = 0;

        for (int i = 0; i < N; ++i){
            sum += nums[i];
            mod[i%k].push_back(sum);
        }

        long long res = -1e15;

        for (int i = 0; i < k; ++i){
            vector<long long> prefixs = mod[i];
            int M = prefixs.size();
            // cout << "prefix: \n";
            // for (auto& p : prefixs){
            //     cout << p << " ";
            // }
            // cout << "\n";

            if (i == k - 1){
                res = max(res, *std::max_element(prefixs.begin(), prefixs.end()));
            }
            long long prevMin = prefixs[0];

            for (int j = 1; j < M; ++j){
                res = max(res, prefixs[j] - prevMin);
                prevMin = min(prevMin, prefixs[j]);
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

    vector<int> nums = {1,2}; int k = 1;

    // vector<int> nums = {-1,-2,-3,-4,-5}; int k = 4;
    // vector<int> nums = {-5,1,2,-3,4}; int k = 2;

    Solution s;
    cout << s.maxSubarraySum(nums, k);

    return 0;
}