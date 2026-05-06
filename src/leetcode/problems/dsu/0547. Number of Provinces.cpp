#include <vector>
#include <iostream>

struct DisjointSetUnion {
    std::vector<int> parent_;

    DisjointSetUnion(size_t n){ parent_.assign(n, -1); }

    int root(int u){ return (parent_[u] < 0) ? u : (parent_[u] = root(parent_[u])); }

    void do_union(int u, int v){
        int root_u = root(u);
        int root_v = root(v);
        if (root_u == root_v) return;
        parent_[root_v] = root_u;   // parent_[root_u] += parent_[root_v];
    }

    int components(){
        int num = 0;
        for (size_t u = 0; u < parent_.size(); ++u)
            num += (parent_[u] < 0);
        return num;
    }
};

class Solution {
    public:
        int findCircleNum(std::vector<std::vector<int>>& isConnected) {
            size_t n = isConnected.size();
            DisjointSetUnion dsu(n);
            for (int u = 0; u < (int)n; ++u)
                for (int v = u + 1; v < (int)n; ++v)
                    if (isConnected[u][v])
                        dsu.do_union(u, v);
            return dsu.components();
        }
};

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    std::vector<std::vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    std::cout << sol.findCircleNum(isConnected);
    return 0;
}