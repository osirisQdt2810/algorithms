#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        void trace(
            vector<vector<int>>& grid,
            const vector<vector<int>>& dp,
            int i, int j
        ){
            if (i == 0 && j == 0){
                grid[i][j] = 0;
                return;
            }
            
            if (i > 0 && dp[i][j] == dp[i-1][j] + grid[i][j])
                trace(grid, dp, i - 1, j);
            else if (j > 0 && dp[i][j] == dp[i][j-1] + grid[i][j])
                trace(grid, dp, i, j - 1);

            grid[i][j] = 0;
        }

    public:
        long long gridGame2(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    if (i > 0){
                        dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j]);
                    }
                    if (j > 0){
                        dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j]);
                    }
                }
            }
            trace(grid, dp, m - 1, n - 1);
            cout << dp[m-1][n-1] << "\n";
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    cout << grid[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    dp[i][j] = grid[i][j];
                    if (i > 0){
                        dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j]);
                    }
                    if (j > 0){
                        dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j]);
                    }
                }
            }
            return dp[m-1][n-1];
        }

        long long gridGame3(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<long long> A(n + 1, 0), B(n + 1, 0);
            for (int i = 0; i < n; ++i){
                A[i+1] = A[i] + grid[0][i];
                B[i+1] = B[i] + grid[1][i];
            }

            long long res = LONG_LONG_MAX;
            for (int i = 0; i < n; ++i){        // first robot will
                                                //      0...0 ai+1 ... an-1
                                                //      b0..0 0 .......0
                res = min(res, max(A[n] - A[i+1], B[i]));
                cout << "i = " << i << " - a = " << A[n] - A[i+1] << " - b = " << B[i] << "\n";
            }
            return res;
        };

        long long gridGame(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            long long sumA = 0;
            for (int i = 0; i < n; ++i){
                sumA += grid[0][i];
            }

            long long preA = 0, preB = 0;

            long long res = LONG_LONG_MAX;
            for (int i = 0; i < n; ++i){        // first robot will
                                                //      0...0 ai+1 ... an-1
                                                //      b0..0 0 .......0
                preA += grid[0][i];
                res = min(res, max(sumA - preA, preB));
                preB += grid[1][i];
                // cout << "i = " << i << " - a = " << A[n] - A[i+1] << " - b = " << B[i] << "\n";
            }
            return res;
        };
};


auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};

    cout << sol.gridGame(grid);

    return 0;
}