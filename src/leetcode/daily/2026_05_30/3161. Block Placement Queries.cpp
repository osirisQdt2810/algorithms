#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
    private:
        struct segtree {
            int n;
            vector<int> nodes;

            segtree(int n_) : n(n_), nodes(4*n_+5, -1){
                nodes[0] = 0;
            }

            int query(int t, int l, int r, int X, int Y){
                // case 1: [l...r] [X...Y] or [X...Y] [l..r]
                if (l > r || r < X || Y < l) return -1;
                // case 2: [X...l...r...Y]
                if (X <= l && r <= Y) return nodes[t];
                // case 3: overlap
                int m = (l+r)/2;
                return max(query(2*t,l,m,X,Y), query(2*t+1,m+1,r,X,Y));
            }

            int query(int l, int r){
                return query(1, 1, n, l, r);
            }

            void update(int t, int l, int r, int k, int val){
                if (l == r){
                    nodes[t] = val;
                    return;
                }
                int m = (l+r)/2;
                (k <= m) ? update(2*t,l,m,k,val) : update(2*t+1,m+1,r,k,val);
                nodes[t] = max(nodes[2*t], nodes[2*t+1]);
            }

            void update(int k, int val){
                update(1,1,n,k,val);
            }
        };

    public:
        vector<bool> getResults2(vector<vector<int>>& queries) {
            set<int> points;
            vector<bool> res;

            for (auto& query : queries){
                if (query[0] == 1){
                    int x = query[1];
                    points.insert(x);
                }
                else {
                    int x = query[1], sz = query[2];
                    auto bend = points.upper_bound(x);
                    if (bend == points.begin()){
                        res.push_back((sz <= x));    // assume sz <= x
                        continue;                                                                                                                                                                               continue;
                    }

                    bool is_placeable = false;
                    int curr_pt = 0;
                    for (auto it = points.begin(); it != bend; ++it){
                        int curr_sz = (*it) - curr_pt;
                        if (curr_sz >= sz){
                            is_placeable = true;
                            break;
                        }
                        curr_pt = *it;
                    }
                    res.push_back(is_placeable | (x - curr_pt >= sz));
                }
            }
            return res;
        }

        vector<bool> getResults(vector<vector<int>>& queries) {
            set<int> points;
            vector<bool> res;
            segtree tree(5*1e4+1);

            points.insert(0);

            for (auto& query : queries){
                if (query[0] == 1){
                    int x = query[1];
                    auto it = points.upper_bound(x);
                    if (it != points.end()){
                        tree.update(*it, *it - x);
                    }
                    tree.update(x, x - *prev(it));
                    points.insert(x);
                }
                else {
                    int x = query[1], sz = query[2];
                    if (sz > x){
                        res.push_back(false);
                        continue;
                    }
                    auto bend = points.upper_bound(x);
                    int last = *prev(bend);
                    bool cond1 = (x - last) >= sz;
                    bool cond2 = tree.query(1, last) >= sz;
                    // cout << "x=" << x << " - last=" << last << " - query=" << tree.query(1,last) << "\n";
                    res.push_back(cond1 || cond2);
                }
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

    vector<vector<int>> queries = {{1,7},{2,7,6},{1,2},{2,7,5},{2,7,6}};
    vector<bool> results = sol.getResults(queries);
    for (bool res : results) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}