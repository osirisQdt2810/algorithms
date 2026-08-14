#include <iostream>
#include <vector>

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
    TreeNode* recursive(TreeNode* node, int height){
        if (node == nullptr) return node;
        if (height % 2 == 0 && node->left && node->right){
            int tmp = node->left->val;
            node->left->val = node->right->val;
            node->right->val = tmp;
        }

        recursive(node->left, height + 1);
        recursive(node->right, height + 1);
        return node;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        return recursive(root, 0);
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;

    // root = [2,3,5,8,13,21,34] -> expected [2,5,3,8,13,21,34]
    TreeNode* root = new TreeNode(2,
        new TreeNode(3, new TreeNode(8), new TreeNode(13)),
        new TreeNode(5, new TreeNode(21), new TreeNode(34)));

    root = sol.reverseOddLevels(root);

    // level-order print
    vector<TreeNode*> level{root};
    while (!level.empty()){
        vector<TreeNode*> next;
        for (TreeNode* node : level){
            cout << node->val << " ";
            if (node->left) next.push_back(node->left);
            if (node->right) next.push_back(node->right);
        }
        level = next;
    }
    cout << "\n";

    return 0;
}