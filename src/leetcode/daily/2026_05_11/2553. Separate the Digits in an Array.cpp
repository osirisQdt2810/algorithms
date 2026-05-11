#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
    public:
        vector<int> separateDigits(vector<int>& nums) {
            vector<int> res;
            int n = nums.size();
            for (int i = n - 1; i >= 0; i--){
                int num = nums[i];
                while (num){
                    res.insert(res.begin(), num % 10);
                    num /= 10;
                }
            }

            return res;
        }
};

int main(){
    Solution sol;

    // vector<int> nums = {2, 3, 1};
    vector<int> nums = {711212, 5, 7};
    vector<int> result = sol.separateDigits(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}