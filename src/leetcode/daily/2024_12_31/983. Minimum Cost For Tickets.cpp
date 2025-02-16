#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = min(costs[0], min(costs[1], costs[2]));
        for (int i = 1; i < n; ++i){
            // using 1-day:
            dp[i] = min(dp[i], dp[i-1] + costs[0]);
            // cout << "   - 0. " << dp[i] << "\n";
            // using 7-day:
            int j = i - 1;
            while (j >= 0 && days[j] >= days[i] - 6) --j;
            dp[i] = min(dp[i], ((j >= 0) ? dp[j] : 0) + costs[1]);
            // cout << "   - 1. " << dp[i] << "\n";

            // using 30-day:
            int k = i - 1;
            while (k >= 0 && days[k] >= days[i] - 29) --k;
            dp[i] = min(dp[i], ((k >= 0) ? dp[k] : 0) + costs[2]);
            // cout << "   - 2. " << dp[i] << "\n";

            // cout << "i = " << i << " -> dp = " << dp[i] << "\n";
        }

        return dp[n-1];
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    vector<int> days = {1,4,6,7,8,20}, costs = {7,2,15};

    Solution sol;
    cout << sol.mincostTickets(days, costs);

    return 0;
}