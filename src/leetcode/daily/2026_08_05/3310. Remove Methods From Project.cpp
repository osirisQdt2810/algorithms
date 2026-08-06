#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
    LC 3310 - Remove Methods From Project
    https://leetcode.com/problems/remove-methods-from-project/

    Problem:
        You are maintaining a project that has n methods numbered from 0 to n - 1.
        You are given two integers n and k, and a 2D integer array invocations, where
        invocations[i] = [a_i, b_i] indicates that method a_i invokes method b_i.
        There is a known bug in method k. Method k, along with any method invoked by it, either
        directly or indirectly, are considered suspicious and we aim to remove them.
        A group of methods can only be removed if no method outside the group invokes any methods
        within it.
        Return an array containing all the remaining methods after removing all the suspicious
        methods. You may return the answer in any order. If it is not possible to remove all the
        suspicious methods, none should be removed.

        Constraints:
          - 1 <= n <= 10^5
          - 0 <= k <= n - 1
          - 0 <= invocations.length <= 2 * 10^5
          - invocations[i] == [a_i, b_i]
          - 0 <= a_i, b_i <= n - 1
          - a_i != b_i
          - invocations[i] != invocations[j]

    Examples:
        Example 1:
            Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
            Output: [0,1,2,3]
            Explanation: Method 2 and method 1 are suspicious, but they are directly invoked by
            methods 3 and 0, which are not suspicious. We return all elements without removing
            anything.

        Example 2:
            Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]
            Output: [3,4]
            Explanation: Methods 0, 1, and 2 are suspicious and they are not directly invoked by
            any other method. We can remove them.

        Example 3:
            Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]
            Output: []
            Explanation: All methods are suspicious. We can remove them.

    Best solution:
        Graph reachability (DFS/BFS from k on the directed invocation graph) + one incoming-edge
        check on the suspicious set.

    Time & Space complexity:
        Time:  O(n + E), E = invocations.length
               - one DFS visits each node and each edge at most once, then a single O(n) sweep to
                 test the suspicious set and build the answer.
        Space: O(n + E)
               - adjacency lists O(n + E), plus visited/in-degree arrays and the recursion stack
                 O(n).

    Approach (detail):
        1. Build the directed adjacency list a -> b from invocations, and count each node's
           in-degree (number of methods that invoke it).
        2. DFS from k marking `visited`; `visited` is exactly the suspicious set (k plus everything
           reachable from it, directly or indirectly). This is the group we want to delete.
        3. While DFS-ing, decrement in_deg[v] for every edge u -> v traversed out of a suspicious
           node u. Each suspicious node's adjacency list is walked exactly once (the node is marked
           visited before recursing), so every edge leaving the suspicious set is discounted
           exactly once. After the DFS, for a suspicious node u, in_deg[u] is the number of
           invocations of u coming from *outside* the suspicious set.
        4. Removability check: the group is removable iff no outside method invokes anything in it,
           i.e. iff in_deg[u] == 0 for every suspicious u. If any suspicious u still has
           in_deg[u] > 0, nothing can be removed - return all n methods.
        5. Otherwise the answer is every non-suspicious node, in any order.
        6. Why this is correct: the suspicious set is forced (it is the reachable closure of k, so
           it is exactly the minimal set that must go), and the problem's only obstruction is an
           incoming edge crossing into that set from outside. Reducing the in-degree by the edges
           internal to the set turns "is there a crossing edge into u" into a single O(1) test per
           node, so one DFS plus one sweep decides the whole question. Edges leaving the set
           (suspicious -> non-suspicious) are irrelevant: removing a caller never breaks a callee.
*/

class Solution {
    private:
        void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& in_deg){
            visited[u] = true;
            for (auto& v : adj[u]){
                --in_deg[v];
                if (visited[v]) continue;
                dfs(v, adj, visited, in_deg);
            }
        }

    public:
        vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
            vector<vector<int>> adj(n);
            vector<bool> visited(n, false);
            vector<int> in_deg(n, 0);

            for (auto& invo : invocations){
                int u = invo[0], v = invo[1];
                adj[u].push_back(v);
                ++in_deg[v];
            }

            dfs(k, adj, visited, in_deg);

            // for (int u = 0; u < n; ++u){
            //     cout << u << " " << in_deg[u] << " " << visited[u] << "\n";
            // }
            vector<int> res;
            vector<int> full;
            for (int u = 0; u < n; ++u){
                full.push_back(u);
            }
            for (int u = 0; u < n; ++u){
                if (visited[u]){
                    if (in_deg[u]) return full;
                    continue;
                }
                res.push_back(u);
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

    return 0;
}