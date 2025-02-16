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

class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            
            vector<int> res;
            while (!q.empty()){
                auto len = q.size();

                int currMax = INT_MIN;
                for (int i = 0; i < len; ++i){
                    auto node = q.front(); q.pop();
                    currMax = max(currMax, node->val);
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }

                res.push_back(currMax);
            }

            return res;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();