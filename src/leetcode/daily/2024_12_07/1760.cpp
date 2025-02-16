#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isValidMaxOperations(const vector<int>& nums, int maxOperations, int sz){
        int opsCounter = 0;
        for (const int& num : nums){
            opsCounter += (num + sz - 1) / sz - 1;
        }
        
        return (opsCounter <= maxOperations);
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        // int l = 1, r = 1e9, T = -1;
        int l = 1, r = *std::max_element(nums.begin(), nums.end()), T = -1;

        while (l <= r){
            int m = (l + r) / 2;
            // cout << "m = " << m << "\n";
            if (isValidMaxOperations(nums, maxOperations, m)){
                T = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return T;
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

    vector<int> nums = {9};
    int maxOperations = 2;

    cout << sol.minimumSize(nums, maxOperations);

    return 0;
}