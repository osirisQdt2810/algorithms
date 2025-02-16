#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            using Color_t = int;
            using Ball_t = int;

            unordered_map<Color_t, set<Ball_t>> c2b;
            unordered_map<Ball_t, Color_t> b2c;

            vector<int> res;
            for (auto& Q : queries){
                Ball_t b = Q[0]; 
                Color_t c = Q[1];

                if (b2c.find(b) != b2c.end()){
                    c2b[b2c[b]].erase(b);
                    if (c2b[b2c[b]].empty())
                        c2b.erase(b2c[b]);
                }

                b2c[b] = c;
                c2b[c].insert(b);

                res.push_back(c2b.size());
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
    vector<int> nums = {2,3,4,6};

    int limits = 4;
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};

    for (auto r : sol.queryResults(limits, queries))
        cout << r << " ";

    return 0;
}