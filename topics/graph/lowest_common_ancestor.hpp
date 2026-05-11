#ifndef DSA_GRAPH_LOWEST_COMMON_ANCESTOR_HPP
#define DSA_GRAPH_LOWEST_COMMON_ANCESTOR_HPP

#include "graph/graph_types.hpp"
#include "utility.hpp"

#include <cassert>
#include <utility>
#include <vector>

using namespace dsa::utility::monoid;

namespace dsa::graph {
    
    template<typename WeightType = float, class Ops = sumops<WeightType>>
    class GenericLowestCommonAncestor {
        public:
            static_assert(
                is_valid_monoid_ops<Ops, WeightType>::value,
                "Ops must have ::identity() -> WeightType and ::combine(WeightType, WeightType) -> WeightType"
            );

        protected:
            static constexpr WeightType kNil = Ops::identity();

            const WeightedGraph<WeightType>& tree_;
            Vertex root_;
            int level_;
            std::vector<int> height_;
            std::vector<std::vector<Vertex>> up_;           // up_[u][j]: 2^j-th parent of vertex u
            std::vector<std::vector<WeightType>> dist_;     // dist_[u][j]: ops distance between u -> up_[u][j]

        protected:
            int get_bit(int n, int i) const {
                return (n >> i) & 1;
            }

            virtual void init(){
                int V = tree_.V;
                height_.assign(V, -1);
                up_.assign(V, std::vector<Vertex>(level_ + 1, -1));
                dist_.assign(V, std::vector<WeightType>(level_ + 1, kNil));
                std::cout << "-> go here\n";
                dfs(root_, root_, 0);
            }

        private:
            virtual void dfs(Vertex u, Vertex p, WeightType w){
                height_[u] = height_[p] + 1;
                up_[u][0] = p;
                dist_[u][0] = w;
                for (int j = 1; j <= level_; ++j){
                    up_[u][j] = up_[up_[u][j-1]][j-1];
                    dist_[u][j] = Ops::combine(dist_[u][j-1], dist_[up_[u][j-1]][j-1]);
                }
                for (auto& [v, w] : tree_.adj[u]){
                    if (v == p) continue;
                    dfs(v, u, w);
                }
            }

        public:
            explicit GenericLowestCommonAncestor(const WeightedGraph<WeightType>& tree, Vertex root = 0, bool do_init = true)
                : tree_(tree), root_(root), level_(floor(log2(tree.V))) {
                if (do_init) init();
            }

            /**
             * @brief Returns the lowest common ancestor of `u` and `v`.
             *
             * @note O(logN)
             */
            virtual Vertex lca(Vertex u, Vertex v) const {
                if (height_[u] != height_[v]){
                    if (height_[u] < height_[v]) std::swap(u, v);
                    // binary lift u to u' where height_[u'] = height_[v];
                    int jump = height_[u] - height_[v];
                    for (int j = 0; j <= level_; ++j){
                        if (get_bit(jump, j)){
                            u = up_[u][j];
                        }
                    }
                }
                if (u == v) return u;
                // jump (u, v) to (u', v'), where both of them are the last node that u' != v'
                for (int j = level_; j >= 0; --j){
                    if (up_[u][j] != up_[v][j]){
                        u = up_[u][j];
                        v = up_[v][j];
                    }
                }
                return up_[u][0];
            }

            virtual WeightType distance(Vertex u, Vertex v) const {
                WeightType res = kNil;
                if (height_[u] != height_[v]){
                    if (height_[u] < height_[v]) std::swap(u, v);
                    // binary lift u to u' where height_[u'] = height_[v];
                    int jump = height_[u] - height_[v];
                    for (int j = 0; j <= level_; ++j){
                        if (get_bit(jump, j)){
                            res = Ops::combine(res, dist_[u][j]);
                            u = up_[u][j];
                        }
                    }
                }
                if (u == v) return res;
                // jump (u, v) to (u', v'), where both of them are the last node that u' != v'
                for (int j = level_; j >= 0; --j){
                    if (up_[u][j] != up_[v][j]){
                        res = Ops::combine(res, dist_[u][j]);
                        res = Ops::combine(res, dist_[v][j]);
                        u = up_[u][j];
                        v = up_[v][j];
                    }
                }
                res = Ops::combine(res, dist_[u][0]);
                res = Ops::combine(res, dist_[v][0]);
                return res;
            }
    };

    /**
     * @brief Answers lowest common ancestor and tree-distance queries by binary lifting.
     */
    template <typename WeightType = float>
    class LCAWithSumEdge2 : public GenericLowestCommonAncestor<WeightType>{
        private:
            std::vector<Vertex> parent_;
            std::vector<WeightType> sum_;  // sum_[u] = distance from root->u

            using Base = GenericLowestCommonAncestor<WeightType, sumops<WeightType>>;
            using Base::tree_;
            using Base::root_;
            using Base::level_;
            using Base::height_;
            using Base::up_;
            using Base::dist_;

        protected:
            /**
             * @brief Initializes parent, height, distance, and lift tables.
             */
            void init() override {
                assert(tree_.V > 0);
                sum_.assign(tree_.V, -1);
                sum_[root_] = 0;
                parent_.assign(tree_.V, Vertex{-1});
                height_.assign(tree_.V, -1);
                height_[root_] = 0;
                up_.assign(tree_.V, std::vector<Vertex>(level_, Vertex{-1}));
                dfs(root_);
                preprocess();
            }

        private:
            /**
             * @brief Computes direct parents, depths, and distances from the root.
             *
             * @note O(V + E)
             */
            void dfs(Vertex u) {
                for (const auto& [v, w] : tree_.adj[u]) {
                    if (v == parent_[u]) continue;
                    height_[v] = height_[u] + 1;
                    sum_[v] = sum_[u] + w;
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
                for (int j = 1; j < level_; ++j) {
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
            explicit LCAWithSumEdge2(const WeightedGraph<WeightType>& tree, Vertex root = 0)
                : GenericLowestCommonAncestor<WeightType>(tree, root, false){
                this->init();
            }

            /**
             * @brief Returns the weighted tree distance between `u` and `v`.
             *
             * @note O(logN)
             */
            WeightType distance(Vertex u, Vertex v) const override {
                Vertex ancestor = this->lca(u, v);
                return sum_[u] + sum_[v] - 2 * sum_[ancestor];
            }
    };

    template<typename WeightType = float, class Ops = sumops<WeightType>>
    class GenericLCAWithEulerTime : public GenericLowestCommonAncestor<WeightType, Ops> {
        private:
            std::vector<int> t_in_, t_out_;
            int timer_;

            using Base = GenericLowestCommonAncestor<WeightType, Ops>;
            using Base::tree_;
            using Base::root_;
            using Base::level_;
            using Base::height_;
            using Base::up_;
            using Base::dist_;

        protected:
            void init() override {
                int V = tree_.V;
                timer_ = 0;
                t_in_.assign(V, 0);
                t_out_.assign(V, 0);
                height_.assign(V, -1);
                up_.assign(V, std::vector<Vertex>(level_ + 1, -1));
                dist_.assign(V, std::vector<WeightType>(level_ + 1, Base::kNil));
                this->dfs(root_, root_, 0);
            }

        private:
            void dfs(Vertex u, Vertex p, WeightType w) override {
                // visit u
                t_in_[u] = timer_++;

                height_[u] = height_[p] + 1;
                up_[u][0] = p;
                dist_[u][0] = w;
                for (int j = 1; j <= level_; ++j){
                    up_[u][j] = up_[up_[u][j-1]][j-1];
                    dist_[u][j] = Ops::combine(dist_[u][j-1], dist_[up_[u][j-1]][j-1]);
                }
                for (auto& [v, w] : tree_.adj[u]){
                    if (v == p) continue;
                    dfs(v, u, w);
                }
                // leave u
                t_out_[u] = timer_++;
            }

        public:
            explicit GenericLCAWithEulerTime(const WeightedGraph<WeightType>& tree, Vertex root = 0)
                : GenericLowestCommonAncestor<WeightType, Ops>(tree, root, false){
                this->init();
            };

            bool is_ancestor(Vertex u, Vertex v) const {
                // u is ancestor of v <=> v belongs to subtree(u)
                // <=> t_in_[u] <= t_in_[v] <= t_out_[v] <= t_out_[u]
                return (t_in_[u] <= t_in_[v] && t_out_[v] <= t_out_[u]);
            }

            Vertex lca(Vertex u, Vertex v) const override {
                if (is_ancestor(u, v)) return u;
                // if u is not ancestor of v, we will do the binary uplifting for u to the last node `target`,
                // which is still not the ancestor of v.
                // Then, up_[target][0] (a.k.a parent[target]) will be the ancestor of v.
                for (int j = level_; j >= 0; --j){
                    if (!is_ancestor(up_[u][j], v)){
                        u = up_[u][j];
                    }
                } 
                return up_[u][0];
            }

            WeightType distance(Vertex u, Vertex v) const override {
                WeightType res = Base::kNil;
                if (is_ancestor(v, u)) std::swap(v, u);
                if (is_ancestor(u, v)){
                    int jump = height_[v] - height_[u];
                    // we need to jump `jump` nodes from v to u
                    // `jump` = x1x2...xn => only jump x[j] with x[j] = 1
                    for (int j = 0; j <= level_; ++j){
                        if (this->get_bit(jump, j)){
                            res = Ops::combine(res, dist_[v][j]);
                            v = up_[v][j];
                        }
                    }
                    return res;
                }

                for (int j = level_; j >= 0; --j){
                    if (!is_ancestor(up_[u][j], v)){
                        res = Ops::combine(res, dist_[u][j]);
                        u = up_[u][j];
                    }
                }
                res = Ops::combine(res, dist_[u][0]);
                res = Ops::combine(res, distance(up_[u][0], v));
                return res;
            }
    };

    template<typename WeightType>
    using LCAWithMaxEdge = GenericLowestCommonAncestor<WeightType, maxops<WeightType>>;

    template<typename WeightType>
    using LCAWithSumEdge = GenericLowestCommonAncestor<WeightType, sumops<WeightType>>;

    template<typename WeightType>
    using LCAWithMinEdge = GenericLowestCommonAncestor<WeightType, minops<WeightType>>;

    template<typename WeightType>
    using LCAWithGcdEdge = GenericLowestCommonAncestor<WeightType, gcdops<WeightType>>;
}  // namespace dsa::graph
#endif  // DSA_GRAPH_LOWEST_COMMON_ANCESTOR_HPP