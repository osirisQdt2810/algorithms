#ifndef DSA_GRAPH_GRAPH_TYPES_HPP
#define DSA_GRAPH_GRAPH_TYPES_HPP

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iosfwd>
#include <limits>
#include <ostream>
#include <utility>
#include <vector>

namespace dsa::graph {

/**
 * @brief Identifies a vertex by its zero-based integer id.
 */
struct Vertex {
    int id;

    Vertex(int id = -1) : id(id) {}

    operator int() const {
        return id;
    }
};

/**
 * @brief Sentinel value used to represent infinity for a weight type.
 */
template <typename WeightType>
inline constexpr WeightType kMaxWeight = std::numeric_limits<WeightType>::max();

/**
 * @brief Adjacent vertex and edge weight pair in a weighted adjacency list.
 */
template <typename WeightType = float>
using WeightedNeighbor = std::pair<Vertex, WeightType>;

/**
 * @brief Sequence of vertices in a graph path.
 */
using Path = std::vector<Vertex>;

/**
 * @brief Matrix of edge weights or all-pairs distances.
 */
template <typename WeightType = float>
using WeightMatrix = std::vector<std::vector<WeightType>>;

/**
 * @brief Unweighted graph edge between two vertices.
 */
struct Edge {
    Vertex u, v;

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "(" << edge.u << ", " << edge.v << ")";
        return os;
    }

    bool operator==(const Edge& other) const {
        return (
            (u == other.u && v == other.v) ||
            (u == other.v && v == other.u)
        );
    }
};

/**
 * @brief Hashes an undirected edge by its endpoint ids.
 */
struct EdgeHash {
    std::size_t operator()(const Edge& edge) const {
        Vertex min_uv = std::min(edge.u, edge.v);
        Vertex max_uv = std::max(edge.u, edge.v);
        return std::hash<int>()(min_uv.id) ^ std::hash<int>()(max_uv.id);
    }
};

/**
 * @brief Weighted graph edge between two vertices.
 */
template <typename WeightType = float>
struct WeightedEdge {
    Vertex u, v;
    WeightType w;

    friend std::ostream& operator<<(std::ostream& os, const WeightedEdge& edge) {
        os << "(" << edge.u << ", " << edge.v << ", " << edge.w << ")";
        return os;
    }

    bool operator==(const WeightedEdge& other) const {
        return (
            (u == other.u && v == other.v && w == other.w) ||
            (u == other.v && v == other.u && w == other.w)
        );
    }
};

/**
 * @brief Stores an edge-list and adjacency-list representation of an unweighted graph.
 */
struct Graph {
    int V, E;
    std::vector<Edge> edges;
    std::vector<std::vector<Vertex>> adj;
};

/**
 * @brief Stores edge-list, adjacency-list, and matrix representations of a weighted graph.
 */
template <typename WeightType = float>
struct WeightedGraph {
    int V, E;
    std::vector<WeightedEdge<WeightType>> edges;
    std::vector<std::vector<WeightedNeighbor<WeightType>>> adj;
    WeightMatrix<WeightType> mat;
};

/**
 * @brief Stores an unweighted bipartite graph with edges from the first partition to the second.
 */
struct BipartiteGraph {
    int V1, V2;                 // first-part: 0...V1-1, second-part: 0...V2-1
    int E;
    std::vector<std::vector<Vertex>> adj;  // adj[u]: vertices v in V2 with edge u-v
};

/**
 * @brief Stores a weighted bipartite graph and its cost matrix.
 */
template <typename WeightType = float>
struct WeightedBipartiteGraph {
    int V1, V2;                 // first-part: 0...V1-1, second-part: 0...V2-1
    int E;
    std::vector<std::vector<WeightedNeighbor<WeightType>>> adj;  // adj[u]: vertices v in V2 with edge u-v
    WeightMatrix<WeightType> mat;
};

/**
 * @brief Stores the total weight and optional edge trace of a minimum spanning tree.
 */
template <typename WeightType = float>
struct MinimumSpanningTree {
    std::vector<WeightedEdge<WeightType>> edges;
    WeightType total_weight{0};

    friend std::ostream& operator<<(std::ostream& os, const MinimumSpanningTree& tree) {
        os << "MinimumSpanningTree: " << tree.total_weight << ": ";
        for (const auto& edge : tree.edges) {
            os << edge << " ";
        }
        os << "\n";
        return os;
    }
};

/**
 * @brief Stores single-source shortest path distances and optional concrete paths.
 */
template <typename WeightType = float>
struct ShortestPathTree {
    bool has_trace;
    std::vector<Path> paths;
    std::vector<WeightType> distances;

    explicit ShortestPathTree(int vertices, bool trace = false) : has_trace(trace) {
        distances.assign(vertices, kMaxWeight<WeightType>);
        if (trace) paths.resize(vertices);
    }

    friend std::ostream& operator<<(std::ostream& os, const ShortestPathTree& result) {
        for (std::size_t u = 0; u < result.distances.size(); ++u) {
            os << "ShortestPathTree: " << result.distances[u] << ": (";
            if (result.has_trace) {
                const auto& path = result.paths[u];
                for (std::size_t i = 0; i < path.size(); ++i) {
                    os << path[i];
                    if (i + 1 != path.size()) os << " -> ";
                }
            }
            os << ")\n";
        }
        return os;
    }
};

/**
 * @brief Stores the matching produced by a bipartite matching algorithm.
 *
 * `matching[v] = u` means vertex `v` in the second partition is matched with
 * vertex `u` in the first partition. Unmatched vertices are represented by -1
 * in algorithms that produce partial matchings.
 */
template <typename WeightType = float>
struct BipartiteMatching {
    int matches{0};
    WeightType cost{-1};
    std::vector<Vertex> matching;  // matching[v] = u, v in V2, u in V1
};

}  // namespace dsa::graph

#endif  // DSA_GRAPH_GRAPH_TYPES_HPP
