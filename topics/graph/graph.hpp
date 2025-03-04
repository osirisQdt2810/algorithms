#include <bits/stdc++.h>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////// STRUCT DEFINITION ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

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
        parents[root_v] += parents[root_u];
        parents[root_u] = root_v;
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
};

class MSTFinder {
    public:
        /**
         * @note: Using g.edges => O(ElogE) 
         */
        static inline MST kruskal(Graph& g, bool trace = false){        // O(ElogE)
            UnionFind uf(g.V);
            sort(g.edges.begin(), g.edges.end(), [](const Edge& lhs, const Edge& rhs){
                return lhs.w < rhs.w;
            });

            MST res;
            for (auto& edge : g.edges){
                if (static_cast<int>(res.edges.size()) == g.V - 1)
                    break;
                
                int u = edge.u, v = edge.v, w = edge.w;
                if (uf.do_union(u, v)){
                    res.mst += w;
                    if (trace) res.edges.push_back(edge);
                }
            }
            return res;
        }  

        static inline MST prim(const Graph& g, bool trace = false){   // O(E+V)logV
            auto compare = [](const VW& lhs, const VW& rhs){ return lhs.second > rhs.second; };   // min-heap
            priority_queue<VW, vector<VW>, decltype(compare)> pq(compare);

            vector<Weight> dist(g.V, MAX_WEIGHT);
            vector<int> neighbor(g.V, -1);

            int s = 0; dist[s] = 0;
            pq.push({s, dist[s]});

            MST res;
            while (!pq.empty()){
                // get current best vertex
                auto [u, du] = pq.top(); pq.pop();
                if (dist[u] != du) continue;

                // assign to result
                if (u != s){
                    res.mst += du;
                    dist[u] = 0;
                    if (trace){
                        res.edges.push_back({neighbor[u], u, du});
                    }
                }

                // update neighbor vertex
                for (const auto& [v, w] : g.adj[u]){
                    if (dist[v] > w){
                        dist[v] = w;
                        neighbor[v] = u;
                        pq.push({v, dist[v]});
                    }
                }
            }
            return res;
        }
};

class Searcher {
    private:
        static inline int num_low_counter = 0;

    private:
        static inline void find_bridges(
            const Graph& g, vector<Edge>& bridges, set<int>& cut_points,
            vector<int>& num, vector<int>& low, int u, int p
        ){
            num[u] = low[u] = num_low_counter++;
            int children = 0;
            for (const auto& [v, w] : g.adj[u]){
                if (v == p) continue;
                if (num[v] == -1){
                    find_bridges(g, bridges, cut_points, num, low, v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] >= num[u] && p != -1){
                        cut_points.insert(u);
                    }
                    ++children;
                }
                else {
                    low[u] = min(low[u], num[v]);
                }
                if (low[v] > num[u]){
                    bridges.push_back({u, v, w});
                }                
            }

            if (p == -1 && children > 1){
                cut_points.insert(u);
            }
        }

        // Cycle Detection in Undirected Graph using DFS
        static inline bool isCyclicDFS(
            int u, int p, const Graph& g, vector<bool>& visited
        ){
            visited[u] = true;
            for (const auto& [v, w] : g.adj[u]) {
                if (!visited[v]) {
                    if (isCyclicDFS(v, u, g, visited)) {
                        return true;
                    }
                } else if (v != p) {
                    return true;
                }
            }
            return false;
        }

        // Cycle Detection in Directed Graph using DFS
        static inline bool isCyclicDFSDirected(
            int u, const Graph& g, 
            vector<bool>& visited, vector<bool>& recStack
        ){
            visited[u] = true;
            recStack[u] = true;
            for (const auto& [v, w] : g.adj[u]) {
                if (!visited[v] && isCyclicDFSDirected(v, g, visited, recStack)) {
                    return true;
                } else if (recStack[v]) {
                    return true;
                }
            }
            recStack[u] = false;
            return false;
        }

    public:
        /**
         * @note Using g.adj O(V+E)
         */
        static inline void bfs(const Graph& g, int start){
            queue<int> q;
            vector<bool> visited(g.V, false);
            q.push(start);
            visited[start] = true;

            while (!q.empty()){
                int u = q.front(); q.pop();
                cout << "Node: " << u << " has been visited!\n";

                for (const auto& [v, w] : g.adj[u]){
                    if (!visited[v]){
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }

        /**
         * @note Using g.adj
         * @warning initialize `vector<bool> visited(g.V, false) first`; O(V+E)
         */
        static inline void dfs(const Graph& g, vector<bool>& visited, int u){
            if (visited[u]) return;

            visited[u] = true;
            std::cout << "Node: " << u << " has been visited!\n";

            for (const auto& [v, w] : g.adj[u]){
                dfs(g, visited, v);
            }
        }

        /**
         * @note Using g.adj
         */
        static inline bool isBipartite(const Graph& g){
            vector<int> color(g.V, -1);

            for (int i = 0; i < g.V; ++i){
                if (color[i] == -1){
                    color[i] = 0;
                    queue<int> q;
                    q.push(i);

                    while (!q.empty()){
                        int u = q.front(); q.pop();
                        for (const auto& [v, w]: g.adj[u]){
                            if (color[v] == -1){
                                color[v] = 1 - color[u];
                                q.push(v);
                            }
                            else if (color[v] == color[u]) {
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }

        static inline pair<vector<Edge>, set<int>> tarjan(const Graph& g){
            vector<int> num(g.V, -1);
            vector<int> low(g.V, -1);
            vector<Edge> bridges;
            set<int> cut_points;

            for (int u = 0; u < g.V; ++u){
                if (num[u] == -1){
                    find_bridges(g, bridges, cut_points, num, low, u, -1);
                }
            }
            return {std::move(bridges), std::move(cut_points)};      
        }

        static inline bool hasCycleDirected(const Graph& g){
            vector<bool> visited(g.V, false);
            vector<bool> recStack(g.V, false);

            for (int u = 0; u < g.V; u++) {
                if (!visited[u]) {
                    if (isCyclicDFSDirected(u, g, visited, recStack)) {
                        return true;
                    }
                }
            }
            return false;
        }

        static inline bool hasCycleUndirected(const Graph& g) {
            vector<bool> visited(g.V, false);

            for (int u = 0; u < g.V; u++) {
                if (!visited[u]) {
                    if (isCyclicDFS(u, -1, g, visited)) {
                        return true;
                    }
                }
            }
            return false;
        }        
};

struct Topology {

    /**
     * @note topology search in BFS => Using g.adj
     */
    static inline Path topo_bfs(const Graph& g){
        vector<int> inDegree(g.V, 0);
        for (int u = 0; u < g.V; ++u){
            for (const auto& [v, w]: g.adj[u]){
                inDegree[v]++;
            }
        }

        queue<int> source_nodes;
        for (int u = 0; u < g.V; ++u){
            if (inDegree[u] == 0){
                source_nodes.push(u);
            }
        }

        Path topo;
        while (!source_nodes.empty()){
            int u = source_nodes.front(); source_nodes.pop();
            topo.push_back(u);
            for (const auto& [v, w] : g.adj[u]){
                inDegree[v]--;
                if (inDegree[v] == 0){
                    source_nodes.push(v);
                }
            }
        }
        return topo;
    }
};

class BipartiteMatching {
    private:
        static inline const int NIL = 0;
        static inline const int INF = MAX_WEIGHT;

        /**
         * @brief DFS to update the augmenting path from vertex u in V1
         */
        static inline bool try_kuhn(const BipartiteGraph& g, vector<bool>& visited, vector<int>& mt, int u){
            if (visited[u]) return false;
            visited[u] = true;

            for (const auto& [v, w] : g.adj[u]){
                if (mt[v] == -1 || try_kuhn(g, visited, mt, mt[v])){       // if v is a unsaturated vertex, so v is the end of 
                    mt[v] = u;
                    return true;
                }
            }
            return false;
        }

        static inline bool hopcroft_bfs(const BipartiteGraph& g, int* pairU, int* pairV, int* dist){
            queue<int> Q;
            for (int u = 1; u <= g.V1; ++u){
                if (pairU[u] == NIL){
                    dist[u] = 0;
                    Q.push(u);
                }
                else {
                    dist[u] = INF;
                }
            }

            dist[NIL] = INF;
            while (!Q.empty()){
                int u = Q.front(); Q.pop();
                if (dist[u] < dist[NIL]){
                    for (const auto& [v, w] : g.adj[u - 1]){
                        if (dist[pairV[v + 1]] == INF){
                            dist[pairV[v + 1]] = dist[u] + 1;
                            Q.push(pairV[v + 1]);
                        }
                    }
                }
            }
            return (dist[NIL] != INF);
        }

        static inline bool hopcroft_dfs(const BipartiteGraph& g, int* pairU, int* pairV, int* dist, int u){
            if (u != NIL){
                for (const auto& [v, w] : g.adj[u - 1]){
                    if (dist[pairV[v + 1]] == dist[u] + 1 && hopcroft_dfs(g, pairU, pairV, dist, pairV[v + 1])){
                        pairV[v + 1] = u;
                        pairU[u] = v + 1;
                        return true;
                    }
                }
                dist[u] = INF;
                return false;
            }
            return true;
        }

    public:
        static inline BipartiteMatches kuhn(const BipartiteGraph& g, bool trace = false){
            vector<bool> visited;
            vector<int> mt; mt.assign(g.V2, -1);

            // for each vertex u in V1, we tried to find the augmenting path from u
            BipartiteMatches res;
            for (int u = 0; u < g.V1; ++u){
                visited.assign(g.V1, false);            // reset state of visited for each vertex in V1
                if (try_kuhn(g, visited, mt, u)){
                    res.matches++;
                }
            }
            if (trace){
                res.matching = std::move(mt);
            }
            return res;
        }

        static inline BipartiteMatches kuhn_heuristic(const BipartiteGraph& g, bool trace = false){
            vector<bool> visited;
            vector<int> mt; mt.assign(g.V2, -1);

            // do the heuristic to get the easiest maximum matching
            vector<bool> hasAugmented; hasAugmented.assign(g.V1, false);
            for (int u = 0; u < g.V1; ++u){
                for (const auto& [v, w] : g.adj[u]){
                    if (mt[v] != -1){
                        mt[v] = u;
                        hasAugmented[u] = true;
                        break;
                    }
                }
            }

            // for each vertex u in V1 (not augmented), we tried to find the augmenting path from u
            BipartiteMatches res;
            for (int u = 0; u < g.V1; ++u){
                if (hasAugmented[u]){
                    res.matches++;
                    continue;
                }
                visited.assign(g.V1, false);
                if (try_kuhn(g, visited, mt, u)){
                    res.matches++;
                }
            }
            if (trace){
                res.matching = std::move(mt);
            }            
            return res;            
        }

        static inline BipartiteMatches hopcroft_karp(const BipartiteGraph& g, bool trace = false){       // O(sqrt(V) * E)
            int* pairU = new int[static_cast<size_t>(g.V1 + 1)];
            int* pairV = new int[static_cast<size_t>(g.V2 + 1)];
            int* dist  = new int[static_cast<size_t>(g.V1 + 1)];

            for (int u = 0; u <= g.V1; ++u) pairU[u] = NIL;
            for (int v = 0; v <= g.V2; ++v) pairV[v] = NIL;

            BipartiteMatches res;
            while (hopcroft_bfs(g, pairU, pairV, dist)){
                for (int u = 1; u <= g.V1; ++u){
                    if (pairU[u] == NIL && hopcroft_dfs(g, pairU, pairV, dist, u)){
                        res.matches++;
                    }
                }
            }

            if (trace){
                for (int v = 1; v <= g.V2; v++){
                    res.matching.push_back((pairV[v] == NIL) ? -1 : pairV[v] - 1);
                }
            }

            delete[] pairU;
            delete[] pairV;
            delete[] dist;
            return res;
        }   

        static inline BipartiteMatches hungarian_matching(const BipartiteGraph& g){
            WeightMatrix A = g.mat;
            int n = g.V1, m = g.V2;
            if (n == 0 || m == 0) return BipartiteMatches();
            vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
            for (int i=1; i<=n; ++i) {
                p[0] = i;
                int j0 = 0;
                vector<int> minv (m+1, INF);
                vector<bool> used (m+1, false);
                do {
                    used[j0] = true;
                    int i0 = p[j0],  delta = INF,  j1;
                    for (int j=1; j<=m; ++j)
                        if (!used[j]) {
                            int cur = A[i0 - 1][j - 1]-u[i0]-v[j];
                            if (cur < minv[j])
                                minv[j] = cur,  way[j] = j0;
                            if (minv[j] < delta)
                                delta = minv[j],  j1 = j;
                        }
                    for (int j=0; j<=m; ++j)
                        if (used[j])
                            u[p[j]] += delta,  v[j] -= delta;
                        else
                            minv[j] -= delta;
                    j0 = j1;
                } while (p[j0] != 0);
                do {
                    int j1 = way[j0];
                    p[j0] = p[j1];
                    j0 = j1;
                } while (j0);
            }

            BipartiteMatches res;
            res.matches = min(m, n);
            res.cost = -v[0];
            for (int j = 1; j <= m; j++)
                res.matching.push_back(p[j] - 1);
            return res;
        } 
};

class LCA {
    private:
        const Graph& tree;
        int root;
        int logFarthestAncestor; 
        
        vector<int> par, h;
        vector<Weight> dist;    // dist[u] = distance from root->u
        vector<vector<int>> up;


    private:
        void init(){
            assert(tree.V > 0);
            dist.assign(tree.V, -1); dist[root] = 0;
            par.assign(tree.V, -1); par[root] = -1;
            h.assign(tree.V, -1); h[root] = 0;
            up.resize(tree.V);
            for (int u = 0; u < tree.V; ++u) 
                up[u].assign(logFarthestAncestor, -1);
        }

        // O(V + E)
        void dfs(int u){
            for (const auto& [v, w] : tree.adj[u]){
                if (v == par[u]) continue;
                h[v] = h[u] + 1;
                dist[v] = dist[u] + w;
                par[v] = u;
                dfs(v);
            }
        }

        // O(VlogV)
        void preprocess(){
            for (int u = 0; u < tree.V; ++u) up[u][0] = par[u];
            for (int j = 1; j < logFarthestAncestor; ++j)
                for (int u = 0; u < tree.V; ++u)
                    up[u][j] = (up[u][j-1] == -1) ? -1 : up[up[u][j-1]][j-1];
        }

    public:
        LCA(const Graph& tree, int root = 0) 
            : tree(tree), root(root), logFarthestAncestor(static_cast<int>(__lg(tree.V) + 1)){
            init();
            dfs(root);
            preprocess();    
        }

        // O(logN)
        int lca(int u, int v){
            if (h[u] != h[v]){
                if (h[u] < h[v]) swap(u, v);    // => h[u] > h[v]
                // jump k = h[u] - h[v] steps from u
                int k = h[u] - h[v];
                for (int j = 0; (1 << j) <= k; ++j){
                    if (k >> j & 1) u = up[u][j];
                }
            }
            // std::cout << "u = " << u << ", v = " << v << " - h = " << h[u] << "\n";
            if (u == v) return u;

            // jump to the farthest ancestor of (u and v), where ancestor[u] != ancestor[v]
            int k = __lg(h[u]);
            for (int j = k; j >= 0; --j){
                if (up[u][j] != up[v][j]){
                    u = up[u][j];
                    v = up[v][j];
                }
            }
            return up[u][0];
        }

        // O(logN)
        Weight distance(int u, int v){
            int ancestor = lca(u, v);
            return dist[u] + dist[v] - 2 * dist[ancestor];
        }
};