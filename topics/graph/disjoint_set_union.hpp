#ifndef DSA_GRAPH_DISJOINT_SET_UNION_HPP
#define DSA_GRAPH_DISJOINT_SET_UNION_HPP

#include <vector>

namespace dsa::graph {

    /**
     * @brief Disjoint-set union with path compression.
     */
    class DisjointSetUnion {
        protected:
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
    class TrackedDisjointSetUnion {
        protected:
            std::vector<int> parents_;

        public:
            /**
             * @brief Creates `vertices` singleton sets, each with size 1.
             */
            explicit TrackedDisjointSetUnion(int vertices) : parents_(vertices, -1) {}

            /**
             * @brief Finds the representative of the set containing `u`.
             */
            virtual int find_root(int u) {
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

    /**
     * @brief Weighted disjoint-set union with path compression.
     *
     * This data structure maintains disjoint sets like a normal DSU.
     * In addition to the parent link, each vertex also stores a multiplicative
     * weight relative to its parent.
     *
     * More precisely, for every vertex `u`:
     *
     *     weights_[u] = u / parents_[u]
     *
     * If `u` is a root, then:
     *
     *     parents_[u] = u
     *     weights_[u] = 1.0
     *
     * because the ratio from a root to itself is 1.
     *
     * The stored weights allow the DSU to answer ratio queries between two
     * vertices in the same connected component. After path compression, the
     * weight of a vertex is updated to represent its ratio directly to the root:
     *
     *     weights_[u] = u / root
     *
     * Therefore, if two vertices `u` and `v` have the same root, their ratio can
     * be computed as:
     *
     *     u / v = (u / root) / (v / root)
     *           = weights_[u] / weights_[v]
     *
     * This structure is useful when union operations are not only saying
     * "u and v belong to the same set", but also providing a known ratio:
     *
     *     u / v = ratio
     *
     * The DSU preserves these ratio relationships while still supporting path
     * compression.
     */
    template<typename WeightType>
    class WeightedDisjointSetUnion : public TrackedDisjointSetUnion {
        protected:
            std::vector<WeightType> weights_;

        public:
            static constexpr WeightType kNil = std::numeric_limits<WeightType>::lowest();

        public:
            WeightedDisjointSetUnion(int vertices) : TrackedDisjointSetUnion(vertices){
                weights_.assign(vertices, (WeightType)1);
            }

            int find_root(int u) override {
                if (parents_[u] < 0) return u;
                int p = parents_[u];
                // after find_root for p -> parents_[p] = root;
                // so: weight[u] = u / root = (u / p) * (p / root) = weight[u] * weight[p]
                parents_[u] = find_root(p);
                weights_[u] *= weights_[p];
                return parents_[u];
            }

            bool unite(int u, int v, WeightType udv){
                int root_u = find_root(u);
                int root_v = find_root(v);
                if (root_u == root_v) return false;

                parents_[root_v] += parents_[root_u];
                parents_[root_u] = root_v;

                // update weights for root_u:
                // after find_root() for u and v, weights[u] = u / root_u and weights[v] = v / root_v
                // weights[root_u] = root_u / root_v = (root_u / u) * (u / v) * (v / root_v) = udv * weights[v] / weights[u]
                weights_[root_u] = udv * weights_[v] / weights_[u];
                return true;
            }

            WeightType query(int u, int v){
                int root_u = find_root(u);
                int root_v = find_root(v);
                if (root_u != root_v) return kNil;
                // u / v = (u / root_u) / (v / root_v) = weights[u] / weights[v]
                return weights_[u] / weights_[v];
            }
    };
}  // namespace dsa::graph

#endif  // DSA_GRAPH_DISJOINT_SET_UNION_HPP
