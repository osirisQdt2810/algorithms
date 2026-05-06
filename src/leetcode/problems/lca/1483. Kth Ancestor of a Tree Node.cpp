#include <iostream>
#include <vector>

using namespace std;

class TreeAncestor {
    private:
        vector<vector<int>> up;
        int L;

        int get_bit(int n, int i){
            return (n >> i) & 1;
        }

    public:
        TreeAncestor(int n, vector<int>& parent) {
            L = ceil(log2(n));
            up.assign(n, vector<int>(L + 1, -1));
            for (int u = 0; u < n; ++u) up[u][0] = parent[u];
            for (int j = 1; j <= L; ++j){
                for (int u = 0; u < n; ++u){
                    if (up[u][j-1] != -1){
                        up[u][j] = up[up[u][j-1]][j-1];
                    }
                }
            }
        }
        
        int getKthAncestor(int node, int k) {
            for (int j = 0; j <= L; ++j){
                if (get_bit(k, j) && node != -1){
                    node = up[node][j];
                }
            }
            return node;
        }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */