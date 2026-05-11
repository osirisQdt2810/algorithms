#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

static constexpr int MAX_NUM = 1e6 + 1;
vector<vector<int>> factors;    // factors[u]: all prime factors of integer u

bool eratos = [](){
    factors.resize(MAX_NUM);
    for (int i = 2; i < MAX_NUM; ++i){
        if (factors[i].empty()){   // <=> is_prime(i) = true
            // add i into factors[j], where j = i * k
            for (int j = i; j < MAX_NUM; j += i){
                factors[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
    public:
        int minJumps(vector<int>& nums) {
            int n = nums.size();

            // do reverse BFS to find the shortest path from n-1 -> 0.
            // the reason why we use `reverse` version is that it is easier to find all primes number p (=nums[i]) from factors[j], 
            // thus j can jump back to i
            // if we use normal BFS, with a prime number p, we need to know which num is a multiply of this p
            vector<bool> visited(n, false);
            unordered_map<int, vector<int>> p2f;
            queue<int> q;
            q.push(0);

            for (int i = 0; i < n; ++i){
                if (!factors[nums[i]].empty()){
                    for (int p : factors[nums[i]]){
                        p2f[p].push_back(i);
                    }
                }
            }

            int ans = 0;
            while (!q.empty()){
                // // visit u
                // int u = q.front(); q.pop();
                // visited[u] = true;

                // // seek all v that u can forward
                // // move u - 1
                // if (u > 0 && !visited[u - 1]) q.push(u - 1);
                // // move u + 1
                // if (u < n - 1 && !visited[u + 1]) q.push(u + 1);
                // // if u is prime, move to all v that nums[v] % nums[u] == 0
                // if (factors[u].empty() && nums[u] != 1){
                //     for (int v : p2f[u]){
                //         if (!visited[v]){
                //             q.push(v);
                //         }
                //     }
                // }

                // this design doesn't expose the height of BFS
                // => we implement another effective BFS pattern
                int qsize = q.size(); int oqsize = qsize;
                ans++;
                while (qsize--){
                    int u = q.front(); q.pop();
                    if (u == n-1) return (ans-1);
                    visited[u] = true;
                    if (u > 0 && !visited[u-1]) q.push(u-1);
                    if (u < n-1 && !visited[u+1]) q.push(u+1);
                    if (factors[nums[u]].size() == 1){
                        for (int v : p2f[nums[u]]){
                            if (!visited[v] && v != u-1 && v != u+1){
                                q.push(v);
                            }
                        }
                        p2f[nums[u]].clear();   // critical to avoid duplicate jump from the identical prime p
                    }
                }
            }
            return -1;
        }
};

int main(){
    Solution sol;

    // vector<int> nums = {2, 3, 1};
    vector<int> nums = {7, 5, 7};
    cout << sol.minJumps(nums);
    return 0;
}