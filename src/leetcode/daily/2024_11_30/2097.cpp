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
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int N = pairs.size();
        map<int, vector<int>> back;
        for (int i = 0; i < N; ++i){
            back[pairs[i][0]].push_back(i);
        }

        vector<vector<int>> adj(N, vector<int>());
        for (int i = 0; i < N; ++i){
            if (back.find(pairs[i][1]) != back.end()){
                adj[i] = std::move(back[pairs[i][1]]);
            }

            cout << "i = " << i << " : ";
            for (auto& e : adj[i])
                cout << e << " ";
            cout << "\n";
        }
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

    vector<vector<int>> grid = {{5,1},{4,5},{11,9},{9,4}};

    s.validArrangement(grid);

    return 0;
}