#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int n = nums.size();
            int pivot;
            for (pivot = 1; pivot < n; ++pivot){
                if (nums[pivot] < nums[pivot-1]){
                    if (nums[pivot] > nums[0]){
                        return false;
                    }
                    break;
                }
            }
            for (int i = pivot+1; i < n; ++i){
                if (nums[i] > nums[0] || nums[i] < nums[i-1]){
                    return false;
                }
            }
            return true;
        }
};