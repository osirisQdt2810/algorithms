#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            using ii = pair<int, int>;
            int n = nums.size();
            vector<ii> pairs(n); 
            for (int i = 0; i < n; ++i) pairs[i] = {nums[i], i};
            sort(pairs.begin(), pairs.end());

            for (int i = 0; i < n; i++){
                int l = i + 1, r = n - 1, j = 0, targ = target - pairs[i].first;
                while (l <= r){
                    int m = (l + r) / 2;
                    if (pairs[m].first == targ){
                        j = m;
                        break;
                    }
                    else if (pairs[m].first < targ){
                        l = m + 1;
                    }
                    else {
                        r = m - 1;
                    }
                }

                if (j > 0) return {pairs[i].second, pairs[j].second};
            }
            return {-1, -1};
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
    vector<int> nums = {0, 4, 3, 0};
    int target = 0;
    auto res = sol.twoSum(nums, target);
    cout << "(" << res[0] << ", " << res[1] << ")";
    return 0;
}