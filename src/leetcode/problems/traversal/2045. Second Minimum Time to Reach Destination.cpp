#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * Best solution: modified BFS tracking the two smallest DISTINCT distances (in #edges) per node.
 *
 * Time:  O(V + E) — each node is enqueued at most twice (once for its shortest #edges, once for
 *                   its strictly-second-shortest), so every edge is relaxed O(1) amortized.
 * Space: O(V + E) — adjacency list + dist1[]/dist2[] arrays.
 *
 * Approach (detail):
 *  1. Every edge costs the same `time`, and traffic-light waiting depends only on the elapsed time,
 *     which in turn depends only on how many edges have been traversed. So a path's total arrival
 *     time is a strictly increasing function of its length in EDGES. Hence the SECOND-minimum
 *     arrival time corresponds to the second-smallest DISTINCT #edges on a 1 -> n path (call it k2),
 *     NOT to the second-best path itself.
 *  2. BFS from node 1. Maintain dist1[u] = fewest edges to reach u, and dist2[u] = fewest edges
 *     strictly greater than dist1[u]. When relaxing u -> v with cand = dist[u] + 1:
 *        - cand < dist1[v]              -> dist1[v] = cand, enqueue (v, cand)
 *        - dist1[v] < cand < dist2[v]   -> dist2[v] = cand, enqueue (v, cand)
 *     Since the graph is connected, dist2[n] is always dist1[n] + 1 or dist1[n] + 2.
 *  3. k2 = dist2[n]. Convert k2 hops into elapsed time with the traffic lights: before each hop, if
 *     floor(curr / change) is odd the light is RED, so wait for the next green
 *     (curr = (curr / change + 1) * change); then curr += time.
 */
class Solution {
    private:
        using ii = pair<int, int>;

        int elapse(int curr_time, int time, int change){
            int div = curr_time / change;    // even: green, odd: red
            int sign = div % 2;
            return (sign) ? (div + 1) * change + time : curr_time + time;
        }

        ii shortest_path(vector<vector<int>>& adj, int source, int target, int time, int change){
            vector<bool> visited(adj.size(), false);
            queue<int> q;
            visited[source] = true;
            q.push(source);
            int depth = 0, curr_time = 0;
            while (!q.empty()){
                ++depth;
                curr_time = elapse(curr_time, time, change);
                int len = q.size();
                for (int i = 0; i < len; ++i){
                    int u = q.front(); q.pop();
                    if (u == target) return {depth, curr_time};
                    for (auto& v : adj[u]){
                        if (visited[v]) continue;
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            return {-1, -1};
        }

        bool has_path(vector<vector<int>>& adj, int source, int target, int max_depth) {
            int target_steps = max_depth - 1; 
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(adj.size(), vector<bool>(target_steps + 1, false));
            
            q.push({source, 0});
            visited[source][0] = true;
            
            while (!q.empty()) {
                auto [u, steps] = q.front(); 
                q.pop();
                
                if (u == target && steps == target_steps) {
                    return true;
                }
                
                if (steps < target_steps) {
                    for (auto& v : adj[u]) {
                        int next_steps = steps + 1;
                        if (!visited[v][next_steps]) {
                            visited[v][next_steps] = true;
                            q.push({v, next_steps});
                        }
                    }
                }
            }
            return false;
        }
    public:
        int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
            vector<vector<int>> adj(n+1);
            for (auto& edge : edges){
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            
            const int INF = 1e9;
            using ii = pair<int, int>;
            vector<vector<int>> dist(n+1, vector<int>(2, INF)); // dist[u][0]: đường đi ngắn nhất từ 1->u qua X cạnh, X chẵn
                                                                // dist[u][1]: đường đi ngắn nhất từ 1->u qua Y cạnh, Y lẻ
            dist[1][0] = 0;
            dist[1][1] = INF;
            queue<ii> q;
            q.push({1, 0});
            while (!q.empty()){
                auto [u, step] = q.front(); q.pop();

                for (auto v : adj[u]){
                    int next_step = step + 1;
                    if (next_step < dist[v][next_step % 2]){
                        dist[v][next_step % 2] = next_step;
                        q.push({v, next_step});
                    }
                }
            }

            int min_step = min(dist[n][0], dist[n][1]);
            int max_step = max(dist[n][0], dist[n][1]);
            int steps = min(min_step + 2, max_step);
            cout << min_step << " " << max_step << "\n";
            int curr_time = 0;
            for (int i = 1; i <= steps; ++i){
                curr_time = elapse(curr_time, time, change);
            }
            return curr_time;
        }

        int secondMinimum2(int n, vector<vector<int>>& edges, int time, int change) {
            vector<vector<int>> adj(n+1);
            for (auto& edge : edges){
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            auto [min_depth, curr_time] = shortest_path(adj, 1, n, time, change);
            cout << min_depth << " " << curr_time << "\n";
            if (!has_path(adj, 1, n, min_depth+1)){
                curr_time = elapse(curr_time, time, change);
            }
            return curr_time;
        }
};