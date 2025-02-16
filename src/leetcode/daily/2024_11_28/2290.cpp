#include <bits/stdc++.h>
#include <deque>

using namespace std;

typedef pair<int, int> ii;
#define MAX_WEIGHT INT_MAX
typedef int Weight;

typedef pair<int, Weight> VW;
typedef vector<int> Path;
typedef vector<vector<Weight>> WeightMatrix;

struct Edge {
    int u, v;
    Weight w;

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "(" << edge.u << ", " << edge.v << ", " << edge.w << ")";
        return os;
    }

    bool operator==(const Edge& other) const {
        return (
            (u == other.u && v == other.v && w == other.w) ||
            (u == other.v && v == other.u && w == other.w)
        );
    }
};

struct EdgeHash {
    std::size_t operator()(const Edge& edge) const {
        int min_uv = min(edge.u, edge.v);
        int max_uv = max(edge.u, edge.v);
        return hash<int>()(min_uv) ^ hash<int>()(max_uv);
    }
};

struct Graph {
    int V, E;
    vector<Edge> edges;
    vector<vector<VW>> adj;
    WeightMatrix mat;
};

struct BipartiteGraph {
    int V1, V2;                 // first-part: 0...V1-1, second-part: 0...V2-1
    int E;
    vector<vector<VW>> adj;     // adj[u]: list of vertices v in V2 where edge u-v is present
    WeightMatrix mat;           
};

struct UnionFind {
    std::vector<int> parents;

    UnionFind(int V){
        parents.resize(V);
        for (int i = 0; i < V; ++i)
            parents[i] = i;
    }

    int find_root(int u){
        return (parents[u] == u) ? u : (parents[u] = find_root(parents[u]));
    }

    bool in_union(int u, int v){
        int root_u = find_root(u);
        int root_v = find_root(v);
        return (root_u == root_v);
    }

    bool do_union(int u, int v){
        int root_u = find_root(u);
        int root_v = find_root(v);
        if (root_u == root_v) return false;
        parents[root_u] = root_v;
        return true;
    }
};

struct AdvanceUnionFind {
    std::vector<int> parents;

    AdvanceUnionFind(int V){
        parents.resize(V);
        for (int i = 0; i < V; ++i)
            parents[i] = -1;
    }

    int find_root(int u){
        return (parents[u] < 0) ? u : (parents[u] = find_root(parents[u]));
    }

    bool in_union(int u, int v){
        int root_u = find_root(u);
        int root_v = find_root(v);
        return (root_u == root_v);
    }

    bool do_union(int u, int v){
        int root_u = find_root(u);
        int root_v = find_root(v);
        if (root_u == root_v) return false;
        parents[root_u] = root_v;
        parents[root_v] += parents[root_u];
        return true;
    }

    int num_components(){
        int num = 0;
        for (auto& par : parents)
            num += (par < 0);
        return num;
    }

    int num_points_with_vertex(int u){
        int root_u = find_root(u);
        return -parents[root_u];
    }
};

struct MST {
    vector<Edge> edges;
    Weight mst{0};

    friend std::ostream& operator<<(std::ostream& os, const MST& mst) {
        std::cout <<  "MST: " << mst.mst << ": ";
        for (auto e : mst.edges){
            std::cout << e << " ";
        }
        std::cout << "\n";
        return os;
    }    
};

struct ShortestPath {
    bool trace;
    vector<Path> paths;
    vector<Weight> shortests;

    ShortestPath(int V, bool trace = false) : trace(trace){
        shortests.resize(V);
        if (trace) paths.resize(V);
        for (int i = 0; i < V; ++i){
            shortests[i] = MAX_WEIGHT;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ShortestPath& sp) {
        for (size_t u = 0; u < sp.shortests.size(); ++u){
            std::cout << "ShortestPath: " << sp.shortests[u] << ": (";
            if (sp.trace){
                auto& path = sp.paths[u];
                for (size_t i = 0; i < path.size(); ++i){
                    std::cout << path[i];
                    if (i != path.size() - 1) std::cout << " -> ";
                }        
            }
            std::cout << ")\n";

        }
        return os;
    }    
};

struct BipartiteMatches {
    int matches{0};
    Weight cost{-1};
    vector<int> matching;  // matching[v] = u, where v is the vertex in V2, u is the vertex in V1)
};
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
class ShortestPathFinder {
    private:
        static inline void trace(vector<int>& p, vector<int>& neighbor, int src, int dst){
            if (src == dst){
                p.push_back(src);
                return;
            }
            trace(p, neighbor, src, neighbor[dst]);
            p.push_back(dst);
        }

    public:
        /**
         * @note: Using g.adj => O(V*E)
         */
        static inline ShortestPath bellman_ford(const Graph& g, int src){        // Use g.adj: O(V*E)
            vector<Weight> dist(g.V, MAX_WEIGHT);
            dist[src] = 0;

            ShortestPath sp(g.V);
            for (int iter = 0; iter < g.V; ++iter){
                for (int u = 0; u < g.V; ++u){
                    for (const auto& [v, w] : g.adj[u]){
                        if (dist[u] != MAX_WEIGHT)
                            dist[v] = min(dist[v], dist[u] + w);
                    }
                }
            }
            sp.shortests = std::move(dist);
            return sp;
        }

        /**
         * @note: Using g.mat => O(V^3)
         * @warning:
         *     1. g.mat[i][j] = 0           if (i == j)
         *     2. g.mat[i][j] = WEIGHT_MAX  if dont have edge (i -> j)
         */
        static inline WeightMatrix floyd_warshall(const Graph& g){
            WeightMatrix dist = g.mat;
            for (int k = 0; k < g.V; ++k){
                for (int i = 0; i < g.V; ++i){
                    for (int j = 0; j < g.V; ++j){
                        if (dist[i][k] != MAX_WEIGHT && dist[k][j] != MAX_WEIGHT){
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
            return dist;
        }

        /**
         * @note: Using g.adj => O((E + V) logV)
         * 
         */
        static inline ShortestPath dijikstra(const Graph& g, int src, int dst = -1, bool trace = false){      // O((E+V)logV)
            auto cmp = [](const VW& lhs, const VW& rhs){ return lhs.second > rhs.second; }; // min-heap
            priority_queue<VW, vector<VW>, decltype(cmp)> pq(cmp);
            vector<Weight> dist(g.V, MAX_WEIGHT);
            vector<int> neighbor(g.V, -1);

            dist[src] = 0;
            pq.push({src, dist[src]});
            neighbor[src] = src;
            
            ShortestPath res(g.V, trace);
            while (!pq.empty()){
                // get current best vertex
                auto [u, du] = pq.top(); pq.pop();
                if (dist[u] != du) continue;

                // assign to result
                res.shortests[u] = du;
                if (trace) ShortestPathFinder::trace(res.paths[u], neighbor, src, u);

                // stop if meets target vertex
                if (dst == u) break;

                // update neighbor vertex
                for (const auto& [v, w] : g.adj[u]){
                    if (dist[v] > dist[u] + w){
                        dist[v] = dist[u] + w;
                        neighbor[v] = u;
                        pq.push({v, dist[v]});
                    }
                }
            }
            return res;
        }

        static inline ShortestPath BFS0_1(const Graph& g, int src, int dst = -1){   // O(E)
            deque<int> queue;
            vector<Weight> dist(g.V, MAX_WEIGHT);
            dist[src] = 0;
            queue.push_front(src);

            ShortestPath res(g.V, false);

            while (!queue.empty()){
                auto u = queue.front(); queue.pop_front();
                for (const auto& [v, w] : g.adj[u]){
                    if (dist[v] > dist[u] + w){
                        dist[v] = dist[u] + w;
                        if (w == 1){
                            queue.push_back(v);
                        }
                        else {
                            queue.push_front(v);
                        }
                    }
                }
            }
            for (int u = 0; u < g.V; ++u)
                res.shortests[u] = dist[u];
            return res;
        }
};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        Graph g;
        int m = grid.size(), n = grid[0].size();
        g.V = m * n;
        g.adj.assign(g.V, std::vector<VW>());
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                int p = i * n + j;
                int l = i * n + (j - 1);
                int t = (i - 1) * n + j;
                int r = i * n + (j + 1);
                int b = (i + 1) * n + j;

                if (i >= 1){
                    g.adj[p].push_back(ii(t, grid[i-1][j]));
                }
                if (j >= 1){
                    g.adj[p].push_back(ii(l, grid[i][j-1]));
                }
                if (i + 1 < m){
                    g.adj[p].push_back(ii(b, grid[i+1][j]));
                }
                if (j + 1 < n){
                    g.adj[p].push_back(ii(r, grid[i][j+1]));
                }                    
            }
        }

        // auto res = ShortestPathFinder::BFS0_1(g, 0, m * n - 1);
        auto res = ShortestPathFinder::dijikstra(g, 0, m * n - 1);
        int shortest = res.shortests[m * n - 1];
        // cout << "shortest = " << shortest << "\n";

        return (shortest == 0) ? 0 : (shortest - 1);
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

    vector<vector<int>> grids = {{0,1,1},{1,1,0},{1,1,0}};
    // vector<vector<int>> grids = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout << s.minimumObstacles(grids);

    return 0;
}