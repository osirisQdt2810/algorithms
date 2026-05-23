#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
class Solution {
private:
    int find_splitted_index(vector<int>& nums){
        int n = nums.size();
        int l = 0, r = n-1, ans=n-1;
        // vector<int>  nums = {4,5,6,7,0,1,2};
        //  [5,1,3]
        while (l <= r){
            int m = (l + r) / 2;
            if (nums[m] < nums[r]){
                ans = m;
                r = m;
            }
            else {
                l = m+1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target, int lower, int upper){
        int l = lower, r = upper;
        while (l <= r){
            int m = (l + r) / 2;
            if (nums[m] == target){
                return m;
            }
            else if (nums[m] < target){
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) return (nums[0] == target) ? 0 : -1;

        int k = find_splitted_index(nums);
        return (nums[n-1] >= target) ? search(nums, target, k, n-1) : search(nums, target, 0, k-1);
    }
};

int main(){
    Solution sol;
    vector<int>  nums = {3,1};
    int target = 0;
    int ans = sol.search(nums, target);
    cout << ans << "\n";
    return 0;
}