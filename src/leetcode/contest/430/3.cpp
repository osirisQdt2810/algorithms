#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        map<float, int> existed;
        int n = nums.size();

        existed[1.f * nums[2] / nums[0]] = 1;

        long long res = 0;
        for (int s = 4; s < n; ++s){
            for (int r = s + 2; r < n; ++r){
                float t = 1.f * nums[s] / nums[r];
                if (existed.find(t) != existed.end()){
                    res += existed[t];
                }
                // cout << "find: " << t << " -> " << (existed.find(t) != existed.end() ? "exist" : "not exist") << endl;
            }

            for (int p = s - 3; p >= 0; --p){
                float t = 1.f * nums[s-1] / nums[p];

                if (existed.find(t) == existed.end()){
                    existed[t] = 1;
                }
                else {
                    existed[t]++;
                }
                // cout << "insert: " << 1.f * nums[s-1] / nums[p] << "\n";
            }

        }
        return res;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    vector<int> nums = {1,2,3,4,3,6,1};
    // vector<int> nums = {3,4,3,4,3,4,3,4};

    Solution sol;
    cout << sol.numberOfSubsequences(nums);

    return 0;
}