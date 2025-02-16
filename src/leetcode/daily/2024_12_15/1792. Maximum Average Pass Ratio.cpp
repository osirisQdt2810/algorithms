#include <bits/stdc++.h>

using namespace std;

using dbi = pair<double, int>;

class Solution {
public:
    double delta(int p, int t, int i){
        return 1. * (p + i + 1) / (t + i + 1) - 1. * (p + i) / (t + i);
    }

    double maxAverageRatio2(vector<vector<int>>& classes, int extraStudents) {
        int N = classes.size(), T = extraStudents;
        double res = -1;

        vector<vector<double>> dp(N, vector<double>(T + 1, 0));

        for (int i = 0; i < N; ++i){
            int pi = classes[i][0], ti = classes[i][1];
            for (int j = 0; j <= T; ++j){
                double pre = (i >= 1 ? dp[i - 1][T - j] * i : 0);
                dp[i][j] = max(dp[i][j], (pre + 1. * (pi + j) / (ti + j)) / (i + 1));
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<dbi, vector<dbi>, less<dbi>> pq;
        vector<int> inc(classes.size(), 0);

        int N = classes.size(), T = extraStudents;

        for (int i = 0; i < N; ++i){
            pq.push({delta(classes[i][0], classes[i][1], 0), i});
            // cout << "i = " << i << " - delta(classes[i][0], classes[i][1], 0) = " << delta(classes[i][0], classes[i][1], 0) << "\n";
        }

        while (T--){
            auto [d, i] = pq.top(); pq.pop();
            
            // cout << "i = " << i << " : d = " << d << "\n";
            
            ++inc[i];
            pq.push({delta(classes[i][0], classes[i][1], inc[i]), i});
        }

        double res = 0;
        for (int i = 0; i < N; ++i)
            res += 1. * (classes[i][0] + inc[i]) / (classes[i][1] + inc[i]);

        return res / N;
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

    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;

    cout << sol.maxAverageRatio(classes, extraStudents);

    return 0;
}