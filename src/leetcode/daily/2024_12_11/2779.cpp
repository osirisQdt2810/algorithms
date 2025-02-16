#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
            int min_ele = INT_MAX, max_ele = -INT_MAX;
            for (auto& num : nums){
                int start = num - k;
                int end = num + k;
                min_ele = min(min_ele, start);
                max_ele = max(max_ele, end);
            }

            int N = max_ele - min_ele;
            vector<int> freqs(N + 2, 0);
            for (auto& num : nums){
                int start = num - k;
                int end = num + k;
                ++freqs[start - min_ele];
                --freqs[end + 1 - min_ele];
            }

            // cout << "min_ele = " << min_ele << " - max_ele = " << max_ele << "\n";

            int beauty = -INT_MAX;
            for (int i = min_ele; i <= max_ele; ++i){
                int trueIdx = i - min_ele;
                freqs[trueIdx] = (i > min_ele) ? freqs[trueIdx] + freqs[trueIdx - 1] : freqs[trueIdx];
                // cout << "i = " << i << " - freqs = " << freqs[trueIdx] << "\n";
                beauty = max(beauty, freqs[trueIdx]);
            }
            return beauty;
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
    vector<int> nums = {13,46,71};
    int k = 29;

    Solution sol;
    cout << sol.maximumBeauty(nums, k);

    return 0;
}