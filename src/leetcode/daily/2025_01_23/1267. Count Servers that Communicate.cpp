#include <bits/stdc++.h>

using namespace std;

struct AdvanceUnionFind {
    std::vector<int> parents;

    AdvanceUnionFind(int V){
        parents.reserve(V);
    }

    int add_vertex(){
        parents.push_back(-1);
        return parents.size() - 1;
    }

    int num_vertices(){
        return parents.size();
    }

    int find_root(int u){
        return (parents[u] < 0) ? u : (parents[u] = find_root(parents[u]));
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
        parents[root_v] += parents[root_u];
        parents[root_u] = root_v;
        return true;
    }

    int num_components(){
        int num = 0;
        for (auto& par : parents)
            num += (par < 0);
        return num;
    }

    int num_points_with_vertex(int u){
        int root_u = find_root(u);
        return -parents[root_u];
    }

    int num_connected_vertex(){
        int num = 0, i = 0;
        for (auto& par : parents){
            if (par < -1){
                num += -par;
            }
        }
        return num;
    }

};

class Solution {
    public:
        int countServers(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            using Position = int;
            using Index = int;
            unordered_map<Position, Index> mapPosIndex;
            AdvanceUnionFind uf(m * n);
            for (int i = 0; i < m; ++i){
                int j = 0;
                Position pos = -1;
                for (; j < n; ++j){
                    if (grid[i][j]){
                        pos = i * n + j;
                        if (mapPosIndex.find(pos) == mapPosIndex.end()){
                            mapPosIndex[pos] = uf.add_vertex();
                        }
                        break;
                    }
                }
                for (++j; j < n; ++j){
                    if (grid[i][j]){
                        Position curr = i * n + j;
                        if (mapPosIndex.find(curr) == mapPosIndex.end()){
                            mapPosIndex[curr] = uf.add_vertex();
                        }
                        uf.do_union(mapPosIndex[pos], mapPosIndex[curr]);
                    }
                }                
            }


            for (int j = 0; j < n; ++j){
                int i = 0;
                Position pos = -1;
                for (; i < m; ++i){
                    if (grid[i][j]){
                        pos = i * n + j;
                        if (mapPosIndex.find(pos) == mapPosIndex.end()){
                            mapPosIndex[pos] = uf.add_vertex();
                        }
                        
                        break;
                    }
                }
                for (++i; i < m; ++i){
                    if (grid[i][j]){
                        Position curr = i * n + j;
                        if (mapPosIndex.find(curr) == mapPosIndex.end()){
                            mapPosIndex[curr] = uf.add_vertex();
                        }
                        uf.do_union(mapPosIndex[pos], mapPosIndex[curr]);
                    }
                }                
            }

            return uf.num_connected_vertex();
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
    vector<vector<int>> grid = {{1,0},{1,1}};


    return 0;
}