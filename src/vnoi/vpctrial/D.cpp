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

    public:
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
};

// return e in A but not in B.
vector<Edge> difference(const vector<Edge>& A, const vector<Edge>& B){
    unordered_set<Edge, EdgeHash> setB(B.begin(), B.end()); // O(mlogM);
    vector<Edge> edges;

    for (const auto& a : A){                // O(n)
        if (setB.find(a) == setB.end()){    // O(1)
            edges.push_back(a);
        }
    }

    return edges;
}

Graph build_cc_tree(const Graph& g, const vector<Edge>& newEdges, const vector<Edge>& bridges){
    UnionFind uf(g.V);
    for (const auto& e : newEdges) uf.do_union(e.u, e.v);

    Graph tree; tree.V = 0;
    vector<int> node2tree(g.V, -1);
    for (int u = 0; u < g.V; ++u){
        if (uf.parents[u] == u){
            node2tree[u] = tree.V++;
        }
    }

    for (int u = 0; u < g.V; ++u){
        int root_u = uf.find_root(u);
        if (u != root_u){
            node2tree[u] = node2tree[root_u];
        }
    }
    // for (int u = 0; u < g.V; u++){
    //     std::cout << node2tree[u] << " ";
    // }

    vector<vector<bool>> visited; visited.resize(tree.V);
    for (int u = 0; u < tree.V; ++u) visited[u].assign(tree.V, false);
    tree.adj.resize(tree.V);

    for (auto& bridge : bridges){
        int u = bridge.u, v = bridge.v;
        int tree_u = node2tree[u], tree_v = node2tree[v];
        // std::cout << "u = " << u << ", v = " << v << ", tree_u = " << tree_u << ", tree_v = " << tree_v << "\n";
        if (visited[tree_u][tree_v] == false){
            visited[tree_u][tree_v] = visited[tree_v][tree_u] = true;
            tree.adj[tree_u].push_back({tree_v, 0});
            tree.adj[tree_v].push_back({tree_u, 0});
        }
    }
    return tree;
}

/**
* @brief Ý tưởng:
* @note 1 đồ thị liên thông chính là 1 cây, trong đó mỗi cạnh là 1 cầu, mỗi đỉnh là tập tplt (1).
* =>    Bài toán đặt ra là “Thêm số cạnh ít nhất sao cho xóa đi bất kỳ 1 cạnh nào đó thì đồ thị vẫn còn liên thông, thì rõ ràng tương đương bài toán thêm số cạnh ít nhất sao cho đồ thị không còn cầu (vì xóa cầu đi thì đồ thị mất tính lt).
*       Do đó nếu chuyển miền tọa độ từ đồ thị ban đầu sang đồ thị (1), thì bài toán trở  thành: Cho cây n đỉnh (n <=> số tplt trong đồ thị gốc). Hỏi cần thêm ít nhất bn cạnh sao cho cây ko còn cầu (3)
*       Đáp án là m / 2 với m là số nút lá (m chẵn, còn m lẻ là (m+1)/2). (2)
*           eg. 1 case có thể tưởng tượng là :
*               cây 1-2, 1-3, 1-4, 1-5, thì chỉ cần nối 2-3 hoặc 4-5 là được (tức là ghép cặp 2 đỉnh lá).
*               cây 1-2, 1-3, 1-4, 1-5, 1-6 thì phải ghép (2-3), (4-5) và (x-6).
* @Proof (2):
        - Rõ ràng ta thấy số cạnh cần thêm phải >= m / 2 (vì như thế thì toàn bộ đỉnh lá mới có thể có degree >= 2)
        - Ta chỉ ra 1 TH thêm m/2 cạnh là thỏa mãn (3):
            + Đầu tiên ta sắp xếp lá là 1->m
            + Giả sử ta nối lá thứ i với i+m/2 (1 <=i <=m /2). (4)
            + Giả sử ngược lại, (3) không tm, tức là tồn tại 1 cầu (u, v) nào đó, với u là cha v (cha ở đây tức là mình xét dfs cây gốc thì chạy từ u→v).
            + Rõ ràng số lá trong gốc u > số lá trong gốc v. (ko thể bằng được vì nếu bằng thì chứng tỏ nhánh khác của gốc u ko còn lá, tức là chỉ còn chu trình thôi => sai vì đây là cây)(5)
            + Giả sử số lá trong gốc v là (l→r). Vì tính chất (u, v) cầu nên các lá trong [l, r] chỉ có thể nối với nhau qua lại trong gốc v thôi. Đến đây:
                + nếu l > m/2 => sai vì l được nối tới l – m/2 ko thuộc [l, r] (theo (4))
                + nếu r < m/2 => sai vì r được nối tới r + m/2 ko thuộc [l, r] (theo (4))
                + nếu l <= m/2 <= r => l = 1, r = m (theo (4)) => sai luôn vì [l, r] chứa hết toàn bộ m lá (mâu thuẫn với (5)).
            => Tóm lại, giả sử ngược lại là sai, cách nối i→i+m/2 giúp cho cây ko còn cầu
            => Có result >= m/2 và result = m/2 tồn tại nghiệm => min = m/2 

* Từ (2) và (3) ta đưa ra thuật:
*   B1: Chuyển miền bài toán sang cây:
*         1.1 Tìm  tập cầu sử dụng tarjan
*	      1.2 Xóa hết cạnh cầu trong đồ thị gốc đi, dùng dsu chạy tìm tập tplt
*	      1.3 Map mỗi tplt là 1 đỉnh trong cây mới. Kết hợp với 2 đầu mút của mỗi cầu, ta xác *         định tập các cạnh trong cây mới
*   B2: Tìm số lá trong cây <=> tìm số đỉnh có degree = 1
*/

int main(){
    freopen("./vnoi/contest/vpc_trial_2024/D.txt", "r", stdin);
    Graph g;
    cin >> g.V >> g.E;
    g.adj.resize(g.V);
    for (int u, v, w = 0, i = 0; i < g.E; ++i){
        cin >> u >> v;
        g.adj[u - 1].push_back({v - 1, w});
        g.adj[v - 1].push_back({u - 1, w});
        g.edges.push_back({u - 1, v - 1, w});
    }

    auto [bridges, cut_points] = Searcher::tarjan(g);

    auto edgeIfRemovedBridges = difference(g.edges, bridges);

    cout << "\nEdge if remove bridges: "; for (auto& e : edgeIfRemovedBridges) std::cout << e << ", ";
    cout << "\nAll edges: "; for (auto& e : g.edges) std::cout << e << ", ";
    cout << "\nAll bridges: "; for (auto& e : bridges) std::cout << e << ", ";
    cout << "\n\n";
    Graph tree = build_cc_tree(g, edgeIfRemovedBridges, bridges);
    int leaf = 0;
    for (int u = 0; u < tree.V; ++u) leaf += (tree.adj[u].size() == 1);
    std::cout << (leaf + 1) / 2;
    return 0;
}