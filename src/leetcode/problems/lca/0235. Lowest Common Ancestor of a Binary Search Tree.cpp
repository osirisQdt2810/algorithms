#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
LC 235 - Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Problem:
    Given a binary search tree (BST), find the lowest common ancestor (LCA) node
    of two given nodes in the BST.
    According to the definition of LCA on Wikipedia: "The lowest common ancestor
    is defined between two nodes p and q as the lowest node in T that has both p
    and q as descendants (where we allow a node to be a descendant of itself)."

    Constraints:
        The number of nodes in the tree is in the range [2, 10^5].
        -10^9 <= Node.val <= 10^9
        All Node.val are unique.
        p != q
        p and q will exist in the BST.

Examples:
    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.

    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    Output: 2
    Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
    of itself according to the LCA definition.

    Input: root = [2,1], p = 2, q = 1
    Output: 2

Best solution:
    Single top-down walk exploiting the BST ordering - no recursion into both
    subtrees, no parent pointers, no extra storage.

Time & Space complexity:
    Time:  O(h) - one step per level, h = tree height (O(log n) when balanced).
    Space: O(1) - an iterative walk keeps only the current pointer.

Approach (detail):
    1. In a BST every value in the left subtree of a node is smaller than the node
       and every value in the right subtree is larger. So the position of p and q
       relative to the current node is decided by comparing values alone - there is
       never a need to search both sides.
    2. Start at the root. At the current node c:
       - if both p->val and q->val are less than c->val, the LCA lies strictly in
         the left subtree, so move c = c->left;
       - if both are greater than c->val, move c = c->right;
       - otherwise stop and return c.
    3. The stopping case covers exactly the two ways c can be the answer: the values
       split (one below c, one above c), so c is the lowest node with both as
       descendants; or c->val equals p or q, and since the other node is then in c's
       subtree, c is its own ancestor by the problem's definition.
    4. Correctness: the walk only descends when both targets are provably on the
       same side, so it never passes below the true LCA; and it stops at the first
       node where they diverge, so it never stops above it either.
    5. Each iteration drops one level, giving O(h) steps and O(1) memory when
       written as a loop.

Your solution:
    SUBOPTIMAL - the code runs the generic binary-tree LCA (the LC 236 algorithm):
    a postorder recursion that searches BOTH subtrees at every node and combines
    the results, never comparing values to exploit the BST ordering. It is correct
    (a generic LCA is valid on a BST), but it costs Time O(n) and Space O(h) for the
    recursion stack, versus O(h) time and O(1) space for the BST walk above - so on
    a balanced tree it does O(n) work where O(log n) suffices. It still passes under
    n <= 10^5, though the recursion depth equals the height, which reaches 10^5 on a
    degenerate (chain-shaped) BST and risks a stack overflow.
    The solution body is the same code as "0236. Lowest Common Ancestor of a
    Binary Tree.cpp" in the same folder, where that algorithm IS optimal because
    the tree is unordered; here the BST ordering is available and left unused.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        TreeNode* lca(TreeNode* curr, int p, int q){    // return node chứa p hoặc q
            if (curr == nullptr || curr->val == p || curr->val == q) return curr;

            TreeNode* left = lca(curr->left, p, q);
            TreeNode* right = lca(curr->right, p, q);
            if (left && !right) return left;
            if (!left && right) return right;
            if (!left && !right) return nullptr;
            return curr;
        }

    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return lca(root, p->val, q->val);
        }
};
