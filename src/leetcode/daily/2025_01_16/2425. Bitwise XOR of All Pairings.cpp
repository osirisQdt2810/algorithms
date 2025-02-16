#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
            int t1 = 0, t2 = 0;
            if (n % 2){
                for (auto& num1 : nums1){
                    t1 ^= num1;
                    // cout << "num1 = " << num1 << " - t1 = " << t1 << "\n";
                }
            }
            if (m % 2){
                for (auto& num2 : nums2){
                    t2 ^= num2;
                    // cout << "num2 = " << num2 << " - t2 = " << t2 << "\n";
                }
            }
            // cout << "t1 = " << t1 << " -> t2 = " << t2 << " -> " << (t1 ^ t2) << "\n";
            return t1 ^ t2;
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
    vector<int> nums1 = {2,1,3}, nums2 = {10,2,5,0};
    cout << sol.xorAllNums(nums1, nums2);
    return 0;
}