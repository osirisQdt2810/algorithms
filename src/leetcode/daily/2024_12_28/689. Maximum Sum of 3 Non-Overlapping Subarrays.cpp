#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE -INT_MAX
#define MAXIMUM_ARRAY 15000
#define OPERATOR(a, b) max(a, b)                         

using IT = int;

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
            int idx = -1;
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
                node[t].idx = x;
                return;
            }
            build(2 * t, x, (x + y) / 2);
            build(2 * t + 1, (x + y) / 2 + 1, y);
        }

        // query[x, y] in known range[lt, rt]
        pair<IT, int> query(int t, int x, int y){
            if (x > y) return {NEG_CASE, -1};
            if (y < node[t].l || node[t].r < x) return {NEG_CASE, -1};
            if (x <= node[t].l && node[t].r <= y) return {node[t].it, node[t].idx};
            auto ln = query(2 * t, x, y);
            auto rn = query(2 * t + 1, x, y);
            return (ln.first >= rn.first) ? ln : rn;
        }
        
    public:
        SegmentTree(int n){
            build(1, 1, n);
        }


        // update a[i] = k 
        void update(int i, IT k){
            int t = leaf[i];
            node[t].it = k;
            while (t != 1){
                t /= 2;
                if (node[2 * t].it >= node[2 * t + 1].it){
                    node[t].it = node[2 * t].it;
                    node[t].idx = node[2 * t].idx; 
                }
                else {
                    node[t].it = node[2 * t + 1].it;
                    node[t].idx = node[2 * t + 1].idx;  
                }
            }
        }

        // query[x, y] in known range[lt, rt]
        pair<IT, int> query(int l, int r){
            return query(1, l, r);
        }
};

struct Tuple {
    long long max;
    int b, c;
};

typedef pair<int, int> ii;

class Solution {
public:
    vector<int> maxSumOfThreeSubarraysUseSegmentTree(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> sumK(N - k + 1, 0);
        for (int i = 0; i < k; ++i)
            sumK[0] += nums[i];
        
        SegmentTree tree(N - k + 1);
        tree.update(1, sumK[0]);
        for (int i = 1; i < N - k + 1; ++i){
            sumK[i] = sumK[i-1] - nums[i - 1] + nums[i + k - 1];
            tree.update(i + 1, sumK[i]);
        }

        int idx_1, idx_2, idx_3;
        int target = NEG_CASE;
        for (int i = 0; i < N; ++i){
            for (int j = i + k; j < N; ++j){
                if (j + 2 * k > N) break;
                auto maxSumK = tree.query(j + k + 1, N - k + 1);
                auto currMaxSumK = sumK[i] + sumK[j] + maxSumK.first;
                if (target < currMaxSumK){
                    // cout << " i = " << i << ", j = " << j << ", k = " <<  maxSumK.second - 1 << " -> currSumK = " << currMaxSumK << " > target = " << target << "\n";
                    target = currMaxSumK;
                    idx_1 = i; idx_2 = j; idx_3 = maxSumK.second - 1;
                }
            }
        }
        return {idx_1, idx_2, idx_3};
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> sumK(N - k + 1, 0);
        for (int i = 0; i < k; ++i) sumK[0] += nums[i];
        for (int i = 1; i < N - k + 1; ++i) sumK[i] = sumK[i-1] - nums[i - 1] + nums[i + k - 1];
        
        // cout << "\n";
        // for (int i = 0; i <= N - k; ++i) cout << sumK[i] << " ";
        // cout << "\n";

        vector<Tuple> maxTwoSum(N - k + 1);
        maxTwoSum[N - 2 * k] = {sumK[N - 2 * k] + sumK[N - k], N - 2 * k, N - k};
        ii currMaxTwoSum = {sumK[N - k], N - k};
        for (int i = N - 2 * k - 1; i >= 0; --i){
            if (currMaxTwoSum.first <= sumK[i + k])
                currMaxTwoSum = {sumK[i + k], i + k};
            
            if (maxTwoSum[i + 1].max <= sumK[i] + currMaxTwoSum.first){
                maxTwoSum[i] = {sumK[i] + currMaxTwoSum.first, i, currMaxTwoSum.second};
            }
            else {
                maxTwoSum[i] = maxTwoSum[i + 1];
            }
        }

        // for (int i = 0; i <= N - k; ++i){
        //     auto tuple = maxTwoSum[i];
        //     cout << tuple.b << " " << tuple.c << " -> " << tuple.max << "\n";
        // }

        int res = NEG_CASE;
        int idx_1, idx_2, idx_3;
        for (int i = 0; i < N; ++i){
            if (i + k > N - k) break;
            int currSum = sumK[i] + maxTwoSum[i + k].max;
            if (res < currSum){
                res = currSum;
                idx_1 = i;
                idx_2 = maxTwoSum[i + k].b;
                idx_3 = maxTwoSum[i + k].c;
            }
        }
        return {idx_1, idx_2, idx_3};
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // vector<int> nums = {1,2,1,2,6,7,5,1}; int k = 2;        // 
    // vector<int> nums = {1,2,1,2,1,2,1,2,1}; int k = 2;       
    vector<int> nums = { 7,13,20,19,19,2,10,1,1,19 }; int k = 3;      

    Solution sol;
    auto res = sol.maxSumOfThreeSubarrays(nums, k);
    
    cout << "\n";
    for (auto r : res)
        cout << r << " ";
    cout << "\n";

    // vector<int> nums = {1, 1, 1, 1, 1};
    // SegmentTree tree(nums.size());
    // for (int i = 0; i < nums.size(); ++i)
    //     tree.update(i + 1, nums[i]);

    // auto [val, u] = tree.query(1, 5);
    // cout << "val = " << val << " -> u = " << u << endl;

    return 0;
}