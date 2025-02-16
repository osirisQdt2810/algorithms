#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long currVal = LLONG_MIN; // can use -1e15 if you prefer
        int distinctCount = 0;
    
        for (int i = 0; i < (int)nums.size(); i++) {
            long long candidate = max(currVal, (long long)nums[i] - k);
    
            if (candidate <= (long long)nums[i] + k) {
                distinctCount++;
                currVal = candidate + 1;
            }
        }
    
        return distinctCount;
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

}