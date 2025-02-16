#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isArraySpecial(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return true;
            int parity = nums[0] % 2;
            for (int i = 1; i < n; ++i){
                if (nums[i] % 2 == parity)
                    return false;
                
                parity = 1 - parity;
            }
            return true;
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
    vector<int> nums = {3, 5, 1, 2};
    cout << (sol.isArraySpecial(nums) ? "true" : "false");

    return 0;
}