#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
    private:
        int findMinBs(int l, int r, const vector<int>& nums){
            if (l > r) return INT_MAX;
            if (nums[l] <= nums[r]) return nums[l];
            int m = (l + r) / 2;
            if (nums[m] <= nums[r]) return min(nums[m], findMinBs(l, m - 1, nums));
            return findMinBs(m + 1, r, nums);
        }

    public:
        int findMin(vector<int>& nums) {
            return findMinBs(0, nums.size() - 1, nums);
        }
};

int main(){
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    cout << sol.findMin(nums) << endl;
    return 0;
}