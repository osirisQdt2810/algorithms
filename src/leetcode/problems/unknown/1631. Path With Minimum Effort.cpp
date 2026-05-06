#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using Vertex = int;
using Weight = int;
using WeightNeighbor = std::pair<Vertex, Weight>;

class Solution {
    private:
        inline std::pair<int, int> serialize(int id, int n){
            return {id / n, id % n};
        }

        inline int cell(int r, int c, int n){
            return r * n + c;
        }

        const std::vector<int> dr = {-1, 1, 0, 0};
        const std::vector<int> dc = {0, 0, -1, 1};
        const int oo = INT_MAX;

        int m, n, threshold;

        bool canReachDestination(int r, int c, const std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& visited){
            if (r == m - 1 && c == n - 1) return true;
            visited[r][c] = true;
            for (int i = 0; i < 4; ++i){
                int r_n = r + dr[i], c_n = c + dc[i];
                if ((r_n < 0 || r_n >= m || c_n < 0 || c_n >= n) || visited[r_n][c_n]) continue;
                if (abs(heights[r][c] - heights[r_n][c_n]) > threshold) continue;   // prune the edge whose weight is larger than threshold
                // visited the new node, if we can reach the destination through this child node, the task is done
                if (canReachDestination(r_n, c_n, heights, visited))
                    return true;
            }
            return false;
        }

        bool hasPathWithMaxWeightAtmost(const std::vector<std::vector<int>>& heights, int T){
            m = heights.size();
            n = heights[0].size();
            threshold = T;
            std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
            return canReachDestination(0, 0, heights, visited);
        }

    public:
        inline int minimumEffortPath_dijikstra(std::vector<std::vector<int>>& heights) {
            m = heights.size();
            n = heights[0].size();

            auto cmp = [](const WeightNeighbor& lhs, const WeightNeighbor& rhs){ return lhs.second > rhs.second;};
            std::priority_queue<WeightNeighbor, std::vector<WeightNeighbor>, decltype(cmp)> pq(cmp); // min-heap
            std::vector<Weight> d(m * n, oo);

            int ans = oo;
            pq.push({0, 0});
            d[0] = 0;

            while (!pq.empty()){
                // pop current vertex
                auto [u, du] = pq.top(); pq.pop();
                if (du != d[u]) continue;
                if (u == m * n - 1){
                    ans = du;
                    break;
                };

                // update u's neighbor
                auto [r, c] = serialize(u, n);
                for (int i = 0; i < 4; ++i){
                    int rn = r + dr[i];
                    int cn = c + dc[i];
                    int v = cell(rn, cn, n);
                    if (rn >= 0 && rn < m && cn >= 0 && cn < n){
                        // this is ineffecient because it causes heap inflates though dv is equal to d[v] 
                        // d[v] = std::min(d[v], std::max(du, abs(heights[rn][cn] - heights[r][c])));
                        // pq.push({v, d[v]});
                        // this should be more optimal
                        int dv = std::max(du, abs(heights[rn][cn] - heights[r][c]));
                        if (dv < d[v]){
                            d[v] = dv;
                            pq.push({v, dv});
                        }
                    }
                }
            }
            return ans;
        }

        inline int minimumEffortPath_binarysearch(std::vector<std::vector<int>>& heights) {
            int l = 0, r = 1e6;
            int ans = -1;

            // Với bài minimize f(x):
            //     can(T) = exists x with f(x) <= T
            //     => luôn đơn điệu về mặt logic. false false true true true

            // Với bài maximize f(x):
            //     can(T) = exists x with f(x) >= T
            //     => luôn đơn điệu về mặt logic. true true false false false

            while (l <= r){
                int m = (l + r) / 2;
                if (hasPathWithMaxWeightAtmost(heights, m)){
                    ans = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }

            return ans;
        }

        int minimumEffortPath(std::vector<std::vector<int>>& heights) {
            return minimumEffortPath_binarysearch(heights);
        }
};

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution s;
    std::vector<std::vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    std::cout << s.minimumEffortPath(heights);
    return 0;
}