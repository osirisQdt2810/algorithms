#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE 0
#define MAXIMUM_ARRAY 1000100
#define OPERATOR(a, b) a + b
typedef int OPR_TYPE;

/**
 * @brief Suitable for two operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Query information in [x, y] (information: min, max, sum)
 */
class SegmentTree {
    private:
        int l[4 * MAXIMUM_ARRAY], r[4 * MAXIMUM_ARRAY];
        int leaf[MAXIMUM_ARRAY];
        OPR_TYPE it[4 * MAXIMUM_ARRAY];

        void build(int t, int x, int y){
            l[t] = x; r[t] = y; it[t] = NEG_CASE;
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
        void update(int i, OPR_TYPE k){
            int t = leaf[i];
            it[t] = k;
            while (t != 1){
                t /= 2;
                it[t] = OPERATOR(it[2 * t], it[2 * t + 1]);
            }
        }

        // query[x, y] in known range[lt, rt]
        OPR_TYPE query(int t, int x, int y){
            if (x > y) return NEG_CASE;
            if (y < l[t] || r[t] < x) return NEG_CASE;
            if (x <= l[t] && r[t] <= y) return it[t];
            return OPERATOR(query(2 * t, x, y), query(2 * t + 1, x, y));
        }
};

class LazySegmentTree {
    
};

class FenwichTree {

};