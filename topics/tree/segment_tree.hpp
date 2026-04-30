#ifndef DSA_TREE_SEGMENT_TREE_HPP
#define DSA_TREE_SEGMENT_TREE_HPP

#include <ostream>
#include <utility>
#include <vector>

namespace dsa::tree {

/**
 * @brief Support for two operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Query information in [x, y] (information: min, max, sum) in O(logN)
 * @note: Index run from 1->N
 */
class SegmentTree {
private:
    struct Node {
        int l, r;
        int value{0};
    };

    std::vector<Node> nodes_;
    std::vector<int> leaves_;

    /**
     * @brief Builds segment tree nodes for interval `[l, r]`.
     */
    void build(int t, int l, int r) {
        nodes_[t].l = l;
        nodes_[t].r = r;

        if (l == r) {
            leaves_[l] = t;
            return;
        }

        int mid = (l + r) / 2;
        build(2 * t, l, mid);
        build(2 * t + 1, mid + 1, r);
    }

    /**
     * @brief Queries `[l, r]` while currently at tree node `t`.
     */
    int query(int t, int l, int r) {
        if (l > r || r < nodes_[t].l || nodes_[t].r < l) return 0;
        if (l <= nodes_[t].l && nodes_[t].r <= r) return nodes_[t].value;
        return query(2 * t, l, r) + query(2 * t + 1, l, r);
    }

public:
    explicit SegmentTree(int n) : nodes_(4 * n + 5), leaves_(n + 1) {
        build(1, 1, n);
    }

    void update(int index, int value) {
        int t = leaves_[index];
        nodes_[t].value = value;
        while (t != 1) {
            t /= 2;
            nodes_[t].value = nodes_[2 * t].value + nodes_[2 * t + 1].value;
        }
    }

    int query(int l, int r) {
        return query(1, l, r);
    }
};

/**
 * @brief Segment tree that returns both aggregate value and selected index.
 *
 * Ties are resolved toward the left child.
 */
class IndexedSegmentTree {
private:
    struct Node {
        int l, r;
        int index{-1};
        int value{0};
    };

    std::vector<Node> nodes_;
    std::vector<int> leaves_;

    void build(int t, int l, int r) {
        nodes_[t].l = l;
        nodes_[t].r = r;

        if (l == r) {
            leaves_[l] = t;
            nodes_[t].index = l;
            return;
        }

        int mid = (l + r) / 2;
        build(2 * t, l, mid);
        build(2 * t + 1, mid + 1, r);
    }

    /**
     * @brief Queries `[l, r]` while currently at tree node `t`.
     */
    std::pair<int, int> query(int t, int l, int r) {
        if (l > r || r < nodes_[t].l || nodes_[t].r < l) return {0, -1};
        if (l <= nodes_[t].l && nodes_[t].r <= r) return {nodes_[t].value, nodes_[t].index};

        auto left = query(2 * t, l, r);
        auto right = query(2 * t + 1, l, r);
        return (left.first >= right.first) ? left : right;
    }

public:
    explicit IndexedSegmentTree(int n) : nodes_(4 * n + 5), leaves_(n + 1) {
        build(1, 1, n);
    }

    void update(int index, int value) {
        int t = leaves_[index];
        nodes_[t].value = value;
        while (t != 1) {
            t /= 2;
            if (nodes_[2 * t].value >= nodes_[2 * t + 1].value) {
                nodes_[t].value = nodes_[2 * t].value;
                nodes_[t].index = nodes_[2 * t].index;
            } else {
                nodes_[t].value = nodes_[2 * t + 1].value;
                nodes_[t].index = nodes_[2 * t + 1].index;
            }
        }
    }

    std::pair<int, int> query(int l, int r) {
        return query(1, l, r);
    }
};

/**
 * @brief Segment tree with lazy range-add propagation.
 *
 * Supports point assignment, range add, and range sum query over 1-indexed
 * positions.
 */
class LazySegmentTree {
private:
    struct Node {
        int l, r;
        int value{0};
        int lazy{0};
    };

    std::vector<Node> nodes_;
    std::vector<int> leaves_;
    int n_{0};

    void build(int t, int l, int r) {
        nodes_[t].l = l;
        nodes_[t].r = r;

        if (l == r) {
            leaves_[l] = t;
            return;
        }

        int mid = (l + r) / 2;
        build(2 * t, l, mid);
        build(2 * t + 1, mid + 1, r);
    }

    /**
     * @brief Pushes the pending lazy delta at node `t` to its children.
     */
    void push_down(int t) {
        int lazy = nodes_[t].lazy;
        if (lazy == 0) return;

        nodes_[t].lazy = 0;
        for (int child : {2 * t, 2 * t + 1}) {
            nodes_[child].lazy += lazy;
            nodes_[child].value += lazy * (nodes_[child].r - nodes_[child].l + 1);
        }
    }

    int query(int t, int l, int r) {
        if (l > r || r < nodes_[t].l || nodes_[t].r < l) return 0;
        if (l <= nodes_[t].l && nodes_[t].r <= r) return nodes_[t].value;

        push_down(t);
        return query(2 * t, l, r) + query(2 * t + 1, l, r);
    }

public:
    LazySegmentTree() = default;

    explicit LazySegmentTree(int n) : nodes_(4 * n + 5), leaves_(n + 1), n_(n) {
        build(1, 1, n);
    }

    void update(int t, int index, int value) {
        int l = nodes_[t].l;
        int r = nodes_[t].r;
        if (index < l || r < index) return;

        if (l == r) {
            nodes_[t].value = value;
            return;
        }

        push_down(t);
        update(2 * t, index, value);
        update(2 * t + 1, index, value);
        nodes_[t].value = nodes_[2 * t].value + nodes_[2 * t + 1].value;
    }

    void update(int t, int ql, int qr, int delta) {
        int l = nodes_[t].l;
        int r = nodes_[t].r;
        if (r < ql || qr < l) return;

        if (ql <= l && r <= qr) {
            nodes_[t].value += delta * (r - l + 1);
            nodes_[t].lazy += delta;
            return;
        }

        push_down(t);
        update(2 * t, ql, qr, delta);
        update(2 * t + 1, ql, qr, delta);
        nodes_[t].value = nodes_[2 * t].value + nodes_[2 * t + 1].value;
    }

    int query(int l, int r) {
        return query(1, l, r);
    }

    friend std::ostream& operator<<(std::ostream& os, const LazySegmentTree& tree) {
        os << "tree: \n";
        for (int id = 1; id <= tree.leaves_[tree.n_]; ++id) {
            os << "\t- [" << tree.nodes_[id].l << ", " << tree.nodes_[id].r << "]\t("
               << id << "): value = " << tree.nodes_[id].value
               << ", lazy = " << tree.nodes_[id].lazy << "\n";
        }
        os << "\n";
        return os;
    }
};

}  // namespace dsa::tree

#endif  // DSA_TREE_SEGMENT_TREE_HPP
