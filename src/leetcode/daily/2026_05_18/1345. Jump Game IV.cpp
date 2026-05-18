#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int minJumps(vector<int>& arr) {
            // use BFS from last index to first index,
            // obviously, if a node v has been 'visited' previously in the track path, v has already had its best 
            // minimum distance from v to last node index
            int n = arr.size();

            queue<int> Q;
            vector<int> dp(n, -1);
            using Value = int;
            using Pos = int;
            unordered_map<Value, unordered_set<Pos>> val2pos;

            for (int i = 0; i < n; ++i){
                val2pos[arr[i]].insert(i);
            }

            // [100,-23,-23,404,100,23,23,23,3,404]
            dp[n-1] = 0;
            Q.push(n-1);
            while (!Q.empty()){
                int u = Q.front(); Q.pop();
                if (u == 0) return dp[u];
                // u-1/u+1
                if (u-1 >= 0 && dp[u-1] < 0){
                    dp[u-1] = dp[u] + 1;
                    val2pos[arr[u-1]].erase(u-1);
                    Q.push(u-1);
                }
                if (u+1 < n && dp[u+1] < 0){
                    dp[u+1] = dp[u] + 1;
                    val2pos[arr[u+1]].erase(u+1);
                    Q.push(u+1);
                }
                
                // v where arr[v] = arr[u]
                for (auto& v : val2pos[arr[u]]){
                    if (dp[v] < 0){
                        dp[v] = dp[u] + 1;
                        Q.push(v);
                    }
                }
                val2pos.erase(arr[u]);
            }
            return -1;
        }
};