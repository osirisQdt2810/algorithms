#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE 1
#define MAXIMUM_ARRAY 100100
#define OPERATOR(a, b) a * b                            
#define OPERATOR_UPDATE_IT(lazy, l, r) lazy * (r - l + 1)  // for sum: it += lazy * (r - l + 1), for min/max: it += lazy
using IT = int8_t;

/**
 * @brief Support for two operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Query information in [x, y] (information: min, max, sum) in O(logN)
 * @note: Index run from 1->N
 */
class SegmentTree {
    private:
        struct Node {
            int l, r;
            IT it;
        };

    private:
        Node node[4 * MAXIMUM_ARRAY];
        int leaf[MAXIMUM_ARRAY];

        void build(int t, int x, int y){
            node[t].l = x; 
            node[t].r = y; 
            node[t].it = NEG_CASE;

            if (x == y){
                leaf[x] = t;
                return;
            }
            build(2 * t, x, (x + y) / 2);
            build(2 * t + 1, (x + y) / 2 + 1, y);
        }

    public:
        SegmentTree(int n){
            if (n > 0){
                build(1, 1, n);
            }
        }


        // update a[i] = k 
        void update(int i, IT k){
            int t = leaf[i];
            node[t].it = k;
            while (t != 1){
                t /= 2;
                node[t].it = OPERATOR(node[2 * t].it, node[2 * t + 1].it);
            }
        }

        // query[x, y] in known range[lt, rt]
        IT query(int t, int x, int y){
            if (x > y) return NEG_CASE;
            if (y < node[t].l || node[t].r < x) return NEG_CASE;
            if (x <= node[t].l && node[t].r <= y) return node[t].it;
            return OPERATOR(query(2 * t, x, y), query(2 * t + 1, x, y));
        }
};

class Solution {
public:
    vector<bool> prodSegmentTree_isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        SegmentTree tree(N - 1);
        for (int i = 1; i < N; ++i){
            // cout << "update: i = " << i << " : " << abs(nums[i] - nums[i - 1]) % 2 << "\n";
            tree.update(i, abs(nums[i] - nums[i - 1]) % 2);
        }

        vector<bool> res;
        for (auto& query : queries){
            int from = query[0], to = query[1];
            int8_t prod = (from >= to) ? 1 : tree.query(1, from + 1, to);
            // cout << "from: " << from + 1 << " -> to: " << to << " => prod: " << prod << "\n";
            res.push_back(prod);
        }

        return res;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> prefixSum(N, 0);
        for (int i = 1; i < N; ++i){
            prefixSum[i] = prefixSum[i - 1] + (abs(nums[i] - nums[i - 1]) % 2);
        }

        vector<bool> res;
        for (auto& query : queries){
            int from = query[0], to = query[1];
            bool correct = (from >= to) ? true : (prefixSum[to] - prefixSum[from] == to - from);
            // cout << "from: " << from + 1 << " -> to: " << to << " => prod: " << prod << "\n";
            res.push_back(correct);
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

int main(){
    Solution sol;

    // vector<int> nums = {3,4,1,2,6}; vector<vector<int>> queries = {{0,4}};
    vector<int> nums = {4, 3, 1, 6}; vector<vector<int>> queries = {{0,2}, {2,3}};
    // vector<int> nums = {1}; vector<vector<int>> queries = {{0,0}};

    cout << "\n\n";
    for (auto t : sol.isArraySpecial(nums, queries)){
        cout << t << " ";
    }

    return 0;
}