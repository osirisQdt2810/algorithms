#include <vector>
#include <iostream>

using namespace std;

/*
    LC 3600 - Maximize Spanning Tree Stability with Upgrades
    https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/

    Problem:
        You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of
        edges, where edges[i] = [u_i, v_i, s_i, must_i]:
          - u_i and v_i indicates an undirected edge between nodes u_i and v_i.
          - s_i is the strength of the edge.
          - must_i is an integer (0 or 1). If must_i == 1, the edge must be included in the
            spanning tree. These edges cannot be upgraded.
        You are also given an integer k, the maximum number of upgrades you can perform. Each
        upgrade doubles the strength of an edge, and each eligible edge (with must_i == 0) can be
        upgraded at most once.
        The stability of a spanning tree is defined as the minimum strength score among all edges
        included in it.
        Return the maximum possible stability of any valid spanning tree. If it is impossible to
        connect all nodes, return -1.

        Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all
        nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly
        n - 1 edges.

        Constraints:
          - 2 <= n <= 10^5
          - 1 <= edges.length <= 10^5
          - edges[i] = [u_i, v_i, s_i, must_i]
          - 0 <= u_i, v_i < n
          - u_i != v_i
          - 1 <= s_i <= 10^5
          - must_i is either 0 or 1.
          - 0 <= k <= n
          - There are no duplicate edges.

    Examples:
        Example 1:
            Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1
            Output: 2
            Explanation:
              - Edge [0,1] with strength = 2 must be included in the spanning tree.
              - Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
              - The resulting spanning tree includes these two edges with strengths 2 and 6.
              - The minimum strength in the spanning tree is 2, which is the maximum possible
                stability.

        Example 2:
            Input: n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2
            Output: 6
            Explanation:
              - Since all edges are optional and up to k = 2 upgrades are allowed.
              - Upgrade edges [0,1] from 4 to 8 and [1,2] from 3 to 6.
              - The resulting spanning tree includes these two edges with strengths 8 and 6.
              - The minimum strength in the tree is 6, which is the maximum possible stability.

        Example 3:
            Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0
            Output: -1
            Explanation:
              - All edges are mandatory and form a cycle, which violates the spanning tree
                property of acyclicity. Thus, the answer is -1.

    Best solution:
        Binary search on the answer (the minimum strength / stability m) + DSU feasibility check
        with a greedy "free edges first, then spend upgrades" pass.

    Time & Space complexity:
        Time:  O((V + E) * alpha(V) * log(2 * max_s) + E log E)
               - one sort of the optional edges up front: O(E log E);
               - each of the O(log(2 * max_s)) binary-search steps copies the mandatory-edge DSU
                 (O(V)) and scans every optional edge once with near-constant DSU ops (O(E alpha)).
        Space: O(V + E)
               - DSU parent array of size V (plus one copy per check) and the optional-edge list.

    Approach (detail):
        1. Monotonicity is the key insight: if a spanning tree with every edge strength >= m
           exists, then one with every strength >= m' exists for any m' <= m (the same tree
           works). So `feasible(m)` is monotone decreasing in m and the maximum stability can be
           binary searched over m in [1, 2 * 10^5] (2 * max_s, since an upgrade at most doubles
           1 <= s <= 10^5).
        2. Preprocess the mandatory edges (must == 1): they are all forced into the tree, so union
           them in a base DSU. If any mandatory edge closes a cycle, no acyclic spanning tree can
           contain all of them -> return -1 immediately. Record min_must = min strength over
           mandatory edges; mandatory edges cannot be upgraded, so any answer m > min_must is
           infeasible by definition.
        3. Sort the optional edges (must == 0) by strength descending, once, outside the search.
        4. feasible(m): start from a copy of the base (mandatory) DSU and walk the sorted optional
           edges with a budget of k upgrades:
             - if 2 * s < m, the edge is useless even after an upgrade -> skip it;
             - if s >= m, the edge already clears the threshold -> union for free;
             - otherwise (m <= 2 * s and s < m) the edge only clears m when upgraded -> union it
               and, if the union actually merged two components, spend one upgrade (spend nothing
               when the edge was redundant).
           m is feasible iff the DSU ends with exactly one component.
        5. Why the greedy is correct: descending sort guarantees every free edge (s >= m) is
           processed before every upgrade-needing edge (s < m), so upgrades are only ever spent on
           components that no free edge could have merged. Connectivity is what matters, not which
           particular edges are chosen — the usable edge set at threshold m is fixed, and spending
           an upgrade only when a union succeeds keeps the number of upgrades at the minimum needed
           to connect the graph. Hence if this pass fails to connect, no assignment of <= k
           upgrades can.
        6. Standard binary search: on success record m and search higher (l = m + 1), else search
           lower (r = m - 1). The recorded answer stays -1 when even m = 1 is infeasible, i.e. the
           graph cannot be connected at all.
*/

class Solution {
    private:
        struct edge {
            int u, v, w;
        };

        struct DSU {
            int n;
            int components;
            vector<int> parents;

            DSU(int n_) : n(n_), components(n_), parents(n, -1){}

            int root(int u){
                return (parents[u] < 0) ? u : (parents[u] = root(parents[u]));
            }

            bool join(int u, int v){
                int root_u = root(u);
                int root_v = root(v);
                if (root_u == root_v) return false;

                --components;
                parents[root_u] += parents[root_v];
                parents[root_v] = root_u;
                return true;
            }
        };

    public:
        int maxStability(int n, vector<vector<int>>& edges, int k) {
            int l = 1, r = 2e5, ans = -1;
            int min_must = INT_MAX;
            vector<edge> opts;
            DSU t_dsu(n);
            for (auto& edge : edges){
                int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
                if (m == 0){
                    opts.push_back({u, v, s});
                    continue;
                }
                if (!t_dsu.join(u, v)) return -1;
                min_must = min(min_must, s);
            }
            sort(opts.begin(), opts.end(), [](const edge& lhs, const edge& rhs){
                return lhs.w > rhs.w;
            });

            auto form_valid_spanning_tree = [&](int m){
                // all edges has strength >= m
                if (min_must < m) return false;
                DSU dsu = t_dsu;
                int used_k = k;
                for (auto& edge : opts){
                    auto [u, v, s] = edge;
                    if (2 * s < m) continue;
                    if (s >= m){
                        dsu.join(u, v);
                    }
                    else if (used_k > 0){
                        used_k -= dsu.join(u, v);
                    }
                }
                
                return (dsu.components == 1);
            };

            while (l <= r){
                int m = (l+r)/2;
                if (form_valid_spanning_tree(m)){
                    ans = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            return ans;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    return 0;
}