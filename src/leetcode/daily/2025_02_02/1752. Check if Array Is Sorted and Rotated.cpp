#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int pos = 1, n = nums.size();
            while (pos < n && nums[pos - 1] <= nums[pos]) ++pos;
            if (pos == n) return true;
            while (pos + 1 < n){
                if (nums[pos] > nums[pos + 1] || nums[pos] > nums[0]) return false;
                ++pos;
            }
            return nums[pos] <= nums[0];
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
    cout << (sol.check(nums) ? "true" : "false");

    return 0;
}