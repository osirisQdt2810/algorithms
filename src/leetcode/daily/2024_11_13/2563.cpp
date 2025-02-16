#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        // arr[0] <= arr[1] <=... <= arr[N]
        // Find j minimum satisfy: arr[j] >= Q
        int binary_search_lower(vector<int>& arr, int fromIdx, int Q){
            int l = fromIdx + 1, r = arr.size() - 1, ans = -1;
            while (l <= r){
                int m = (l + r) / 2;
                if (arr[m] >= Q){
                    ans = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            return ans;
        }

        // arr[0] <= arr[1] <=... <= arr[N]
        // Find j maximum satisfy: arr[j] <= Q
        int binary_search_upper(vector<int>& arr, int fromIdx, int Q){
            int l = fromIdx + 1, r = arr.size() - 1, ans = -1;
            while (l <= r){
                int m = (l + r) / 2;
                if (arr[m] <= Q){
                    ans = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            return ans;
        }

        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());

            // for (auto& e: nums) cout << e << " ";
            // cout << "\n";

            long long cnt = 0;
            for (size_t i = 0; i < nums.size(); ++i){
                int j_lower = binary_search_lower(nums, i, lower - nums[i]);
                int j_upper = binary_search_upper(nums, i, upper - nums[i]);
                if (j_lower >= 0 && j_upper >= 0){
                    // cout << "i = " << i << " : val = " << nums[i] << " -> j_lower = " << j_lower << " -> j_upper = " << j_upper << "\n";
                    cnt += max(0, j_upper - j_lower + 1);
                }
            }
            return cnt;
        }
};

int main(){
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3, upper = 6;

    // vector<int> nums = {1, 7, 9, 2, 5};
    // int lower = 11, upper = 11;

    Solution s;
    cout << s.countFairPairs(nums, lower, upper);
}