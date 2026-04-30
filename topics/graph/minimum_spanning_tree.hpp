#ifndef DSA_GRAPH_MINIMUM_SPANNING_TREE_HPP
#define DSA_GRAPH_MINIMUM_SPANNING_TREE_HPP

#include "disjoint_set_union.hpp"
#include "graph_types.hpp"

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

namespace dsa::graph::mst {

/**
 * @brief Computes a minimum spanning tree with Kruskal's algorithm.
 *
 * @param[in] graph Weighted undirected graph. It is passed by value because the edge list is sorted.
 * @param[in] trace Whether to store chosen MST edges.
 * @return Minimum spanning tree total weight and optional edge trace.
 * @note: Using graph.edges => O(ElogE)
 */
template <typename WeightType>
inline MinimumSpanningTree<WeightType> kruskal(WeightedGraph<WeightType> graph, bool trace = false) {
    DisjointSetUnion dsu(graph.V);
    std::sort(graph.edges.begin(), graph.edges.end(), [](const WeightedEdge<WeightType>& lhs, const WeightedEdge<WeightType>& rhs) {
        return lhs.w < rhs.w;
    });

    MinimumSpanningTree<WeightType> result;
    for (const auto& edge : graph.edges) {
        if (static_cast<int>(result.edges.size()) == graph.V - 1) break;

        if (dsu.unite(edge.u, edge.v)) {
            result.total_weight += edge.w;
            if (trace) result.edges.push_back(edge);
        }
    }
    return result;
}

/**
 * @brief Computes a minimum spanning tree with Prim's algorithm.
 *
 * @param[in] graph Weighted undirected graph represented by adjacency lists.
 * @param[in] trace Whether to store chosen MST edges.
 * @return Minimum spanning tree total weight and optional edge trace.
 * @note: Using graph.adj => O((E + V) logV)
 */
template <typename WeightType>
inline MinimumSpanningTree<WeightType> prim(const WeightedGraph<WeightType>& graph, bool trace = false) {
    auto compare = [](const WeightedNeighbor<WeightType>& lhs, const WeightedNeighbor<WeightType>& rhs) {
        return lhs.second > rhs.second;
    };  // min-heap
    std::priority_queue<
        WeightedNeighbor<WeightType>,
        std::vector<WeightedNeighbor<WeightType>>,
        decltype(compare)
    > pq(compare);
    std::vector<WeightType> dist(graph.V, kMaxWeight<WeightType>);
    std::vector<Vertex> parent(graph.V, -1);
    std::vector<bool> in_mst(graph.V, false);

    int source = 0;
    dist[source] = 0;
    pq.push({source, dist[source]});

    MinimumSpanningTree<WeightType> result;
    while (!pq.empty()) {
        // get current best vertex
        auto [u, du] = pq.top();
        pq.pop();
        if (in_mst[u]) continue;

        // assign to result
        in_mst[u] = true;
        if (u != source) {
            result.total_weight += du;
            if (trace) result.edges.push_back({parent[u], u, du});
        }

        // update neighbor vertex
        for (const auto& [v, w] : graph.adj[u]) {
            if (!in_mst[v] && dist[v] > w) {
                dist[v] = w;
                parent[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }
    return result;
}

}  // namespace dsa::graph::mst

#endif  // DSA_GRAPH_MINIMUM_SPANNING_TREE_HPP
