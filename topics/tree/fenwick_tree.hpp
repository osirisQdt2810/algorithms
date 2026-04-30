#ifndef DSA_TREE_FENWICK_TREE_HPP
#define DSA_TREE_FENWICK_TREE_HPP

#include <vector>

namespace dsa::tree {

/**
 * @brief Support for three operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Update a[i] += k in O(logN)
 *        3. Update a[u->v] += k in O(logN)
 *        4. Query sum[l, r] in O(logN)
 * @note: Index run from 1->N
 */
class FenwickTree {
private:
    std::vector<int> bit_a_;  // binary indexed tree
    std::vector<int> bit_b_;  // binary indexed tree
    int n_;

    /**
     * @brief Returns prefix sum from a raw Fenwick backing array.
     */
    int sum(const std::vector<int>& bit, int index) const {
        int result = 0;
        while (index > 0) {
            result += bit[index];
            index -= index & -index;
        }
        return result;
    }

    /**
     * @brief Adds `delta` at one index in a raw Fenwick backing array.
     */
    void add(std::vector<int>& bit, int index, int delta) {
        while (index <= n_) {
            bit[index] += delta;
            index += index & -index;
        }
    }

public:
    /**
     * @brief Creates a 1-indexed Fenwick tree over `n` positions.
     */
    explicit FenwickTree(int n) : bit_a_(n + 2, 0), bit_b_(n + 2, 0), n_(n + 1) {}

    /**
     * @brief Returns the prefix sum on `[1, index]`.
     */
    int prefix_sum(int index) const {
        return sum(bit_a_, index) * index - sum(bit_b_, index);
    }

    /**
     * @brief Returns the range sum on `[l, r]`.
     */
    int range_sum(int l, int r) const {
        if (l > r) return 0;
        return prefix_sum(r) - prefix_sum(l - 1);
    }

    /**
     * @brief Adds `delta` to every value in `[l, r]`.
     */
    void add_range(int l, int r, int delta) {
        add(bit_a_, l, delta);
        add(bit_a_, r + 1, -delta);
        add(bit_b_, l, delta * (l - 1));
        add(bit_b_, r + 1, -delta * r);
    }

    /**
     * @brief Assigns `a[index] = value`.
     */
    void assign(int index, int value) {
        int current_value = range_sum(index, index);
        add_range(index, index, value - current_value);
    }
};

}  // namespace dsa::tree

#endif  // DSA_TREE_FENWICK_TREE_HPP
