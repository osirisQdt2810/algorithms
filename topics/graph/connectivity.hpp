#ifndef DSA_GRAPH_CONNECTIVITY_HPP
#define DSA_GRAPH_CONNECTIVITY_HPP

#include "graph/graph_types.hpp"

#include <algorithm>
#include <queue>
#include <set>
#include <utility>
#include <vector>

namespace dsa::graph::connectivity {

namespace detail {

/**
 * @brief DFS helper for Tarjan bridge and articulation point discovery.
 */
inline void find_bridges(
    const Graph& graph,
    std::vector<Edge>& bridges,
    std::set<Vertex>& articulation_points,
    std::vector<int>& num,
    std::vector<int>& low,
    int& timer,
    Vertex u,
    Vertex parent
) {
    num[u] = low[u] = timer++;
    int children = 0;

    for (Vertex v : graph.adj[u]) {
        if (v == parent) continue;

        if (num[v] == -1) {
            find_bridges(graph, bridges, articulation_points, num, low, timer, v, u);
            low[u] = std::min(low[u], low[v]);

            if (low[v] >= num[u] && parent != -1) {
                articulation_points.insert(u);
            }
            if (low[v] > num[u]) {
                bridges.push_back({u, v});
            }
            ++children;
        } else {
            low[u] = std::min(low[u], num[v]);
        }
    }

    if (parent == -1 && children > 1) {
        articulation_points.insert(u);
    }
}

/**
 * @brief Detects a cycle in an undirected DFS tree.
 */
inline bool has_undirected_cycle_dfs(const Graph& graph, Vertex u, Vertex parent, std::vector<bool>& visited) {
    visited[u] = true;
    for (Vertex v : graph.adj[u]) {
        if (!visited[v]) {
            if (has_undirected_cycle_dfs(graph, v, u, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Detects a back edge in a directed DFS recursion stack.
 */
inline bool has_directed_cycle_dfs(
    const Graph& graph,
    Vertex u,
    std::vector<bool>& visited,
    std::vector<bool>& recursion_stack
) {
    visited[u] = true;
    recursion_stack[u] = true;

    for (Vertex v : graph.adj[u]) {
        if (!visited[v] && has_directed_cycle_dfs(graph, v, visited, recursion_stack)) {
            return true;
        }
        if (recursion_stack[v]) {
            return true;
        }
    }

    recursion_stack[u] = false;
    return false;
}

}  // namespace detail

/**
 * @brief Checks whether an undirected graph is bipartite.
 *
 * @param[in] graph Graph represented by adjacency lists.
 * @return True when all connected components can be two-colored.
 * @note Using graph.adj
 */
inline bool is_bipartite(const Graph& graph) {
    std::vector<int> color(graph.V, -1);

    for (int i = 0; i < graph.V; ++i) {
        if (color[i] != -1) continue;

        color[i] = 0;
        std::queue<Vertex> q;
        q.push(i);

        while (!q.empty()) {
            Vertex u = q.front();
            q.pop();

            for (Vertex v : graph.adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * @brief Finds all bridges and articulation points with Tarjan low-link values.
 *
 * @param[in] graph Undirected graph represented by adjacency lists.
 * @return Pair of bridge edges and articulation vertices.
 */
inline std::pair<std::vector<Edge>, std::set<Vertex>> tarjan_bridges_and_articulation_points(
    const Graph& graph
) {
    std::vector<int> num(graph.V, -1);
    std::vector<int> low(graph.V, -1);
    std::vector<Edge> bridges;
    std::set<Vertex> articulation_points;
    int timer = 0;

    for (int u = 0; u < graph.V; ++u) {
        if (num[u] == -1) {
            detail::find_bridges(graph, bridges, articulation_points, num, low, timer, u, -1);
        }
    }
    return {std::move(bridges), std::move(articulation_points)};
}

/**
 * @brief Checks whether a directed graph contains a cycle.
 *
 * @param[in] graph Directed graph represented by adjacency lists.
 * @return True if a directed cycle exists.
 */
inline bool has_directed_cycle(const Graph& graph) {
    std::vector<bool> visited(graph.V, false);
    std::vector<bool> recursion_stack(graph.V, false);

    for (int u = 0; u < graph.V; ++u) {
        if (!visited[u] && detail::has_directed_cycle_dfs(graph, u, visited, recursion_stack)) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks whether an undirected graph contains a cycle.
 *
 * @param[in] graph Undirected graph represented by adjacency lists.
 * @return True if an undirected cycle exists.
 */
inline bool has_undirected_cycle(const Graph& graph) {
    std::vector<bool> visited(graph.V, false);

    for (int u = 0; u < graph.V; ++u) {
        if (!visited[u] && detail::has_undirected_cycle_dfs(graph, u, -1, visited)) {
            return true;
        }
    }
    return false;
}

}  // namespace dsa::graph::connectivity

#endif  // DSA_GRAPH_CONNECTIVITY_HPP
