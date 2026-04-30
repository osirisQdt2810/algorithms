#ifndef DSA_GRAPH_TOPOLOGICAL_SORT_HPP
#define DSA_GRAPH_TOPOLOGICAL_SORT_HPP

#include "graph_types.hpp"

#include <queue>
#include <vector>

namespace dsa::graph::topological_sort {

/**
 * @brief Computes a topological order with Kahn's BFS algorithm.
 *
 * @param[in] graph Directed acyclic graph represented by adjacency lists.
 * @return Topological order. If the graph has a cycle, the returned order is partial.
 * @note topology search in BFS => Using graph.adj
 */
inline Path kahn(const Graph& graph) {
    std::vector<int> in_degree(graph.V, 0);
    for (int u = 0; u < graph.V; ++u) {
        for (Vertex v : graph.adj[u]) {
            ++in_degree[v];
        }
    }

    std::queue<Vertex> source_nodes;
    for (int u = 0; u < graph.V; ++u) {
        if (in_degree[u] == 0) source_nodes.push(u);
    }

    Path order;
    while (!source_nodes.empty()) {
        Vertex u = source_nodes.front();
        source_nodes.pop();
        order.push_back(u);

        for (Vertex v : graph.adj[u]) {
            --in_degree[v];
            if (in_degree[v] == 0) source_nodes.push(v);
        }
    }
    return order;
}

}  // namespace dsa::graph::topological_sort

#endif  // DSA_GRAPH_TOPOLOGICAL_SORT_HPP
