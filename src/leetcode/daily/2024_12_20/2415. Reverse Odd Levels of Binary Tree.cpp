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

    // vector<int> nums = {2,1,3,5,6};
    // int k = 5, multiplier = 2;

    // vector<int> nums = {100000, 2000};
    // int k = 2, multiplier = 1000000;

    vector<int> arr = {1,0,2,3,4};

    cout << sol.maxChunksToSorted(arr);

    return 0;
}