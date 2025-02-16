#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        vector<int> target(N);
        for (int i = N - 1; i >= 0; --i){
            target[i] = prices[i];
            for (int j = i + 1; j < N; ++j){
                if (prices[j] <= prices[i]){
                    target[i] -= prices[j];
                    break;
                }
            }
        }
        return target;
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

    // vector<int> nums = {2,1,3,5,6};
    // int k = 5, multiplier = 2;

    // vector<int> nums = {100000, 2000};
    // int k = 2, multiplier = 1000000;

    vector<int> nums = {4, 2, 4};
    int k = 3, multiplier = 2;

    sol.getFinalState(nums, k, multiplier);

    return 0;
}