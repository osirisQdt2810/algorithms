#ifndef DSA_TREE_BINARY_SEARCH_TREE_HPP
#define DSA_TREE_BINARY_SEARCH_TREE_HPP

#include "tree_types.hpp"

#include <limits>
#include <vector>

namespace dsa::tree {

/**
 * @brief Binary search tree storing unique keys.
 */
template <typename T>
class BinarySearchTree : public TreeBase<T> {
protected:
    using Node = BinaryTreeNode<T>;
    Node* root_ = nullptr;

    /**
     * @brief Inserts `key` into the subtree rooted at `parent`.
     */
    virtual Node* insert(Node* parent, T key) {
        if (parent == nullptr) return new Node(key);
        if (parent->value < key) parent->right = insert(parent->right, key);
        if (parent->value > key) parent->left = insert(parent->left, key);
        return parent;
    }

    /**
     * @brief Removes `key` from the subtree rooted at `parent`.
     */
    virtual Node* remove(Node* parent, T key) {
        if (parent == nullptr) return nullptr;

        if (parent->value < key) {
            parent->right = remove(parent->right, key);
        } else if (parent->value > key) {
            parent->left = remove(parent->left, key);
        } else {
            if (parent->left != nullptr && parent->right != nullptr) {
                Node* successor = minimum_node(parent->right);
                parent->value = successor->value;
                parent->right = remove(parent->right, successor->value);
            } else {
                Node* child = (parent->left != nullptr) ? parent->left : parent->right;
                delete parent;
                return child;
            }
        }
        return parent;
    }

    /**
     * @brief Finds the node containing `key` in the subtree rooted at `parent`.
     */
    Node* search(Node* parent, T key) {
        if (parent == nullptr) return nullptr;
        if (parent->value == key) return parent;
        if (parent->value < key) return search(parent->right, key);
        return search(parent->left, key);
    }

    /**
     * @brief Returns the minimum-valued node in a subtree.
     */
    Node* minimum_node(Node* parent) {
        Node* node = parent;
        while (node != nullptr && node->left != nullptr) node = node->left;
        return node;
    }

    /**
     * @brief Returns the maximum-valued node in a subtree.
     */
    Node* maximum_node(Node* parent) {
        Node* node = parent;
        while (node != nullptr && node->right != nullptr) node = node->right;
        return node;
    }

public:
    /**
     * @brief Creates an empty binary search tree.
     */
    BinarySearchTree() = default;

    /**
     * @brief Creates a binary search tree by inserting all values in order.
     */
    explicit BinarySearchTree(const std::vector<T>& values) {
        for (const auto& value : values) {
            root_ = insert(root_, value);
        }
    }

    /**
     * @brief Inserts `key` into the tree.
     */
    void insert(T key) override {
        root_ = insert(root_, key);
    }

    /**
     * @brief Removes `key` from the tree when present.
     */
    void remove(T key) override {
        root_ = remove(root_, key);
    }

    /**
     * @brief Checks whether `key` exists in the tree.
     */
    bool find(T key) override {
        return search(root_, key) != nullptr;
    }

    /**
     * @brief Returns values in the requested traversal order.
     */
    std::vector<T> traverse(TraversalOrder order) override {
        if (root_ == nullptr) return {};
        return root_->traverse(order);
    }

    /**
     * @brief Returns the number of nodes in the tree.
     */
    std::size_t size() override {
        return (root_ == nullptr) ? 0 : root_->size();
    }

    /**
     * @brief Returns the minimum key, or numeric max when the tree is empty.
     */
    T minimum() {
        Node* node = minimum_node(root_);
        return (node == nullptr) ? std::numeric_limits<T>::max() : node->value;
    }

    /**
     * @brief Returns the maximum key, or numeric lowest when the tree is empty.
     */
    T maximum() {
        Node* node = maximum_node(root_);
        return (node == nullptr) ? std::numeric_limits<T>::lowest() : node->value;
    }
};

}  // namespace dsa::tree

#endif  // DSA_TREE_BINARY_SEARCH_TREE_HPP
