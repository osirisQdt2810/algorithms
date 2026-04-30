#ifndef DSA_GRAPH_LOWEST_COMMON_ANCESTOR_HPP
#define DSA_GRAPH_LOWEST_COMMON_ANCESTOR_HPP

#include "graph_types.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace dsa::graph {

/**
 * @brief Answers lowest common ancestor and tree-distance queries by binary lifting.
 */
template <typename WeightType = float>
class LowestCommonAncestor {
private:
    const WeightedGraph<WeightType>& tree_;
    Vertex root_;
    int max_log_;
    std::vector<Vertex> parent_;
    std::vector<int> height_;
    std::vector<WeightType> dist_;  // dist[u] = distance from root->u
    std::vector<std::vector<Vertex>> up_;

    /**
     * @brief Returns floor(log2(value)) for positive values.
     */
    static int log2_floor(int value) {
        int result = 0;
        while ((1 << (result + 1)) <= value) {
            ++result;
        }
        return result;
    }

    /**
     * @brief Initializes parent, height, distance, and lift tables.
     */
    void init() {
        assert(tree_.V > 0);
        dist_.assign(tree_.V, -1);
        dist_[root_] = 0;
        parent_.assign(tree_.V, Vertex{-1});
        height_.assign(tree_.V, -1);
        height_[root_] = 0;
        up_.assign(tree_.V, std::vector<Vertex>(max_log_, Vertex{-1}));
    }

    /**
     * @brief Computes direct parents, depths, and distances from the root.
     *
     * @note O(V + E)
     */
    void dfs(Vertex u) {
        for (const auto& [v, w] : tree_.adj[u]) {
            if (v == parent_[u]) continue;
            height_[v] = height_[u] + 1;
            dist_[v] = dist_[u] + w;
            parent_[v] = u;
            dfs(v);
        }
    }

    /**
     * @brief Builds the binary lifting table.
     *
     * @note O(VlogV)
     */
    void preprocess() {
        for (int u = 0; u < tree_.V; ++u) up_[u][0] = parent_[u];
        for (int j = 1; j < max_log_; ++j) {
            for (int u = 0; u < tree_.V; ++u) {
                up_[u][j] = (up_[u][j - 1] == -1) ? Vertex{-1} : up_[up_[u][j - 1]][j - 1];
            }
        }
    }

public:
    /**
     * @brief Preprocesses a rooted tree for LCA and distance queries.
     *
     * @param[in] tree Weighted tree represented by adjacency lists.
     * @param[in] root Root vertex used for depth and distance preprocessing.
     */
    explicit LowestCommonAncestor(const WeightedGraph<WeightType>& tree, Vertex root = 0)
        : tree_(tree), root_(root), max_log_(log2_floor(tree.V) + 1) {
        init();
        dfs(root_);
        preprocess();
    }

    /**
     * @brief Returns the lowest common ancestor of `u` and `v`.
     *
     * @note O(logN)
     */
    Vertex lca(Vertex u, Vertex v) const {
        if (height_[u] != height_[v]) {
            if (height_[u] < height_[v]) std::swap(u, v);  // => height_[u] > height_[v]

            // jump diff = height_[u] - height_[v] steps from u
            int diff = height_[u] - height_[v];
            for (int j = 0; (1 << j) <= diff; ++j) {
                if ((diff >> j) & 1) u = up_[u][j];
            }
        }

        if (u == v) return u;

        // jump to the farthest ancestor of (u and v), where ancestor[u] != ancestor[v]
        for (int j = log2_floor(height_[u]); j >= 0; --j) {
            if (up_[u][j] != up_[v][j]) {
                u = up_[u][j];
                v = up_[v][j];
            }
        }
        return up_[u][0];
    }

    /**
     * @brief Returns the weighted tree distance between `u` and `v`.
     *
     * @note O(logN)
     */
    WeightType distance(Vertex u, Vertex v) const {
        Vertex ancestor = lca(u, v);
        return dist_[u] + dist_[v] - 2 * dist_[ancestor];
    }
};

}  // namespace dsa::graph

#endif  // DSA_GRAPH_LOWEST_COMMON_ANCESTOR_HPP
