#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
            int m = isWater.size(), n = isWater[0].size();
            vector<vector<int>> res(m, vector<int>(n, -1));
            using ii = pair<int, int>;
            queue<ii> Q;
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    if (isWater[i][j] == 1){
                        Q.push({i, j});
                        res[i][j] = 0;
                    }
                }
            }

            while (!Q.empty()){
                auto [r, c] = Q.front(); Q.pop();

                if (r > 0 && res[r - 1][c] == -1){
                    res[r - 1][c] = res[r][c] + 1;
                    Q.push({r - 1, c});
                }
                if (r + 1 < m && res[r + 1][c] == -1){
                    res[r + 1][c] = res[r][c] + 1;
                    Q.push({r + 1, c});
                }
                if (c > 0 && res[r][c - 1] == -1){
                    res[r][c - 1] = res[r][c] + 1;
                    Q.push({r, c - 1});
                }
                if (c + 1 < n && res[r][c + 1] == -1){
                    res[r][c + 1] = res[r][c] + 1;
                    Q.push({r, c + 1});
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

    vector<vector<int>> isWater = {{0,1},{0,0}};

    for (auto& row : sol.highestPeak(isWater)){
        for (auto& c : row){
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}