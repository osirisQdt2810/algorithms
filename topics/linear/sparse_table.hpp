#ifndef DSA_LINEAR_SPARSE_TABLE_HPP
#define DSA_LINEAR_SPARSE_TABLE_HPP

#include "utility.hpp"

#include <cmath>
#include <vector>

using namespace dsa::utility::monoid;

namespace dsa::linear::sparse_table {
    /**
     * Sparse table: static range-query structure that precomputes Ops::combine
     * over every interval of length 2^j, enabling fast arbitrary-range queries.
     *
     * Supports ANY associative monoid (not necessarily idempotent).
     * Build: O(n log n) time + space.
     * Query: O(log n) — decomposes [l,r] into disjoint power-of-two blocks.
     *
     * Requires Ops to satisfy is_valid_monoid_ops<Ops, T> (identity + combine).
     * Default Ops = sumops<T>; for idempotent ops prefer IdempotentSparseTable.
     *
     * Example:
     *   std::vector<int> a{5, 2, 8, 1, 9, 3};
     *   GenericSparseTable<int> st(a);    // sumops by default
     *   st.query(1, 4);                   // returns 2+8+1+9 = 20
     */
    template<
        typename T, class Ops = sumops<T>,
        typename = std::enable_if_t<is_valid_monoid_ops<Ops, T>::value>
    >
    class GenericSparseTable {
        protected:
            // sparse_table_[i][j] = Ops::combine of arr[i .. i + 2^j - 1]
            std::vector<std::vector<T>> sparse_table_;
            int n_;
            int num_levels_;   // floor(log2(n)) + 1

            /**
             * Fills sparse_table_ bottom-up: level 0 = raw elements,
             * level j = combine(left half, right half) of level j-1.
             */
            void build_sparse_table(const std::vector<T>& arr){
                sparse_table_.assign(n_, std::vector<T>(num_levels_, Ops::identity()));
                for (int i = 0; i < n_; ++i) sparse_table_[i][0] = arr[i];
                for (int j = 1; j < num_levels_; ++j)
                    for (int i = 0; i + (1 << j) - 1 < n_; ++i)
                        sparse_table_[i][j] = Ops::combine(sparse_table_[i][j-1], sparse_table_[i+(1<<(j-1))][j-1]);
            }

        public:
            explicit GenericSparseTable(const std::vector<T>& arr)
                : n_(static_cast<int>(arr.size())),
                  num_levels_(static_cast<int>(std::floor(std::log2(n_))) + 1){
                build_sparse_table(arr);
            }

            /**
             * Returns Ops::combine over arr[l..r] (inclusive).
             * Decomposes len = r-l+1 into disjoint blocks of size 2^j (greedy
             * from highest bit), combines left-to-right. O(log n).
             */
            T query(int l, int r) const {
                T target = Ops::identity();
                int len = r - l + 1;
                for (int j = 0; j < num_levels_; ++j){
                    if (1 & (len >> j)){
                        target = Ops::combine(target, sparse_table_[l][j]);
                        l = l + (1 << j);
                    }
                }
                return target;
            }
    };

    /**
     * Sparse table specialised for idempotent ops (max, min, gcd, and, or).
     *
     * Precomputes the same table as GenericSparseTable but exploits idempotency
     * — combine(x, x) == x — to answer queries with two overlapping blocks in O(1).
     * Build: O(n log n).  Query: O(1).
     *
     * Inherits storage and build from GenericSparseTable; only query() differs.
     *
     * Example:
     *   std::vector<int> a{5, 2, 8, 1, 9, 3};
     *   IdempotentSparseTable<int> st(a);           // maxops by default
     *   st.query(1, 4);                              // returns max(2,8,1,9) = 9
     *
     *   IdempotentSparseTable<int, minops<int>> mn(a);
     *   mn.query(0, 5);                              // returns min = 1
     */
    template<
        typename T, class Ops = maxops<T>,
        typename = std::enable_if_t<is_valid_idempotent_ops<Ops, T>::value>
    >
    class IdempotentSparseTable : public GenericSparseTable<T, Ops> {
        public:
            using GenericSparseTable<T, Ops>::GenericSparseTable;

            /**
             * Returns Ops::combine over arr[l..r] (inclusive).
             * Picks k = floor(log2(r-l+1)) and merges two length-2^k blocks
             * [l, l+2^k-1] and [r-2^k+1, r]; overlap is safe since op is idempotent.
             * O(1).
             */
            T query(int l, int r) const {
                int k = static_cast<int>(std::floor(std::log2(r - l + 1)));
                return Ops::combine(this->sparse_table_[l][k],
                                    this->sparse_table_[r - (1 << k) + 1][k]);
            }
    };
}

#endif // DSA_LINEAR_SPARSE_TABLE_HPP
