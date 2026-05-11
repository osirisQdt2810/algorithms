#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        /* Analyze:
        // find i, j, k satisfying:
        // val = abs(y) = abs(nums[j] + nums[k] - target)
        // if (y < 0) => j += 1
        // if (y >= 0) => k -= 1

        // 0, 3, 6, 7, 8, 12, 15
        // target = 18
        // i=0 => -4
        // -> abs(nums[j] + nums[k] - 5) min
        // nums[n] in [0, 2000]
        // target += 3000 => target in [-10^4 + 3000, 10^4 + 3000]
        // abs(nums[i] + nums[j] + nums[k] - target)
        // if target < 0 => we choose (i, j, k) min
        // if target > 0, nums[n] > 0
        //      => we need to find: (i, j, k) satisfying: nums[i] + nums[j] + nums[k] ~ target
        //         where: 0 <= nums[0] <= nums[1] <= nums[2] <= ... 
        // fix nums[i] => need to find (j, k): i < j < k: nums[j] + nums[k] ~ (target - nums[i] > 0) => abs(nums[j] + nums[k] - X)
        // pointers l = i + 1, r = n - 1, ans = 
        // while l < r:
        //    val = abs(nums[l] + nums[r] - X)  
        //    if (ans >= val){
        //        ans = val; 
        //.   }
        //
        */
        int threeSumClosest(vector<int>& nums, int target) {
            // first, we change the input problem so that nums[i] >= 0 for all i
            // ps: actually, we dont need to do the trick that nums[i] >= 0 for all i
            static constexpr int NUM_COMPL = 0;
            static constexpr int TARGET_COMPL = 0;
            for (auto& num : nums) num += NUM_COMPL;
            target += TARGET_COMPL;

            // then, we sort the input array so that we can apply two pointers
            std::sort(nums.begin(), nums.end());

            // obviously, if target < 0, i, j, k must be: [0], [1], [2]
            if (target < 0) return (nums[0] + nums[1] + nums[2] - TARGET_COMPL);

            // otherwise, the problem turns into:
            // find (i, j, k), i < j < k, satisfying: min(nums[i] + nums[j] + nums[k] - target)
            // where: nums is an increasing positive array and target >= 0
            // fixed i, we must find: min(nums[j] + nums[k] - (target - nums[i]))
            int n = nums.size();
            int minabs = std::numeric_limits<int>::max();
            int ans = 0;
            for (int i = 0; i < n - 2; ++i){
                if (target < nums[i]){
                    int sum = nums[i + 1] + nums[i + 2] + nums[i];
                    int curr_abs = abs(sum - target);
                    if (minabs > curr_abs){
                        // cout << i << " " << i + 1 << " " << i + 2 << " -> curr-min = " << curr_abs << "\n";
                        minabs = curr_abs;
                        ans = (sum - TARGET_COMPL);
                    }
                    continue;
                }
                // target >= nums[i]
                int ntarget = target - nums[i];
                int l = i + 1, r = n - 1;
                while (l < r){
                    int val = nums[l] + nums[r] - ntarget;
                    int val_abs = abs(val);
                    if (minabs > val_abs){
                        // cout << i << " " << l << " " << r << " -> curr-min = " << val_abs << " | " << nums[l]  << " " << nums[r] << " " << nums[i] << " " << target << " " << ntarget << "| val: " << val <<  "\n";
                        minabs = val_abs;
                        ans = nums[i] + nums[l] + nums[r] - TARGET_COMPL;
                    }
                    if (val >= 0){
                        --r;
                    }
                    else {
                        ++l;
                    }

                }
            }
            // cout << minabs << "\n";
            return ans;
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
    vector<int> nums = {10,20,30,40,50,60,70,80,90};
    int target = 0;

    cout << sol.threeSumClosest(nums, target);

    return 0;
}