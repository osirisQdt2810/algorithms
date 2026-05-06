// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cmath>

#include "topics/graph/lowest_common_ancestor.hpp"

using namespace std;

using Vertex = int;
using Weight = long long;
using WeightNeighbor = pair<Vertex, Weight>;
static constexpr Weight kNil = std::numeric_limits<Weight>::lowest();

struct Edge {
    int i;
    Vertex u, v;
    Weight w;
};

vector<vector<WeightNeighbor>> adj;
vector<Edge> edges;

struct DisjointSetUnion {
    vector<int> par;

    DisjointSetUnion(int n){ par.assign(n, -1); }

    int root(int u){ return (par[u] < 0) ? u : (par[u] = root(par[u])); }

    bool do_union(int u, int v){
        int root_u = root(u);
        int root_v = root(v);
        if (root_u == root_v) return false;
        par[root_v] += par[root_u];
        par[root_u] = root_v;
        return true;
    }
};

struct LCA {

    vector<vector<Vertex>> up;          // up[u][j]: 2^j-th parent of u, 0 <= j <= L
    vector<vector<Weight>> max_dist;    // max_dist[u][j]: max(edge) in the path u -> up[u][j]
    vector<int> nodes;                  // nodes[u]: number of nodes in path: root -> u (u included)
    vector<int> t_in, t_out;

    int V;
    int L;
    int root;
    int timer{0};

    void _dfs(int u, int p, Weight w){
        // visit[u], where p is the parent of u
        t_in[u] = timer++;
        up[u][0] = p;
        max_dist[u][0] = w;
        nodes[u] = nodes[p] + 1;
        for (int j = 1; j <= L; ++j){
            up[u][j] = up[up[u][j-1]][j-1];
            max_dist[u][j] = max(max_dist[u][j-1], max_dist[up[u][j-1]][j-1]);
        }

        for (auto& [v, w] : adj[u]){
            if (v == p) continue; // avoid to traverse p -> u -> p
            _dfs(v, u, w);
        }

        // leave[u]
        t_out[u] = timer++;
    }

    void init(){
        t_in.assign(V, 0);
        t_out.assign(V, 0);
        up.assign(V, vector<Vertex>(L + 1));
        max_dist.assign(V, vector<Weight>(L + 1, kNil));
        nodes.assign(V, 0);
        _dfs(root, root, 0);
    }

    bool is_ancestor(int u, int v){
        return (t_in[u] <= t_in[v] && t_out[v] <= t_out[u]);
    }

    int get_bit(int n, int i){
        return (n >> i) & 1;
    }

    virtual Weight max_distance(Vertex u, Vertex v){
        Weight res = kNil;
        if (is_ancestor(v, u)) std::swap(v, u);
        if (is_ancestor(u, v)){
            int jump = nodes[v] - nodes[u];
            // we need to jump `jump` nodes from v to u
            // `jump` = x1x2...xn => only jump x[j] with x[j] = 1
            // cout << get_bit(3, 0);
            for (int j = 0; j <= L; ++j){
                if (get_bit(jump, j)){
                    res = std::max(res, max_dist[v][j]);
                    v = up[v][j];
                }
            }
            return res;
        }

        for (int j = L; j >= 0; --j){
            if (!is_ancestor(up[u][j], v)){
                res = std::max(res, max_dist[u][j]);
                u = up[u][j];
            }
        }
        res = std::max(res, max_dist[u][0]);
        res = std::max(res, max_distance(up[u][0], v));
        return res;
    }

    LCA(int n_, Vertex root_ = 0) 
        : V(n_), L(floor(log2(n_))), root(root_){
        init();
    }
};

struct OrthodoxLCA {
    vector<vector<Vertex>> up;
    vector<vector<Weight>> max_dist;
    vector<int> height;

    int V, L, root;

    void _dfs(int u, int p, Weight w){
        height[u] = height[p] + 1;
        up[u][0] = p;
        max_dist[u][0] = w;
        for (int j = 1; j <= L; ++j){
            up[u][j] = up[up[u][j-1]][j-1];
            max_dist[u][j] = max(max_dist[u][j-1], max_dist[up[u][j-1]][j-1]);
        }
        for (auto& [v, w] : adj[u]){
            if (v == p) continue;
            _dfs(v, u, w);
        }
    }

    void init(){
        height.assign(V, -1);
        up.assign(V, vector<Vertex>(L + 1, -1));
        max_dist.assign(V, vector<Weight>(L + 1, kNil));
        _dfs(root, root, 0);
    }

    int get_bit(int n, int i){
        return (n >> i) & 1;
    }

    Weight max_distance(Vertex u, Vertex v){
        // if (h[u] != h[v]) => jump u/v so that they are on the same height
        Weight res = kNil;
        // cout << "1. " << u << " " << v << " " << " -> height = " << height[u] << " " << height[v] << " -> " << res << "\n";
        if (height[u] != height[v]){    // (1, 0) -> h(4, 1)
            if (height[u] < height[v]) std::swap(u, v); // (0, 1) -> h(1, 4)
            // jump u -> u' where height[u'] = height[v]
            int jump = height[u] - height[v];   // 3
            for (int j = 0; j <= L; ++j){
                // cout << jump << " -> j = " << j << " -> " << get_bit(jump, j) << " -> dist = " << max_dist[] "\n";
                if (get_bit(jump, j)){
                    res = max(res, max_dist[u][j]);
                    u = up[u][j];
                }
            }
        }
        // cout << "2. " << u << " " << v << " " << " -> height = " << height[u] << " " << height[v] << " -> " << res << "\n";
        if (u == v) return res;
        // u and v are on the same height => lift binarily both of them until they reach their target u' and v',
        // which are the last node satisfying u' != v'
        // There, parent[u'] = parent[v'] = lca
        for (int j = L; j >= 0; --j){
            // cout << "-> j = " << j << " | "  << u << " " << v << " " << " | up: " << up[u][j] << " " << up[v][j] << "\n";
            if (up[u][j] != up[v][j]){
                res = max(res, max_dist[u][j]);
                res = max(res, max_dist[v][j]);
                u = up[u][j];
                v = up[v][j];
            }
        }
        res = max(res, max_dist[v][0]);
        res = max(res, max_dist[u][0]);
        // cout << "3. " << u << " " << v << " " << " -> height = " << height[u] << " " << height[v] << " -> " << res << "\n";
        return res;
    }

    OrthodoxLCA(int n_, Vertex root_ = 0) : V(n_), L(ceil(log2(n_))), root(root_){
        init();
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;
    for (int u, v, i = 0; i < m; ++i){
        Weight w;
        cin >> u >> v >> w;
        edges.push_back({i, u - 1, v - 1, w});
    }

    std::sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs){ return lhs.w < rhs.w; });
    adj.resize(n);

    DisjointSetUnion dsu(n);
    Weight mst = 0;
    int cnt_edge = 0;
    vector<bool> in_mst(m, false);

    for (int i = 0; i < m; ++i){
        auto& edge = edges[i];
        if (cnt_edge == n - 1) break;
        if (dsu.do_union(edge.u, edge.v)){
            in_mst[i] = true;
            cnt_edge++;
            mst += edge.w;
            adj[edge.u].push_back({edge.v, edge.w});
            adj[edge.v].push_back({edge.u, edge.w});
        }
    }
    
    dsa::graph::WeightedGraph<Weight> graph;
    graph.V = n;
    graph.E = n - 1;
    graph.adj.resize(n);
    for (int u = 0; u < n; ++u){
        for (auto& [v, w] : adj[u]){
            graph.adj[u].push_back({v, w});
        }
    }

    // LCA lca(n, 0);
    // OrthodoxLCA lca(n, 0);
    // dsa::graph::LCAWithMaxEdge<Weight> lca(graph, dsa::graph::Vertex(0));
    dsa::graph::GenericLCAWithEulerTime<Weight, dsa::graph::maxops<Weight>> lcae(graph, dsa::graph::Vertex(0));
    vector<Weight> res(m, mst);
    for (int i = 0; i < m; ++i){
        auto& edge = edges[i];
        if (in_mst[i]) continue;
        res[edge.i] = mst + edge.w - lcae.distance(edge.u, edge.v);
    }
    for (int i = 0; i < m; ++i)
        cout << res[i] << "\n";

    return 0;
}