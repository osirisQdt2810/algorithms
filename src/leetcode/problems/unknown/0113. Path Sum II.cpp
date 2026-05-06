#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef long long ll;

class Solution {
    private:
        void downwards(TreeNode* node, vector<vector<int>>& res, vector<int> pref, ll total, int target){
            if (node == nullptr){
                if (total == target) res.push_back(pref);
                return;
            }

            total += node->val;
            pref.push_back(node->val);

            if (node->left == nullptr && node->right == nullptr){
                downwards(nullptr, res, pref, total, target);
            }
            else if (node->left == nullptr){
                downwards(node->right, res, pref, total, target);
            }
            else if (node->right == nullptr){
                downwards(node->left, res, pref, total, target);
            }
            else {
                downwards(node->right, res, pref, total, target);
                downwards(node->left, res, pref, total, target);
            }
            
            total -= node->val;
        }

    public:
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            if (root == nullptr) return {};

            vector<vector<int>> res;
            downwards(root, res, {}, 0, targetSum);
            return res;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();