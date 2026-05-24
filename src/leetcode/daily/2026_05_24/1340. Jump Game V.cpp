#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    using ii = pair<int, int>;

    struct segtree {
        int n;
        vector<ii> nodes;

        void build(int t, int l, int r){
            if (l == r){
                nodes[t] = {INT_MAX, l};
                return;
            }
            int m = (l+r) / 2;
            build(2*t, l, m);
            build(2*t+1, m+1, r);
        }

        segtree(int n_): n(n_), nodes(4*n_ + 5){
            build(1, 1, n);
        }

        void update(int t, int l, int r, int k, int val){
            if (l == r){
                nodes[t] = {val, l};
                return;
            }
            int m = (l+r) / 2;
            if (k <= m){
                update(2*t, l, m, k, val);
            }
            else {
                update(2*t+1, m+1, r, k, val);
            }
            nodes[t] = min(nodes[2*t], nodes[2*t+1]);
        }

        void update(int k, int val){
            return update(1, 1, n, k+1, val);
        }

        ii query(int t, int l, int r, int X, int Y){
            // case 1: l...r X...Y or X...Y l...r
            if (l > r || r < X || Y < l) return {INT_MAX, -1};
            // case 2: X...l...r...Y
            if (X <= l && r <= Y) return nodes[t];
            // case 3: overlap
            int m = (l+r)/2;
            return min(query(2*t, l, m, X, Y), query(2*t+1, m+1, r, X, Y));
        }

        int query(int X, int Y){
            if (X > Y) return -1;
            return query(1, 1, n, X+1, Y+1).second;
        }
    };

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<ii> arrwindex(n);
        for (int i = 0; i < n; ++i) arrwindex[i] = {arr[i], i};
        sort(arrwindex.begin(), arrwindex.end(), [](const ii& lhs, const ii& rhs){
            return lhs.first < rhs.first;
        });

        vector<int> dp(n, 1);
        segtree tree(n);

        int ans = 0;
        for (int l = 0; l < n; ++l){
            auto [num, i] = arrwindex[l];
            int j = tree.query(max(0, i-d), i-1);
            int k = tree.query(i+1, min(i+1, n-1));
            cout << "i = " << i << "\n";
            if (j > 0 && arr[i] > arr[j-1]){
                dp[i] = max(dp[i], dp[j-1] + 1);
                cout << " -> j=" << j-1 << " -> dp=" << dp[j-1] << " -> after dp[i]=" << dp[i] << "\n";
            }
            if (k > 0 && arr[i] > arr[k-1]){
                dp[i] = max(dp[i], dp[k-1] + 1);
                cout << " -> k=" << k-1 << " -> dp=" << dp[k-1] << " -> after dp[i]=" << dp[i] << "\n";
            }
            ans = max(ans, dp[i]);
            tree.update(i, dp[i]);
        }
        return ans;
    }
};