#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE -INT_MAX
#define MAXIMUM_ARRAY 50500
#define OPERATOR(a, b) max(a, b)                         
#define OPERATOR_UPDATE_IT(lazy, l, r) lazy * (r - l + 1)  // for sum: it += lazy * (r - l + 1), for min/max: it += lazy

using IT = int;

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
            build(1, 1, n);
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
    int maxScoreSightseeingPair2(vector<int>& values) {
        int N = values.size();
        SegmentTree tree(N);
        for (int i = 1; i <= N; ++i)
            tree.update(i, values[i - 1] + i - 1);
        
        int maxScore = NEG_CASE;
        for (int j = 1; j < N; ++j)
            // find i in [0, j - 1] satisfy: a[i] + a[j] + i - j max <=> a[i] + i max
            maxScore = max(maxScore, values[j] - j + tree.query(1, 1, j));
        
        return maxScore;
    }

    int maxScoreSightseeingPair(vector<int>& values) {
        int N = values.size();
        int maxScore = NEG_CASE;
        int currMax = values[0];
        for (int j = 1; j < N; ++j){
            // find i in [0, j - 1] satisfy: a[i] + a[j] + i - j max <=> a[i] + i max
            maxScore = max(maxScore, values[j] - j + currMax);
            currMax = max(currMax, values[j] + j);
        }
        
        return maxScore;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // vector<int> nums = {1, 1, 1, 1, 1}; int target = 3;
    // vector<int> values = {8,1,5,2,6};
    vector<int> values = {1, 2};

    Solution sol;
    cout << sol.maxScoreSightseeingPair(values);

    return 0;
}