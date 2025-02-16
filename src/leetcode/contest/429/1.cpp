#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isDistinctArray(vector<int>& nums, int k){
            if (k == nums.size()) return true;
            std::unordered_set<int> seen;
            for (int i = k; i < nums.size(); ++i) {
                // If the number is already in the set, it's a duplicate
                if (seen.find(nums[i]) != seen.end()) {
                    return false;
                }
                seen.insert(nums[i]);
            }
            return true;
        }
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        int k = 0;
        while (!isDistinctArray(nums, k)){
            ++ops;
           k = (k + 3 < nums.size() ? k + 3 : nums.size());
        }

        return ops;      
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    vector<int> nums = {4, 5, 6, 4, 4};
    Solution sol;
    cout << sol.minimumOperations(nums);

    return 0;
}