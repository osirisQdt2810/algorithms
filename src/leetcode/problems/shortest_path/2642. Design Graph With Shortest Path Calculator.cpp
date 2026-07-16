#include <vector>
#include <iostream>

using namespace std;

/*
 * Problem: LC 2642 - Design Graph With Shortest Path Calculator (directed, non-negative weights).
 *
 * Best solution: Incremental Floyd-Warshall over an all-pairs shortest-path matrix.
 *   (For n <= 100 this is optimal; the alternative — store adjacency, run Dijkstra
 *    per query — is also accepted, trading O(1) query for O(1) addEdge.)
 *
 * Complexity:
 *   - Constructor : Time O(n^3) — one full Floyd-Warshall pass.  Space O(n^2) — the dist matrix.
 *   - addEdge     : Time O(n^2) — one relaxation pass over all (u,v) pairs through the new edge.
 *   - shortestPath: Time O(1)   — direct matrix lookup.
 *
 * Approach (detail):
 *   1. Keep an n x n matrix dist[u][v] = shortest u->v distance, init to oo, with
 *      dist[u][u] = 0 and dist[u][v] = w for each initial directed edge u->v.
 *   2. In the constructor run Floyd-Warshall once so dist holds the true all-pairs SP.
 *   3. addEdge(a, b, w): a new directed edge a->b can only improve dist[u][v] by being
 *      routed through exactly once, so for every pair set
 *         dist[u][v] = min(dist[u][v], dist[u][a] + w + dist[b][v]).
 *      One O(n^2) pass suffices — with non-negative weights an optimal path never needs
 *      to traverse the same edge twice (that would only add a non-negative cycle).
 *   4. shortestPath(x, y) returns dist[x][y], or -1 when it is still oo (unreachable).
 *
 * Why correct: after the constructor dist is exact. Treating the newly added edge as the
 * single new "intermediate hop" and relaxing all pairs through it restores exactness —
 * this is precisely one intermediate step of Floyd-Warshall, applied to an edge instead
 * of a vertex.
 */
class Graph {
    private:
        // using ll = long long;
        using ll = int;
        vector<vector<ll>> dist;
        static inline constexpr ll oo = 1e9;

    public:
        Graph(int n, vector<vector<int>>& edges) {
            dist.assign(n, vector<ll>(n, oo));
            for (auto& edge : edges){
                int u = edge[0], v = edge[1], w = edge[2];
                dist[u][v] = w;
            }

            for (int u = 0; u < n; ++u)
                dist[u][u] = 0;

            for (int k = 0; k < n; ++k){
                for (int u = 0; u < n; ++u){
                    for (int v = 0; v < n; ++v){
                        if (dist[u][k] == oo || dist[k][v] == oo) continue;
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }
        
        void addEdge(vector<int> edge) {
            int n = dist.size();
            int a = edge[0], b = edge[1], w = edge[2];
            for (int u = 0; u < n; ++u){
                for (int v = 0; v < n; ++v){
                    if (dist[u][a] != oo && dist[b][v] != oo)
                        dist[u][v] = min(dist[u][v], dist[u][a] + w + dist[b][v]);
                    // if (dist[v][a] != oo && dist[b][u] != oo)
                    //     dist[u][v] = min(dist[u][v], dist[v][a] + w + dist[b][u]);
                }
            }
        }
        
        int shortestPath(int node1, int node2) {
            return (dist[node1][node2] == oo) ? -1 : dist[node1][node2];
        }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    return 0;
}