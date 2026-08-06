#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 1260 - Shift 2D Grid
 * https://leetcode.com/problems/shift-2d-grid/
 *
 * Problem:
 *   Given a 2D grid of size m x n and an integer k. You need to shift the grid
 *   k times.
 *
 *   In one shift operation:
 *     - Element at grid[i][j] moves to grid[i][j + 1].
 *     - Element at grid[i][n - 1] moves to grid[i + 1][0].
 *     - Element at grid[m - 1][n - 1] moves to grid[0][0].
 *
 *   Return the 2D grid after applying shift operation k times.
 *
 *   Constraints:
 *     - m == grid.length
 *     - n == grid[i].length
 *     - 1 <= m <= 50
 *     - 1 <= n <= 50
 *     - -1000 <= grid[i][j] <= 1000
 *     - 0 <= k <= 100
 *
 * Examples:
 *   Example 1:
 *     Input:  grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
 *     Output: [[9,1,2],[3,4,5],[6,7,8]]
 *
 *   Example 2:
 *     Input:  grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
 *     Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
 *
 *   Example 3:
 *     Input:  grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
 *     Output: [[1,2,3],[4,5,6],[7,8,9]]
 *
 * Best solution: Row-major flattening + a single modular index shift.
 * This is optimal: every one of the m*n cells must be read and written at least
 * once, so O(m*n) time is a lower bound, and one direct pass attains it.
 *
 * Time:  O(m*n) — one pass over the grid, each cell mapped to its destination
 *        in O(1) with an integer divide/modulo.
 * Space: O(m*n) for the returned grid; O(1) auxiliary beyond the output.
 *
 * Approach (detail):
 *   1. Key insight: the shift rules describe a single cyclic rotation of the
 *      grid read in row-major order. The three bullets are not three separate
 *      cases — they are exactly what "move one step forward, wrapping at the
 *      end" looks like once the 2D grid is laid out as one flat array of
 *      length mn = m*n.
 *   2. Define the bijection cell(i, j) = i * n + j mapping a coordinate to its
 *      row-major position, and its inverse decell(c) = (c / n, c % n).
 *   3. Applying the shift once sends flat position c to (c + 1) % mn, so
 *      applying it k times sends c to (c + k) % mn. Because the operation is a
 *      rotation of a cycle of length mn, k can be taken mod mn for free — the
 *      single modulo handles k >= mn without any repeated work (this is why
 *      simulating k separate shifts, O(k*m*n), is wasted effort).
 *   4. Allocate the result grid and, for each source (i, j), compute
 *      c = cell(i, j), then write grid[i][j] into res[decell((c + k) % mn)].
 *      Writing into a fresh grid rather than rotating in place avoids
 *      clobbering values that have not been moved yet.
 *   5. Correctness: the map c -> (c + k) % mn is a bijection on [0, mn), so
 *      every destination is written exactly once and no value is lost.
 */

class Solution {
    public:
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
            int m = grid.size(), n = grid[0].size();
            int mn = m * n;
            vector<vector<int>> res(m, vector<int>(n));

            auto cell = [&](int i, int j){
                return i * n + j;
            };

            auto decell = [&](int c){
                return pair<int, int>({
                    c / n,
                    c % n
                });
            };

            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    int c = cell(i, j);
                    auto [in, jn] = decell((c + k) % mn);
                    res[in][jn] = grid[i][j];
                }
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