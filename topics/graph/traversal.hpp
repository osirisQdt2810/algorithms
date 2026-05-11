#ifndef DSA_GRAPH_TRAVERSAL_HPP
#define DSA_GRAPH_TRAVERSAL_HPP

#include "graph/graph_types.hpp"

#include <queue>
#include <vector>

namespace dsa::graph::traversal {

/**
 * @brief Traverses reachable vertices in breadth-first order.
 *
 * @param[in] graph Graph represented by adjacency lists.
 * @param[in] start Start vertex.
 * @return Visit order.
 * @note Using graph.adj O(V+E)
 */
inline Path bfs(const Graph& graph, Vertex start) {
    std::queue<Vertex> q;
    std::vector<bool> visited(graph.V, false);
    Path order;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        Vertex u = q.front();
        q.pop();
        order.push_back(u);

        for (Vertex v : graph.adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return order;
}

/**
 * @brief Recursively traverses reachable vertices in depth-first order.
 *
 * @param[in] graph Graph represented by adjacency lists.
 * @param[in] u Current vertex.
 * @param[in,out] visited Visit markers owned by the caller.
 * @param[out] order Visit order appended by this DFS.
 * @note Using graph.adj
 * @warning initialize `std::vector<bool> visited(graph.V, false) first`; O(V+E)
 */
inline void dfs(const Graph& graph, Vertex u, std::vector<bool>& visited, Path& order) {
    if (visited[u]) return;

    visited[u] = true;
    order.push_back(u);

    for (Vertex v : graph.adj[u]) {
        dfs(graph, v, visited, order);
    }
}

/**
 * @brief Traverses reachable vertices in depth-first order.
 *
 * @param[in] graph Graph represented by adjacency lists.
 * @param[in] start Start vertex.
 * @return Visit order.
 */
inline Path dfs(const Graph& graph, Vertex start) {
    std::vector<bool> visited(graph.V, false);
    Path order;
    dfs(graph, start, visited, order);
    return order;
}

}  // namespace dsa::graph::traversal

#endif  // DSA_GRAPH_TRAVERSAL_HPP
