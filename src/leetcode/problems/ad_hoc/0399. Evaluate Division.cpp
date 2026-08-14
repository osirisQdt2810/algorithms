#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <unordered_map>

#include "topics/graph/disjoint_set_union.hpp"

using namespace std;

using Vertex = int;
using Weight = double;
using WeightNeighbor = std::pair<Vertex, Weight>;

struct Graph {
    int V, E;
    std::vector<std::vector<WeightNeighbor>> adj;
    std::vector<bool> visited;
};

class Solution {
    private:
        Graph build_graph(int V, const vector<vector<string>>& equations, const vector<double>& values, unordered_map<string, int>& var2id){
            Graph g;
            g.V = V;
            g.adj.resize(V);
            for (int i = 0; i < (int)(equations.size()); ++i){
                int u = var2id.at(equations[i][0]);
                int v = var2id.at(equations[i][1]);
                double w = values[i];
                g.adj[u].push_back({v, w});
                g.adj[v].push_back({u, 1. / w});
            }
            return g;
        }

        double dfs(Graph& g, int u, int target){
            if (u == target) return 1.;
            g.visited[u] = true;
            for (auto& [v, w] : g.adj[u]){
                if (!g.visited[v]){
                    double vt = dfs(g, v, target);
                    if (vt != -1.){
                        return vt * w;
                    }
                }
            }
            return -1.;
        }

    public:
        vector<double> calcEquationDFS(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            int V = 0;
            unordered_map<string, int> var2id;
            for (auto& equation : equations){
                if (var2id.find(equation[0]) == var2id.end()){
                    var2id[equation[0]] = V++;
                }
                if (var2id.find(equation[1]) == var2id.end()){
                    var2id[equation[1]] = V++;
                }
            }

            Graph g = build_graph(V, equations, values, var2id);

            // std::cout << g.V << "\n";
            // for (auto& [c, id] : var2id){
            //     std::cout << "c = " << c << " - " << "id = " << id << "\n";
            // }

            int Q = queries.size();
            vector<double> res(Q, -1.);
            for (int i = 0; i < Q; ++i){
                auto& q = queries[i];
                if (var2id.find(q[0]) == var2id.end() || var2id.find(q[1]) == var2id.end()) continue;
                int u = var2id.at(q[0]);
                int v = var2id.at(q[1]);
                g.visited.assign(V, false);
                res[i] = dfs(g, u, v);
                // std::cout << "i = " << i << " - res = " << res[i] << "\n";
            }
            return res;
        }

        vector<double> calcEquationWDSU(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            int V = 0;
            unordered_map<string, int> var2id;
            for (auto& equation : equations){
                if (var2id.find(equation[0]) == var2id.end()){
                    var2id[equation[0]] = V++;
                }
                if (var2id.find(equation[1]) == var2id.end()){
                    var2id[equation[1]] = V++;
                }
            }

            using WDSU = dsa::graph::WeightedDisjointSetUnion<double>;
            WDSU dsu(V);
            for (int i = 0; i < (int)(equations.size()); ++i){
                int u = var2id.at(equations[i][0]);
                int v = var2id.at(equations[i][1]);
                double w = values[i];
                dsu.unite(u, v, w);
            }

            int Q = queries.size();
            vector<double> res(Q, -1.);
            for (int i = 0; i < Q; ++i){
                auto& q = queries[i];
                if (var2id.find(q[0]) == var2id.end() || var2id.find(q[1]) == var2id.end()) continue;
                int u = var2id.at(q[0]);
                int v = var2id.at(q[1]);
                res[i] = dsu.query(u, v);
                if (res[i] == WDSU::kNil) res[i] = -1.;
                // std::cout << "i = " << i << " - res = " << res[i] << "\n";
            }
            return res;
        }

        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            return calcEquationWDSU(equations, values, queries);
        }
};

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution s;
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"a","c"},{"d","e"}};
    vector<double> values = {2.0,3.0,6.0,1.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    auto res = s.calcEquation(equations, values, queries);
    for (auto r : res) std::cout << r << " ";
    return 0;
}