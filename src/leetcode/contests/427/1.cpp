#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N);
        for (int i = 0; i < N; ++i){
            if (nums[i] == 0){
                result[i] = nums[i];
            }
            else if (nums[i] > 0){
                result[i] = nums[(i + nums[i]) % N];
            }
            else {
                result[i] = nums[(i + N - (-nums[i]) % N) % N];
            }
        }
        return result;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // vector<int> nums = {3,-2,1,1};
    vector<int> nums = {-1, 4, -1};

    Solution s;
    for (auto& t : s.constructTransformedArray(nums)){
        cout << t << "\n";
    }
}