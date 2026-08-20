#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
LC 236 - Lowest Common Ancestor of a Binary Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Problem:
    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
    in the tree.
    According to the definition of LCA on Wikipedia: "The lowest common ancestor
    is defined between two nodes p and q as the lowest node in T that has both p
    and q as descendants (where we allow a node to be a descendant of itself)."

    Constraints:
        The number of nodes in the tree is in the range [2, 10^5].
        -10^9 <= Node.val <= 10^9
        All Node.val are unique.
        p != q
        p and q will exist in the tree.

Examples:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.

    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
    of itself according to the LCA definition.

    Input: root = [1,2], p = 1, q = 2
    Output: 1

Best solution:
    Single postorder DFS that returns "the witness found in this subtree" - one
    pass, no parent map, no second traversal.

Time & Space complexity:
    Time:  O(n) - each node is visited exactly once.
    Space: O(h) - recursion stack only, h = tree height (O(n) worst case).

Approach (detail):
    1. Define lca(c) to return: p or q if exactly one of them was found in c's
       subtree, the answer node if both were found, and nullptr if neither was.
    2. Base case: if c is null return nullptr; if c is p or q return c. Returning c
       immediately (without descending) is what makes "a node is a descendant of
       itself" work - if the other target sits below c, c is still reported upward
       as the single witness and becomes the answer at c itself.
    3. Recurse into both children, giving left and right.
    4. Combine:
       - left and right both non-null: p and q were found in different subtrees, so
         c is the lowest node having both as descendants -> return c.
       - exactly one non-null: only that side contains a witness -> propagate it up
         unchanged.
       - both null: this subtree contains neither -> return nullptr.
    5. Correctness: the "both non-null" case can fire at most once on any root-to-
       node path, and it fires at the deepest node where the two search paths
       diverge, which is precisely the LCA. Above that node only one child returns
       non-null, so the answer propagates to the root untouched.
    6. Because the tree is unordered, no comparison can prune a subtree - every node
       may hide a target - so visiting all n nodes is required and O(n) is optimal.

Your solution:
    MATCHES BEST - the code is exactly this one-pass postorder recursion: it
    short-circuits when the current node matches p or q, recurses into both
    children, and returns the current node when both sides come back non-null,
    otherwise propagating whichever side is non-null. Time O(n), Space O(h).
    Matching targets by value (p->val / q->val) rather than by pointer is safe here
    because the constraints guarantee all node values are unique.
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
