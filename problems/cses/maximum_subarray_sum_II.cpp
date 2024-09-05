#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE -1e15
#define MAXIMUM_ARRAY 200200
#define OPERATOR(a, b) max(a, b)
#define OPERATOR_UPDATE_IT(lazy, l, r) lazy * (r - l + 1)  // for sum: it += lazy * (r - l + 1), for min/max: it += lazy
typedef long long IT;

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

int main(){
    // freopen("./revision/problems/cses/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, a, b;
    IT s[MAXIMUM_ARRAY];
    s[0] = 0;

    cin >> n >> a >> b;
    SegmentTree tree(n);
    for (int u, i = 1; i <= n; ++i){
        cin >> u;
        s[i] = s[i-1] + u;
        tree.update(i, s[i]);
        // std::cout << s[i] << " ";
    }

    // std::cout << "\na = " << a << " b = " << b << std::endl;

    IT ans = NEG_CASE;
    for (int i = 0; i <= n; ++i){
        int l = max(1, i + a), r = min(n, i + b);
        ans = OPERATOR(ans, tree.query(1, l, r) - s[i]);
        // std::cout << "i = " << i << " l = " << l << " r = " << r << " max = " << tree.query(1, l, r) << "\n";
    }

    std::cout << ans;
    return 0;
}