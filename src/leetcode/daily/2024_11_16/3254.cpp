#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> recursive(vector<int>& num, int left, int right, int k){
            if (left > right) return {};

            int L = left; while (L + 1 <= right && num[L + 1] == num[L] + 1) ++L;
            int R = right; while (R - 1 > L && num[R - 1] == num[R] - 1) --R;

            // cout << "numbers: ";
            // for (auto n : num) cout << n << " ";
            // cout << "\n";
            // cout << "left = " << left << " | right = " << right <<  " | L = " << L << " | R = " << R << "\n";

            vector<int> res(right - left + 1);
            // left part
            for (int i = left; i <= L - k + 1; ++i) res[i - left] = num[i + k - 1];
            for (int i = max(left, L - k + 2); i <= L; ++i) res[i - left] = -1;
            // cout << "left part: ";
            // for (auto r : res) cout << r << " ";
            // cout << "\n";

            // mid part
            vector<int> mid = recursive(num, L + 1, R - 1, k);
            // res.insert(res.end(), mid.begin(), mid.end());
            for (int i = L + 1; i <= R - 1; ++i) res[i - left] = mid[i - L - 1];
            // cout << "mid part: ";
            // for (auto r : mid) cout << r << " ";
            // cout << "\n";

            // right part
            if (L < R){
                for (int i = R; i <= right - k + 1; ++i) res[i - left] = num[i + k - 1];

                if (left > 0){
                    for (int i = max(R, right - k + 2); i <= right; ++i) res[i - left] = -1;
                }
            }

            return res;
        }

        vector<int> resultsArray(vector<int>& nums, int k) {
            auto res = recursive(nums, 0, nums.size() - 1, k);    
            return vector<int>(res.begin(), res.begin() + nums.size() - k + 1);
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    vector<int> nums = {1};
    int k = 1;

    Solution s;
    for (auto t : s.resultsArray(nums, k)){
        cout << t << " ";
    }
}