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

typedef pair<TreeNode*, int> ii;

class Solution {
    private:
        map<int, vector<int>> getNodeLevels(TreeNode* root){
            map<int, vector<int>> mapHeight;
            queue<ii> q;
            q.push({root, 0});

            int currH = 0;
            while (!q.empty()){
                auto [u, hu] = q.front(); q.pop();
                mapHeight[hu].push_back(u->val);

                if (u->left != nullptr)
                    q.push({u->left, hu + 1});
                
                if (u->right != nullptr)
                    q.push({u->right, hu + 1});
            }

            return mapHeight;
        }

        int countMinimumOperations(vector<int> values){
            
        }

    public:
        int minimumOperations(TreeNode* root) {
            auto mapHeight = getNodeLevels(root);
            int numOps = 0;
            for (auto& [height, values] : mapHeight)
                numOps += countMinimumOperations(values);
            
            return numOps;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();