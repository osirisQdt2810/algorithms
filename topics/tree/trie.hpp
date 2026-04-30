#ifndef DSA_TREE_TRIE_HPP
#define DSA_TREE_TRIE_HPP

#include <string>
#include <vector>

namespace dsa::tree {

/**
 * @brief Trie for lowercase English strings.
 */
class Trie {
private:
    static constexpr int kAlphabetSize = 26;

    /**
     * @brief Trie node with fixed lowercase alphabet children.
     */
    struct Node {
        Node* child[kAlphabetSize];
        int occurrences{0};   // có bao nhiêu xâu là xâu được thể hiện bởi đỉnh này
        int prefix_count{0};  // có bao nhiêu xâu có tiền tố là xâu được thể hiện bởi đỉnh này

        Node() {
            for (int i = 0; i < kAlphabetSize; ++i) {
                child[i] = nullptr;
            }
        }
    };

    Node* root_;

    /**
     * @brief Recursively erases a string and deletes unused nodes.
     */
    bool erase(const std::string& value, Node* current, int index) {
        if (index == static_cast<int>(value.size())) {
            --current->occurrences;
        } else {
            int c = value[index] - 'a';
            bool deleted_child = erase(value, current->child[c], index + 1);
            if (deleted_child) current->child[c] = nullptr;
        }

        if (current != root_) {
            --current->prefix_count;
            if (current->prefix_count == 0) {
                delete current;
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Traverses strings in lexicographic or reverse lexicographic order.
     */
    void traverse_preorder(Node* current, std::string& prefix, std::vector<std::string>& result, bool ascending) {
        if (current == nullptr) return;

        for (int i = 0; i < current->occurrences; ++i) {
            result.push_back(prefix);
        }

        int begin = ascending ? 0 : kAlphabetSize - 1;
        int end = ascending ? kAlphabetSize : -1;
        int step = ascending ? 1 : -1;
        for (int c = begin; c != end; c += step) {
            if (current->child[c] == nullptr) continue;

            prefix += static_cast<char>('a' + c);
            traverse_preorder(current->child[c], prefix, result, ascending);
            prefix.pop_back();
        }
    }

public:
    /**
     * @brief Creates an empty trie.
     */
    Trie() : root_(new Node()) {}

    /**
     * @brief Inserts a lowercase string.
     */
    void insert(const std::string& value) {
        Node* node = root_;
        for (char c : value) {
            int index = c - 'a';
            if (node->child[index] == nullptr) {
                node->child[index] = new Node();
            }

            node = node->child[index];
            ++node->prefix_count;
        }
        ++node->occurrences;
    }

    /**
     * @brief Removes one occurrence of a lowercase string when present.
     */
    void erase(const std::string& value) {
        if (!find(value)) return;
        erase(value, root_, 0);
    }

    /**
     * @brief Checks whether a lowercase string exists in the trie.
     */
    bool find(const std::string& value) {
        Node* node = root_;
        for (char c : value) {
            int index = c - 'a';
            if (node->child[index] == nullptr) return false;
            node = node->child[index];
        }
        return node->occurrences > 0;
    }

    /**
     * @brief Returns all stored strings in sorted order.
     *
     * @param[in] ascending True for ascending lexicographic order, false for descending.
     */
    std::vector<std::string> sort(bool ascending = false) {
        std::vector<std::string> result;
        std::string prefix;
        traverse_preorder(root_, prefix, result, ascending);
        return result;
    }
};

/**
 * @brief Binary trie for non-negative integers up to the configured bit width.
 */
class BinaryTrie {
private:
    static constexpr int kMaxLog = 12;

    struct Node {
        Node* child[2];
        int occurrences{0};
        int count{0};

        Node() {
            for (int i = 0; i < 2; ++i) {
                child[i] = nullptr;
            }
        }
    };

    Node* root_;

    /**
     * @brief Recursively erases a number and deletes unused nodes.
     */
    bool erase(int num, Node* current, int bit) {
        if (bit < 0) {
            --current->occurrences;
        } else {
            int current_bit = (num >> bit) & 1;
            bool deleted_child = erase(num, current->child[current_bit], bit - 1);
            if (deleted_child) current->child[current_bit] = nullptr;
        }

        if (current != root_) {
            --current->count;
            if (current->count == 0) {
                delete current;
                return true;
            }
        }
        return false;
    }

public:
    BinaryTrie() : root_(new Node()) {}

    void insert(int num) {
        Node* node = root_;
        for (int bit = kMaxLog; bit >= 0; --bit) {
            int current_bit = (num >> bit) & 1;
            if (node->child[current_bit] == nullptr) {
                node->child[current_bit] = new Node();
            }

            node = node->child[current_bit];
            ++node->count;
        }
        ++node->occurrences;
    }

    void erase(int num) {
        if (!find(num)) return;
        erase(num, root_, kMaxLog);
    }

    bool find(int num) {
        Node* node = root_;
        for (int bit = kMaxLog; bit >= 0; --bit) {
            int current_bit = (num >> bit) & 1;
            if (node->child[current_bit] == nullptr) return false;
            node = node->child[current_bit];
        }
        return node->occurrences > 0;
    }

    /**
     * @brief Returns the maximum XOR value obtainable with `num`.
     */
    int max_xor(int num) {
        Node* node = root_;
        int result = 0;
        for (int bit = kMaxLog; bit >= 0 && node != nullptr; --bit) {
            int current_bit = (num >> bit) & 1;
            int preferred_bit = current_bit ^ 1;
            if (node->child[preferred_bit] != nullptr) {
                result += 1 << bit;
                node = node->child[preferred_bit];
            } else {
                node = node->child[current_bit];
            }
        }
        return result;
    }
};

}  // namespace dsa::tree

#endif  // DSA_TREE_TRIE_HPP
