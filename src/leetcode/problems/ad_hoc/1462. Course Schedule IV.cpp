#include <bits/stdc++.h>

using namespace std;

/**
 * @brief dfs ket hop voi memoization de luu lai trang thai prerequisites cua 2 dinh u, v
 * 
 */
class Solution {
    private:
        vector<vector<int>> prer;   // -1: un-assigned, 0: no, 1: yes

    public:
        void dfs(int u, vector<int>& parents, vector<bool>& visited, const vector<vector<int>>& adj){
            if (visited[u]) return;

            visited[u] = true;
            for (auto& p : parents){
                prer[p][u] = 1;
            }
            parents.push_back(u);
            for (auto& v : adj[u]){
                dfs(v, parents, visited, adj);
            }
            parents.pop_back();
        }

        vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
            vector<vector<int>> adj(numCourses, vector<int>());
            prer.assign(numCourses, vector<int>(numCourses, -1));
            for (auto& prerequisite : prerequisites){
                prer[prerequisite[0]][prerequisite[1]] = 1;
                adj[prerequisite[0]].push_back(prerequisite[1]);
            }

            vector<bool> res;
            for (auto& query : queries){
                if (prer[query[0]][query[1]] == -1){
                    vector<int> parents;
                    vector<bool> visited(numCourses, false);
                    dfs(query[0], parents, visited, adj);

                    for (int q = 0; q < numCourses; ++q){
                        if (visited[q] == false){
                            prer[query[0]][q] = 0;
                        }
                    }
                }

                res.push_back(prer[query[0]][query[1]] == 1);
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

}