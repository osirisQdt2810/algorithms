#ifndef DSA_GRAPH_SHORTEST_PATH_HPP
#define DSA_GRAPH_SHORTEST_PATH_HPP

#include "graph_types.hpp"

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

namespace dsa::graph::shortest_path {

namespace detail {

/**
 * @brief Reconstructs the path from `src` to `dst` using parent links.
 */
inline void trace_path(Path& path, const std::vector<Vertex>& parent, Vertex src, Vertex dst) {
    if (src == dst) {
        path.push_back(src);
        return;
    }
    if (parent[dst] == -1) return;
    trace_path(path, parent, src, parent[dst]);
    path.push_back(dst);
}

}  // namespace detail

/**
 * @brief Computes single-source shortest paths with Bellman-Ford relaxation.
 *
 * @param[in] graph Weighted graph represented by adjacency lists.
 * @param[in] src Source vertex.
 * @return Shortest path distances from `src`.
 * @note: Using graph.adj => O(V*E)
 */
template <typename WeightType>
inline ShortestPathTree<WeightType> bellman_ford(const WeightedGraph<WeightType>& graph, Vertex src) {
    std::vector<WeightType> dist(graph.V, kMaxWeight<WeightType>);
    dist[src] = 0;

    ShortestPathTree<WeightType> result(graph.V);
    for (int iter = 0; iter < graph.V; ++iter) {
        for (int u = 0; u < graph.V; ++u) {
            for (const auto& [v, w] : graph.adj[u]) {
                if (dist[u] != kMaxWeight<WeightType>) {
                    dist[v] = std::min(dist[v], dist[u] + w);
                }
            }
        }
    }
    result.distances = std::move(dist);
    return result;
}

/**
 * @brief Computes all-pairs shortest paths with Floyd-Warshall.
 *
 * @param[in] graph Weighted graph represented by an adjacency matrix.
 * @return Matrix where `dist[i][j]` is the shortest distance from i to j.
 * @note: Using graph.mat => O(V^3)
 * @warning:
 *     1. graph.mat[i][j] = 0           if (i == j)
 *     2. graph.mat[i][j] = kMaxWeight  if dont have edge (i -> j)
 */
template <typename WeightType>
inline WeightMatrix<WeightType> floyd_warshall(const WeightedGraph<WeightType>& graph) {
    WeightMatrix<WeightType> dist = graph.mat;
    for (int k = 0; k < graph.V; ++k) {
        for (int i = 0; i < graph.V; ++i) {
            for (int j = 0; j < graph.V; ++j) {
                if (dist[i][k] != kMaxWeight<WeightType> && dist[k][j] != kMaxWeight<WeightType>) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

/**
 * @brief Computes single-source shortest paths with Dijkstra's algorithm.
 *
 * @param[in] graph Weighted graph represented by adjacency lists.
 * @param[in] src Source vertex.
 * @param[in] dst Optional destination. Use -1 to compute all reachable vertices.
 * @param[in] trace Whether to reconstruct paths from `src`.
 * @return Shortest path distances and optional path traces.
 * @note: Using graph.adj => O((E + V) logV)
 */
template <typename WeightType>
inline ShortestPathTree<WeightType> dijkstra(
    const WeightedGraph<WeightType>& graph,
    Vertex src,
    Vertex dst = -1,
    bool trace = false
) {
    auto cmp = [](const WeightedNeighbor<WeightType>& lhs, const WeightedNeighbor<WeightType>& rhs) {
        return lhs.second > rhs.second;
    };  // min-heap
    std::priority_queue<
        WeightedNeighbor<WeightType>,
        std::vector<WeightedNeighbor<WeightType>>,
        decltype(cmp)
    > pq(cmp);
    std::vector<WeightType> dist(graph.V, kMaxWeight<WeightType>);
    std::vector<Vertex> parent(graph.V, -1);

    dist[src] = 0;
    parent[src] = src;
    pq.push({src, dist[src]});

    ShortestPathTree<WeightType> result(graph.V, trace);
    while (!pq.empty()) {
        // get current best vertex
        auto [u, du] = pq.top();
        pq.pop();
        if (dist[u] != du) continue;

        // assign to result
        result.distances[u] = du;
        if (trace) detail::trace_path(result.paths[u], parent, src, u);

        // stop if meets target vertex
        if (dst == u) break;

        // update neighbor vertex
        for (const auto& [v, w] : graph.adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }
    return result;
}

}  // namespace dsa::graph::shortest_path

#endif  // DSA_GRAPH_SHORTEST_PATH_HPP
