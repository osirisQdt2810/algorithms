#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxAscendingSum(vector<int>& nums) {
            int res = nums[0], n = nums.size();
            int pos = 1, currSum = nums[0];
            while (pos < n){
                currSum = (nums[pos] > nums[pos - 1]) ? (currSum + nums[pos]) : nums[pos];
                res = max(res, currSum);
                ++pos;
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
    Solution sol;
    vector<int> nums = {1,4,3,3,2};
    cout << sol.maxAscendingSum(nums);

    return 0;
}