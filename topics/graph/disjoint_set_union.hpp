#ifndef DSA_GRAPH_DISJOINT_SET_UNION_HPP
#define DSA_GRAPH_DISJOINT_SET_UNION_HPP

#include <vector>

namespace dsa::graph {

/**
 * @brief Disjoint-set union with path compression.
 */
class DisjointSetUnion {
private:
    std::vector<int> parents_;

public:
    /**
     * @brief Creates `vertices` singleton sets.
     */
    explicit DisjointSetUnion(int vertices) : parents_(vertices) {
        for (int i = 0; i < vertices; ++i) {
            parents_[i] = i;
        }
    }

    /**
     * @brief Finds the representative of the set containing `u`.
     *
     * @return Root representative after path compression.
     */
    int find_root(int u) {
        return (parents_[u] == u) ? u : (parents_[u] = find_root(parents_[u]));
    }

    /**
     * @brief Checks whether `u` and `v` belong to the same set.
     */
    bool connected(int u, int v) {
        return find_root(u) == find_root(v);
    }

    /**
     * @brief Merges the sets containing `u` and `v`.
     *
     * @return True when two different sets were merged.
     */
    bool unite(int u, int v) {
        int root_u = find_root(u);
        int root_v = find_root(v);
        if (root_u == root_v) return false;
        parents_[root_u] = root_v;
        return true;
    }
};

/**
 * @brief Disjoint-set union that also tracks component sizes.
 */
class WeightedDisjointSetUnion {
private:
    std::vector<int> parents_;

public:
    /**
     * @brief Creates `vertices` singleton sets, each with size 1.
     */
    explicit WeightedDisjointSetUnion(int vertices) : parents_(vertices, -1) {}

    /**
     * @brief Finds the representative of the set containing `u`.
     */
    int find_root(int u) {
        return (parents_[u] < 0) ? u : (parents_[u] = find_root(parents_[u]));
    }

    /**
     * @brief Checks whether `u` and `v` belong to the same set.
     */
    bool connected(int u, int v) {
        return find_root(u) == find_root(v);
    }

    /**
     * @brief Merges the sets containing `u` and `v`.
     *
     * @return True when two different sets were merged.
     */
    bool unite(int u, int v) {
        int root_u = find_root(u);
        int root_v = find_root(v);
        if (root_u == root_v) return false;
        parents_[root_v] += parents_[root_u];
        parents_[root_u] = root_v;
        return true;
    }

    /**
     * @brief Counts the current number of connected components.
     */
    int count_components() const {
        int count = 0;
        for (int parent : parents_) {
            count += (parent < 0);
        }
        return count;
    }

    /**
     * @brief Returns the size of the component containing `u`.
     */
    int component_size(int u) {
        return -parents_[find_root(u)];
    }
};

}  // namespace dsa::graph

#endif  // DSA_GRAPH_DISJOINT_SET_UNION_HPP
