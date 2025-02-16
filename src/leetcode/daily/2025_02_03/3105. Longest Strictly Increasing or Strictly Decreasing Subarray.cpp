#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int longestMonotonicSubarray2(vector<int>& nums) {
            using ii = pair<int, int>;
            int res = 1, n = nums.size();
            stack<ii> lis, lds;
            vector<int> idp(n), ddp(n);

            idp[0] = ddp[0] = nums[0];
            lis.push({idp[0], 0});
            lds.push({ddp[0], 0});

            for (int i = 1; i < n; ++i){
                while (!lis.empty() && lis.top().first >= nums[i]) lis.pop();
                idp[i] = (!lis.empty()) ? idp[lis.top().second] + 1: 1;
                while (!lds.empty() && lds.top().first <= nums[i]) lds.pop();
                ddp[i] = (!lds.empty()) ? ddp[lds.top().second] + 1 : 1;
                
                res = max(max(res, idp[i]), ddp[i]);
                lis.push({idp[i], i});
                lds.push({ddp[i], i});
            }
            return res;
        }

        int longestMonotonicSubarray(vector<int>& nums) {
            int res = 1, n = nums.size();
            vector<int> idp(n), ddp(n);
            idp[0] = ddp[0] = 1;

            for (int i = 1; i < n; ++i){
                idp[i] = (nums[i] > nums[i-1]) ? idp[i-1] + 1 : 1;
                ddp[i] = (nums[i] < nums[i-1]) ? ddp[i-1] + 1 : 1;
                res = max(max(res, idp[i]), ddp[i]);
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
    cout << sol.longestMonotonicSubarray(nums);

    return 0;
}