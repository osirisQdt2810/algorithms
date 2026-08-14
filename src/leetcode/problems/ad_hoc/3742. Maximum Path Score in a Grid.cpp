#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int maxPathScore(vector<vector<int>>& grid, int k) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<vector<int>>> scores(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

            vector<int> penalty = {0, 1, 1};
            vector<int> reward  = {0, 1, 2};

            for (int ko = 0; ko <= k; ++ko)
                scores[0][0][ko] = reward[grid[0][0]];

            for (int r = 0; r < m; ++r){
                for (int c = 0; c < n; ++c){
                    for (int ko = 0; ko <= k; ++ko){
                        int rcost = ko - penalty[grid[r][c]];
                        if (rcost >= 0){
                            if (r >= 1 && scores[r-1][c][rcost] >= 0){
                                scores[r][c][ko] = scores[r-1][c][rcost] + reward[grid[r][c]];
                            }
                            if (c >= 1 && scores[r][c-1][rcost] >= 0){
                                scores[r][c][ko] = max(scores[r][c][ko], scores[r][c-1][rcost] + reward[grid[r][c]]);
                            }
                        }
                    }
                }
            }
            return scores[m-1][n-1][k];
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
    vector<vector<int>> grid = {{0, 1},{1, 2}};
    int k = 1;
    cout << sol.maxPathScore(grid, k);
    return 0;
}