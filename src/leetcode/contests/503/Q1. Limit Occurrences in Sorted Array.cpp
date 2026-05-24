#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i){
            if (++f[nums[i]] <= k)
                res.push_back(nums[i]);
        }
        return res;
    }
};