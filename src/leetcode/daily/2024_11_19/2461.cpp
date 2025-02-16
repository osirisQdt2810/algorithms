#include <bits/stdc++.h>

using namespace std;

/**
    2461. Maximum Sum of Distinct Subarrays With Length K

    You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

    The length of the subarray is k, and
    All the elements of the subarray are distinct.
    Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

    A subarray is a contiguous non-empty sequence of elements within an array.
*/
typedef long long ll;

class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            int N = nums.size();
            vector<ll> sum(N, 0); 
            sum[0] = nums[0];
            for (int i = 1; i < N; ++i){
                sum[i] = sum[i-1] + nums[i];
            }

            map<int, int> prevIndexes;
            vector<int> freqs(N + 1, 0);

            for (int i = 0; i < N; ++i){
                if (prevIndexes.find(nums[i]) != prevIndexes.end()){
                    if (i - prevIndexes[nums[i]] + 1 <= k){
                        ++freqs[i];
                        --freqs[min(N, prevIndexes[nums[i]] + k)];
                    }
                }
                prevIndexes[nums[i]] = i;
            }

            for (int i = 0; i < N; ++i){
                freqs[i] = (i == 0) ? freqs[i] : (freqs[i] + freqs[i - 1]);
            //     cout << freqs[i] << " ";
            }
            // cout << "\n";

            ll res = -INT_MAX;
            for (int i = min(k - 1, N - 1); i < N; ++i){
                if (freqs[i] == 0){
                    res = max(res, sum[i] - ((i > k - 1) ? sum[i - k] : 0));
                }
            }
            return (res == -INT_MAX) ? 0 : res;
        }
};

int main(){
    vector<int> nums = {9, 9, 9, 1, 2, 3};
    int k = 3;

    Solution s;
    cout << s.maximumSubarraySum(nums, k);

    return 0;
}