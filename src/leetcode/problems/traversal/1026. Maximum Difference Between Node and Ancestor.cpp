#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <utility>

using namespace std;

/*
LC 1026 - Maximum Difference Between Node and Ancestor
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

Problem:
    Given the root of a binary tree, find the maximum value v for which there
    exist different nodes a and b where v = |a.val - b.val| and a is an ancestor
    of b.
    A node a is an ancestor of b if either any child of a is equal to b or any
    child of a is an ancestor of b.

    Constraints:
        The number of nodes in the tree is in the range [2, 5000].
        0 <= Node.val <= 10^5

Examples:
    Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
    Output: 7
    Explanation: Various ancestor-node differences include |8 - 3| = 5,
    |3 - 7| = 4, |8 - 1| = 7, |10 - 13| = 3. The maximum is 7, from |8 - 1|.

    Input: root = [1,null,2,null,0,3]
    Output: 3

Best solution:
    One DFS over the tree - either carrying the running (min, max) of the ancestors
    downward, or returning the (min, max) of each subtree upward. Both are a single
    traversal; no pair is ever enumerated explicitly.

Time & Space complexity:
    Time:  O(n) - each node is visited once and does O(1) work.
    Space: O(h) - recursion stack only, h = height (O(n) on a degenerate chain).

Approach (detail):
    1. For a fixed ancestor a, |a.val - b.val| over all descendants b is maximised
       at an extreme: either the smallest or the largest descendant value. So only
       two numbers per ancestor matter, not the whole descendant set.
    2. Top-down form: descend carrying mn and mx, the min and max value seen on the
       path from the root to the current node's parent. At each node v, the pair
       (mn, v.val) and (mx, v.val) are both ancestor-descendant pairs, so update the
       answer with max(|v.val - mn|, |v.val - mx|), then recurse with the path
       extremes widened by v.val. Since mn and mx are the extremes of v's ancestors,
       every ancestor-descendant pair is covered exactly at its descendant end.
    3. Bottom-up form (equivalent): have dfs(v) return the min and max value over
       v's strict descendants. At v, update the answer with |v.val - minDesc| and
       |v.val - maxDesc|, then return the extremes of v's subtree - which are the
       returned extremes widened by the children's own values. Each pair is covered
       exactly at its ancestor end.
    4. Either way the maximum over all (ancestor, descendant) pairs is found, because
       every such pair is dominated by one involving a path extreme, and every path
       extreme is examined.
    5. n >= 2 guarantees at least one ancestor-descendant pair exists, so the answer
       is always well defined.
    6. O(n) is optimal: every node can be one half of the winning pair, so none can
       be skipped.

Your solution:
    MATCHES BEST - the code is the bottom-up variant of step 3: dfs returns the
    (min, max) over the strict descendants of the current node, folds each child's
    own value into that pair, and updates res with the distance from the node's value
    to both extremes. Time O(n), Space O(h). The INT_MAX / INT_MIN sentinels are
    guarded before use, so a leaf (which has no descendants) contributes nothing,
    and res is guaranteed to be assigned because n >= 2 means the root has a
    descendant.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    using minmax = pair<int, int>;

    minmax dfs(TreeNode* root, int& res){
        minmax mima = {INT_MAX, INT_MIN};
        if (root->left){
            minmax l = dfs(root->left, res);
            mima.first = min(mima.first, min(root->left->val, l.first));
            mima.second = max(mima.second, max(root->left->val, l.second));
        }
        if (root->right){
            minmax r = dfs(root->right, res);
            mima.first = min(mima.first, min(root->right->val, r.first));
            mima.second = max(mima.second, max(root->right->val, r.second));
        }
        if (mima.first != INT_MAX) res = max(res, abs(root->val - mima.first));
        if (mima.second != INT_MIN) res = max(res, abs(root->val - mima.second));
        return mima;
    }

    public:
        int maxAncestorDiff(TreeNode* root) {
            int res = INT_MIN;
            dfs(root, res);
            return res;
        }
};