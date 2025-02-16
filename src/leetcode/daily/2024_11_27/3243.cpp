#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int bfs(int n, const vector<vector<int>>& adj){
            queue<int> Q;
            vector<int> path(n, 0);

            Q.push(0); path[0] = 1;
            while (!Q.empty()){
                int u = Q.front(); Q.pop();
                if (u == n - 1){
                    return path[u];
                }

                for (const auto& v : adj[u]){
                    if (path[v] == 0){
                        path[v] = path[u] + 1;
                        Q.push(v);
                    }
                }
            }

            return path[n - 1];
        }

        vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
            vector<vector<int>> adj(n, vector<int>());
            for (int u = 0; u < n - 1; ++u){
                adj[u].push_back(u + 1);
            }
            vector<int> res;
            for (auto& Q: queries){
                adj[Q[0]].push_back(Q[1]);
                res.push_back(bfs(n, adj) - 1);
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
    int n = 5;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};

    Solution s;
    for (auto t : s.shortestDistanceAfterQueries(n, queries))
        cout << t << " ";

    return 0;
}