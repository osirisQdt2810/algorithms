#include <vector>
#include <iostream>

class Solution {
    public:
        int maxRotateFunction(std::vector<int>& nums) {
            // equation: F[i] - F[i+1] = sum - n * nums[i];
            int sum = 0, n = nums.size();
            int b = 0;
            for (int i = 0; i < n; ++i){
                sum += nums[i];
                b += i * nums[i];
            }
            int ans = b;
            for (int i = 1; i < n; ++i){
                b = b - (sum - n * nums[i-1]);
                ans = std::max(ans, b);
            }
            return ans;
        }
};

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    std::vector<int> nums = {100};
    std::cout << sol.maxRotateFunction(nums) << std::endl;
    return 0;
}