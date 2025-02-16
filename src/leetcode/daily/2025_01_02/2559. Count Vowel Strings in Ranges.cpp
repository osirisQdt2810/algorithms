#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE 0
#define MAXIMUM_ARRAY 10100
#define OPERATOR(a, b) a + b 

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

        // query[x, y] in known range[lt, rt]
        IT query(int t, int x, int y){
            if (x > y) return NEG_CASE;
            if (y < node[t].l || node[t].r < x) return NEG_CASE;
            if (x <= node[t].l && node[t].r <= y) return node[t].it;
            return OPERATOR(query(2 * t, x, y), query(2 * t + 1, x, y));
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
        IT query(int l, int r){
            return query(1, l, r);
        }
};

class Solution {
private:
    // 'a', 'e', 'i', 'o', and 'u'.
    bool isVowelledWord(string& word){
        char s = word.front(), e = word.back();
        return !(
            (s != 'a' && s != 'e' && s != 'i' && s != 'o' && s != 'u') ||
            (e != 'a' && e != 'e' && e != 'i' && e != 'o' && e != 'u')
        );
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        SegmentTree tree(n);
        for (int i = 0; i < n; ++i)
            tree.update(i + 1, isVowelledWord(words[i]) ? 1 : 0);

        vector<int> res; res.reserve(queries.size());
        for (auto& Q : queries)
            res.push_back(tree.query(Q[0] + 1, Q[1] + 1));

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
    // vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> costs = {{0,2},{1,4},{1,1}};

    Solution sol;
    for (auto s : sol.vowelStrings(words, costs))
        cout << s << " ";

    return 0;
}