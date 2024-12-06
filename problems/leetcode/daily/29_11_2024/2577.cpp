#include <bits/stdc++.h>

using namespace std;

struct Cell {
    int row, col;
    int time;
};

const int oo = 1e9;

struct CellComparison {
    bool operator()(const Cell& lhs, const Cell& rhs){
        return lhs.time > rhs.time;
    }
};

class Solution {
private:
    void make_edge(
        priority_queue<Cell, vector<Cell>, CellComparison>& pq,
        vector<vector<int>>& grid,
        vector<int>& time,
        int n_row, 
        int n_col,
        int N,
        int c_time
    ){
        int idx = n_row * N + n_col;
        if (c_time >= grid[n_row][n_col]){
            int target = c_time + 1;
            if (time[idx] > target){
                time[idx] = target;
                pq.push({n_row, n_col, time[idx]});
                // cout << "   -> push 1: r = " << n_row << " - c = " << n_col << " - time = " << time[idx] << "\n";
            }
        }
        else {
            int diff = grid[n_row][n_col] - c_time;
            int target = grid[n_row][n_col] + (1 - diff % 2);

            if (time[idx] > target){
                time[idx] = target;
                pq.push({n_row, n_col, time[idx]});
                // cout << "   -> push 2: r = " << n_row << " - c = " << n_col << " - time = " << time[idx] << "\n";
            }
        }
    }

public:
    int modified_dijikstra(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size(); int V = m * n;
        
        priority_queue<Cell, vector<Cell>, CellComparison> pq;
        vector<int> time(V, oo);

        time[0] = 0;
        pq.push({0, 0, time[0]});

        while (!pq.empty()){
            Cell c = pq.top(); pq.pop();
            int row = c.row, col = c.col, c_time = c.time;
            int idx = row * n + col;

            // cout << "row = " << row << " - col = " << col << " -> curr_time = " << c_time << " -> time[] = " << time[idx] << "\n";
            if (time[idx] != c_time) continue;  // a better path to [row, col] has been found, currently in pq
            if (row == m - 1 && col == n - 1) return c_time;


            if (col >= 1){
                make_edge(pq, grid, time, row, col - 1, n, c_time);
            }

            if (col < n - 1){
                make_edge(pq, grid, time, row, col + 1, n, c_time);
            }

            if (row >= 1){
                make_edge(pq, grid, time, row - 1, col, n, c_time);
            }

            if (row < m - 1){
                make_edge(pq, grid, time, row + 1, col, n, c_time);
            }
        }

        return time[m * n - 1];
    }

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        return modified_dijikstra(grid);    
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution s;

    vector<vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};

    cout << s.minimumTime(grid);

    return 0;
}