#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            using Number = int;
            using Freq = int;
            int n = nums.size();            
            
            unordered_map<Number, Freq> n2f;
            for (int i = 0; i < n; ++i){
                auto ni = nums[i] - i;
                if (n2f.find(ni) == n2f.end())
                    n2f[ni] = 1;
                else
                    ++n2f[ni];
            }

            long long s = 0, res = 0;
            for (auto it = n2f.begin(); it != n2f.end();){
                auto f = it->second;
                s += f;
                ++it;
                if (it == n2f.end()) break;
                res += s * it->second;
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
    vector<int> nums = {4,1,3,3};

    cout << sol.countBadPairs(nums);

    return 0;
}