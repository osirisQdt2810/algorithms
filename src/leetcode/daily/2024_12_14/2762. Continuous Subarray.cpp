#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int ptr = 0, N = nums.size();
        long long counter = 0;
        for (int i = 0; i < N; ++i){
            while (ptr < i && abs(nums[ptr] - nums[i]) > 2) ++ptr;
            counter += i - ptr + 1;
            cout << "i = " << i << " - ptr = " << ptr << " -> cnt = " << i - ptr + 1 << " -> total = " << counter << "\n";
        }
        return counter;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // string s = "aaaa";
    // vector<int> nums = {5,4,2,4};
    vector<int> nums = {65,66,67,66,66,65,64,65,65,64};

    Solution sol;
    cout << sol.continuousSubarrays(nums);

    return 0;
}