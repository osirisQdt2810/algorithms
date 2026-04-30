#ifndef DSA_GRAPH_BIPARTITE_MATCHING_HPP
#define DSA_GRAPH_BIPARTITE_MATCHING_HPP

#include "graph_types.hpp"

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

namespace dsa::graph::bipartite_matching {

namespace detail {

inline constexpr int kNil = 0;

/**
 * @brief Finds one augmenting path from a vertex in the first partition.
 *
 * @param[in] graph Bipartite graph whose adjacency lists go from V1 to V2.
 * @param[in,out] visited Marks V1 vertices already explored in this DFS pass.
 * @param[in,out] matching Current V2-to-V1 matching.
 * @param[in] u Vertex in V1 to start from.
 * @return True if an augmenting path was found and `matching` was updated.
 */
inline bool try_kuhn(
    const BipartiteGraph& graph,
    std::vector<bool>& visited,
    std::vector<Vertex>& matching,
    Vertex u
) {
    if (visited[u]) return false;
    visited[u] = true;

    for (Vertex v : graph.adj[u]) {
        if (matching[v] == -1 || try_kuhn(graph, visited, matching, matching[v])) {  // if v is a unsaturated vertex, so v is the end of
            matching[v] = u;
            return true;
        }
    }
    return false;
}

/**
 * @brief Builds the BFS layers used by Hopcroft-Karp.
 *
 * @param[in] graph Bipartite graph whose adjacency lists go from V1 to V2.
 * @param[in] pair_u Current V1-to-V2 matching, using 1-based vertices and NIL.
 * @param[in] pair_v Current V2-to-V1 matching, using 1-based vertices and NIL.
 * @param[out] dist Distance labels for the layered graph.
 * @return True if there is at least one free vertex in V2 reachable from V1.
 */
inline bool hopcroft_karp_bfs(
    const BipartiteGraph& graph,
    std::vector<Vertex>& pair_u,
    std::vector<Vertex>& pair_v,
    std::vector<int>& dist
) {
    std::queue<Vertex> q;
    for (int u = 1; u <= graph.V1; ++u) {
        if (pair_u[u] == kNil) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = kMaxWeight<int>;
        }
    }

    dist[kNil] = kMaxWeight<int>;
    while (!q.empty()) {
        Vertex u = q.front();
        q.pop();
        if (dist[u] >= dist[kNil]) continue;

        for (Vertex v : graph.adj[u - 1]) {
            if (dist[pair_v[v + 1]] == kMaxWeight<int>) {
                dist[pair_v[v + 1]] = dist[u] + 1;
                q.push(pair_v[v + 1]);
            }
        }
    }
    return dist[kNil] != kMaxWeight<int>;
}

/**
 * @brief Searches an augmenting path in the current Hopcroft-Karp layer graph.
 *
 * @param[in] graph Bipartite graph whose adjacency lists go from V1 to V2.
 * @param[in,out] pair_u Current V1-to-V2 matching, using 1-based vertices and NIL.
 * @param[in,out] pair_v Current V2-to-V1 matching, using 1-based vertices and NIL.
 * @param[in,out] dist Distance labels built by `hopcroft_karp_bfs`.
 * @param[in] u Current 1-based vertex in V1, or NIL.
 * @return True if an augmenting path was found and the matching was updated.
 */
inline bool hopcroft_karp_dfs(
    const BipartiteGraph& graph,
    std::vector<Vertex>& pair_u,
    std::vector<Vertex>& pair_v,
    std::vector<int>& dist,
    Vertex u
) {
    if (u == kNil) return true;

    for (Vertex v : graph.adj[u - 1]) {
        if (dist[pair_v[v + 1]] == dist[u] + 1 &&
            hopcroft_karp_dfs(graph, pair_u, pair_v, dist, pair_v[v + 1])) {
            pair_v[v + 1] = u;
            pair_u[u] = v + 1;
            return true;
        }
    }
    dist[u] = kMaxWeight<int>;
    return false;
}

}  // namespace detail

/**
 * @brief Computes a maximum cardinality matching with Kuhn's algorithm.
 *
 * @param[in] graph Bipartite graph whose adjacency lists go from V1 to V2.
 * @param[in] trace Whether to store the final V2-to-V1 matching vector.
 * @return A bipartite matching summary. If `trace` is false, only `matches` is populated.
 * @note Time complexity is O(V1 * E) in the usual implementation.
 */
inline BipartiteMatching<> kuhn(const BipartiteGraph& graph, bool trace = false) {
    std::vector<bool> visited;
    std::vector<Vertex> matching(graph.V2, -1);

    BipartiteMatching<> result;
    // for each vertex u in V1, we tried to find the augmenting path from u
    for (int u = 0; u < graph.V1; ++u) {
        visited.assign(graph.V1, false);  // reset state of visited for each vertex in V1
        if (detail::try_kuhn(graph, visited, matching, u)) {
            ++result.matches;
        }
    }
    if (trace) result.matching = std::move(matching);
    return result;
}

/**
 * @brief Computes a maximum cardinality matching with a greedy warm-up before Kuhn DFS.
 *
 * @param[in] graph Bipartite graph whose adjacency lists go from V1 to V2.
 * @param[in] trace Whether to store the final V2-to-V1 matching vector.
 * @return A bipartite matching summary. If `trace` is false, only `matches` is populated.
 * @note The greedy warm-up often reduces DFS work but does not change the final maximum matching guarantee.
 */
inline BipartiteMatching<> kuhn_with_greedy_warmup(
    const BipartiteGraph& graph,
    bool trace = false
) {
    std::vector<bool> visited;
    std::vector<Vertex> matching(graph.V2, -1);
    std::vector<bool> has_augmented(graph.V1, false);

    // do the heuristic to get the easiest maximum matching
    for (int u = 0; u < graph.V1; ++u) {
        for (Vertex v : graph.adj[u]) {
            if (matching[v] == -1) {
                matching[v] = u;
                has_augmented[u] = true;
                break;
            }
        }
    }

    BipartiteMatching<> result;
    // for each vertex u in V1 (not augmented), we tried to find the augmenting path from u
    for (int u = 0; u < graph.V1; ++u) {
        if (has_augmented[u]) {
            ++result.matches;
            continue;
        }
        visited.assign(graph.V1, false);
        if (detail::try_kuhn(graph, visited, matching, u)) {
            ++result.matches;
        }
    }
    if (trace) result.matching = std::move(matching);
    return result;
}

/**
 * @brief Computes a maximum cardinality matching with Hopcroft-Karp.
 *
 * @param[in] graph Bipartite graph whose adjacency lists go from V1 to V2.
 * @param[in] trace Whether to store the final V2-to-V1 matching vector.
 * @return A bipartite matching summary. If `trace` is false, only `matches` is populated.
 * @note Time complexity is O(sqrt(V) * E).
 */
inline BipartiteMatching<> hopcroft_karp(const BipartiteGraph& graph, bool trace = false) {
    std::vector<Vertex> pair_u(graph.V1 + 1, detail::kNil);
    std::vector<Vertex> pair_v(graph.V2 + 1, detail::kNil);
    std::vector<int> dist(graph.V1 + 1);

    BipartiteMatching<> result;
    while (detail::hopcroft_karp_bfs(graph, pair_u, pair_v, dist)) {
        for (int u = 1; u <= graph.V1; ++u) {
            if (pair_u[u] == detail::kNil && detail::hopcroft_karp_dfs(graph, pair_u, pair_v, dist, u)) {
                ++result.matches;
            }
        }
    }

    if (trace) {
        for (int v = 1; v <= graph.V2; ++v) {
            result.matching.push_back((pair_v[v] == detail::kNil) ? -1 : pair_v[v] - 1);
        }
    }
    return result;
}

/**
 * @brief Solves the minimum-cost assignment problem with the Hungarian algorithm.
 *
 * @param[in] graph Complete or cost-matrix-backed bipartite graph.
 * @return A bipartite matching containing the minimum assignment cost and V2-to-V1 assignment.
 * @note `graph.mat[i][j]` is the cost of matching vertex `i` in V1 to vertex `j` in V2.
 */
template <typename WeightType>
inline BipartiteMatching<WeightType> hungarian(const WeightedBipartiteGraph<WeightType>& graph) {
    WeightMatrix<WeightType> cost = graph.mat;
    int n = graph.V1;
    int m = graph.V2;
    if (n == 0 || m == 0) return BipartiteMatching<WeightType>();

    std::vector<WeightType> u(n + 1), v(m + 1), minv(m + 1);
    std::vector<Vertex> p(m + 1), way(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        minv.assign(m + 1, kMaxWeight<WeightType>);
        std::vector<bool> used(m + 1, false);

        do {
            used[j0] = true;
            int i0 = p[j0];
            WeightType delta = kMaxWeight<WeightType>;
            int j1 = 0;

            for (int j = 1; j <= m; ++j) {
                if (used[j]) continue;

                WeightType cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }

            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    BipartiteMatching<WeightType> result;
    result.matches = std::min(m, n);
    result.cost = -v[0];
    for (int j = 1; j <= m; ++j) {
        result.matching.push_back(p[j] - 1);
    }
    return result;
}

}  // namespace dsa::graph::bipartite_matching

#endif  // DSA_GRAPH_BIPARTITE_MATCHING_HPP
