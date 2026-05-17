#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
private:
    int findMinBs(int l, int r, vector<int>& nums){
        if (l == r) return nums[l];
        if (l > r) return INT_MAX;
        if (nums[l] < nums[r]) return nums[l];
        int m = (l + r) / 2;
        if (nums[m] < nums[r]) return min(nums[m], findMinBs(l, m-1, nums));
        if (nums[m] > nums[r]) return min(nums[m], findMinBs(m+1,r,nums));
        int min_left_right = min(findMinBs(l, m-1, nums), findMinBs(m+1, r, nums));
        return min(nums[m], min_left_right);
    }
public:
    int findMinBsNoRecursion(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ans = INT_MAX;
        while (l <= r){
            int m = (l + r) / 2;
            if (nums[m] < nums[r]){
                ans = min(ans, nums[m]);
                r = m - 1;
            }
            else if (nums[m] > nums[r]){
                l = m + 1;
            }
            else {
                ans = min(ans, nums[r]);
                r--;
            }
        }
        return ans;
    }

    int findMinBsNoRecursion2(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int m = (l + r) / 2;
            if (nums[m] < nums[r]){
                r = m;
            }
            else if (nums[m] > nums[r]){
                l = m + 1;
            }
            else {
                r--;
            }
        }
        return nums[r];
    }

    int findMin(vector<int>& nums) {
        return findMinBsNoRecursion2(nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    cout << sol.findMin(nums) << endl;
    return 0;
}