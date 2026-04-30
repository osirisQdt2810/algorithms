#ifndef DSA_TREE_TREE_TYPES_HPP
#define DSA_TREE_TREE_TYPES_HPP

#include <cstddef>
#include <vector>

namespace dsa::tree {

/**
 * @brief Traversal Order
 */
enum class TraversalOrder {
    Preorder,
    Inorder,
    Postorder
};

/**
 * @brief Definition for a binary tree node.
 */
template <typename T>
class BinaryTreeNode {
private:
    void preorder(BinaryTreeNode* node, std::vector<T>& values) {
        if (node == nullptr) return;
        values.push_back(node->value);
        preorder(node->left, values);
        preorder(node->right, values);
    }

    void inorder(BinaryTreeNode* node, std::vector<T>& values) {
        if (node == nullptr) return;
        inorder(node->left, values);
        values.push_back(node->value);
        inorder(node->right, values);
    }

    void postorder(BinaryTreeNode* node, std::vector<T>& values) {
        if (node == nullptr) return;
        postorder(node->left, values);
        postorder(node->right, values);
        values.push_back(node->value);
    }

    std::size_t count_nodes(const BinaryTreeNode* node) const {
        if (node == nullptr) return 0;
        return count_nodes(node->left) + count_nodes(node->right) + 1;
    }

public:
    T value;
    int height;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode() : value(0), height(1), left(nullptr), right(nullptr) {}

    explicit BinaryTreeNode(T value) : value(value), height(1), left(nullptr), right(nullptr) {}

    BinaryTreeNode(T value, BinaryTreeNode* left, BinaryTreeNode* right)
        : value(value), height(1), left(left), right(right) {}

    std::vector<T> traverse(TraversalOrder order) {
        std::vector<T> result;
        switch (order) {
            case TraversalOrder::Preorder:
                preorder(this, result);
                break;
            case TraversalOrder::Inorder:
                inorder(this, result);
                break;
            case TraversalOrder::Postorder:
                postorder(this, result);
                break;
        }
        return result;
    }

    std::size_t size() const {
        return count_nodes(this);
    }
};

template <typename T>
class TreeBase {
public:
    virtual ~TreeBase() = default;

    virtual void insert(T key) = 0;

    virtual void remove(T key) = 0;

    virtual bool find(T key) = 0;

    virtual std::vector<T> traverse(TraversalOrder order) = 0;

    virtual std::size_t size() = 0;
};

}  // namespace dsa::tree

#endif  // DSA_TREE_TREE_TYPES_HPP
