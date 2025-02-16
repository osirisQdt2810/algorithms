#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            if (nums.size() < 4) return 0;
            sort(nums.begin(), nums.end());
            using Ratio_t = double;
            using Counter_t = int;
            unordered_map<Ratio_t, Counter_t> r2c;
            int n = nums.size(), res = 0;
            for (int p = 0; p < n - 1; ++p){
                for (int q = p + 1; q < n; ++q){
                    Ratio_t r = 1. * nums[p] / nums[q];
                    if (r2c.find(r) != r2c.end()){
                        res += 8 * r2c[r];
                    }
                }

                for (int k = 0; k < p; ++k){
                    Ratio_t r = 1. * nums[k] / nums[p];
                    if (r2c.find(r) != r2c.end())
                        ++r2c[r];
                    else
                        r2c[r] = 1;
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
    Solution sol;
    vector<int> nums = {2,3,4,6};
    cout << sol.tupleSameProduct(nums);

    return 0;
}