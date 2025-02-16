#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    std::vector<int> parents;

    UnionFind(int V){
        parents.resize(V);
        for (int i = 0; i < V; ++i)
            parents[i] = i;
    }

    int find_root(int u){
        return (parents[u] == u) ? u : (parents[u] = find_root(parents[u]));
    }

    bool in_union(int u, int v){
        int root_u = find_root(u);
        int root_v = find_root(v);
        return (root_u == root_v);
    }

    bool do_union(int u, int v){
        int root_u = find_root(u);
        int root_v = find_root(v);
        if (root_u == root_v) return false;
        parents[root_u] = root_v;
        return true;
    }

    int component(){
        int counter = 0;
        for (int i = 0; i < parents.size(); ++i)
            counter += parents[i] == i;
        return counter;
    }       
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        using ii = pair<int, int>;
        vector<ii> pairs;
        int N = arr.size();
        for (int i = 0; i < N; ++i)
            pairs.push_back({min(i, arr[i]), max(i, arr[i])});
        
        UnionFind uf(N);
        for (auto [u, v] : pairs)
            for (int k = u + 1; k <= v; ++k)
                uf.do_union(u, k);
        
        return uf.component();
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

    // vector<int> nums = {2,1,3,5,6};
    // int k = 5, multiplier = 2;

    // vector<int> nums = {100000, 2000};
    // int k = 2, multiplier = 1000000;

    vector<int> arr = {1,0,2,3,4};

    cout << sol.maxChunksToSorted(arr);

    return 0;
}