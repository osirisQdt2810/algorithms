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
        void downwards(TreeNode* node, int& counter, const vector<ll>& parentSum, int target){
            if (node == nullptr) return;
            vector<ll> currSum; currSum.reserve(parentSum.size());
            currSum.push_back(node->val);
            counter += (node->val == target);
            for (const auto& prefixSum : parentSum){
                ll sum = prefixSum + node->val;
                counter += (sum == target);
                currSum.push_back(sum);
            }

            downwards(node->left, counter, currSum, target);
            downwards(node->right, counter, currSum, target);
        }

    public:
        int pathSum2(TreeNode* root, int targetSum) {
            int counter = 0;
            downwards(root, counter, {}, targetSum);
            return counter;
        }

    private:
        map<ll, int> prefixSumCounter;  // prefixSumCounter[u] = k means: In a certain current DFS node V, prefix sum u (from root->V) occurs k times.

        /**
         * @brief 
         * 
         * @param root 
         * @param parentSum 
         * @return int  number of paths that ends at root 
         */
        int dfs(TreeNode* node, ll parentSum, const int& targetSum){
            if (node == nullptr) return 0;

            parentSum += node->val;
            // number of valid paths ends at node
            int count = (prefixSumCounter.find(parentSum - targetSum) == prefixSumCounter.end()) ? 0 : prefixSumCounter[parentSum - targetSum];
            
            // add the counter for current prefix sum (node is the last)
            if (prefixSumCounter.find(parentSum) == prefixSumCounter.end())
                prefixSumCounter[parentSum] = 1;
            else
                ++prefixSumCounter[parentSum];

            // recursion is valid because you could imagine that the result will be: 
            //      number_of_paths_end_at_`node` + dfs(node->left) + dfs(node->right) 
            //    = number_of_paths_end_at_`node` + number_of_paths_end_at_`node->left` + number_of_paths_end_at_`node->right` + dfs(node->left->left) + dfs(node->left->right) + dfs(node->right->left) + dfs(node->right->right)
            //    = .................................
            count += dfs(node->left, parentSum, targetSum) + dfs(node->right, parentSum, targetSum);

            // remove the prefix sum because the `node` has been visited!
            --prefixSumCounter[parentSum];

            return count;
        }

    public:

        int pathSum(TreeNode* root, int targetSum) {
            prefixSumCounter[0] = 1;
            return dfs(root, 0, targetSum);
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();