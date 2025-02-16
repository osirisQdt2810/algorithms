#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxTwoEvents2(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[1] < rhs[1];
        });

        for (auto& es : events){
            for (auto& e : es){
                cout << e << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        cout << "\n";

        int N = events.size();
        vector<int> dp(N);
        dp[0] = events[0][2];

        cout << "i = " << 0 << " : dp = " << dp[0] << "\n";
        for (int i = 1; i < N; ++i){
            int start = events[i][0], end = events[i][1], value = events[i][2];
            // find best event j have: end[j] < start
            int l = 0, r = i - 1, ans = -1;
            while (l <= r){
                int m = (l + r) / 2;
                if (events[m][1] < start){
                    ans = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }

            if (ans != -1){
                dp[i] = max(dp[i-1], dp[ans] + value);
            }
            else {
                dp[i] = max(dp[i-1], value);
            }
            cout << "i = " << i << " -> ans = " << ans << " : dp = " << dp[i] << "\n";

        }
        return dp[N-1];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[1] < rhs[1];
        });

        int N = events.size();
        vector<int> maxValue(N, 0);
        maxValue[0] = events[0][2];
        int res = maxValue[0];
        for (int i = 1; i < N; ++i) {
            maxValue[i] = max(maxValue[i-1], events[i][2]);
            res = max(res, maxValue[i]);
        }

        for (int i = 1; i < N; ++i){
            int s = events[i][0], e = events[i][1], v = events[i][2];
            int l = 0, r = i - 1, ans = -1;
            while (l <= r){
                int m = (l + r) / 2;
                if (events[m][1] < s){
                    ans = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            if (ans >= 0){
                res = max(res, v + maxValue[ans]);
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
    Solution sol;

    // vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    vector<vector<int>> events = {{10,83,53},{63,87,45},{97,100,32},{51,61,16}};

    cout << sol.maxTwoEvents(events);

    return 0;
}