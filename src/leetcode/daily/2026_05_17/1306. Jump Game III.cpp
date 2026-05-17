#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReachNoOptimized(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        for (int u = 0; u < n; ++u){
            int v0 = u + arr[u];
            int v1 = u - arr[u];
            if (v0 < n) adj[u].push_back(v0);
            if (v1 >= 0) adj[u].push_back(v1);
        }

        queue<int> q;
        vector<bool> visited(n);
        q.push(start);

        while (!q.empty()){
            int u = q.front(); q.pop();
            if (arr[u] == 0) return true;
            visited[u] = true;
            for (auto& v: adj[u]){
                if (!visited[v]){
                    q.push(v);
                }
            }
        }
        return false;
    }

    bool canReachOptimizedSpace(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        q.push(start);

        while (!q.empty()){
            int u = q.front(); q.pop();
            if (arr[u] == 0) return true;
            int v0 = u + arr[u];
            int v1 = u - arr[u];
            arr[u] = -1;    // mark u as visited
            if (v0 < n && arr[v0] >= 0) q.push(v0);
            if (v1 >= 0 && arr[v1] >= 0) q.push(v1);
        }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        return canReachOptimizedSpace(arr, start);
    }

};