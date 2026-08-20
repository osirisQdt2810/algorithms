#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

/*
LC 1386 - Cinema Seat Allocation
https://leetcode.com/problems/cinema-seat-allocation/

Problem:
    A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats,
    numbered from 1 to 10. You are given a 2D integer array reservedSeats, where
    reservedSeats[i] = [row_i, seat_i] means that seat seat_i in row row_i is
    already reserved.
    A four-person group must be assigned to four seats in the same row. The group
    can be seated in one of the following seat blocks:
        seats 2, 3, 4, 5
        seats 4, 5, 6, 7
        seats 6, 7, 8, 9
    A block can be used only if none of its seats are reserved. Each seat can be
    assigned to at most one group.
    Return the maximum number of four-person groups that can be assigned.

    Constraints:
        1 <= n <= 10^9
        1 <= reservedSeats.length <= min(10 * n, 10^4)
        reservedSeats[i] == [row_i, seat_i]
        1 <= row_i <= n
        1 <= seat_i <= 10
        All reservedSeats[i] are distinct.

Examples:
    Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
    Output: 4
    Explanation: an optimal allocation seats four groups; row 1 keeps only the
    6-9 block, row 2 keeps only the 2-5 block, row 3 keeps both 2-5 and 6-9.

    Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
    Output: 2

    Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
    Output: 4

Best solution:
    Hash map keyed by the touched rows only, plus a constant-size 3-block greedy
    per row. n is up to 10^9 so untouched rows must never be enumerated.

Time & Space complexity:
    Time:  O(m) - m = reservedSeats.length; one pass to mark blocks, one pass over
           the at-most-m touched rows, each doing O(1) work.
    Space: O(m) - the map stores 3 booleans for each distinct reserved row.

Approach (detail):
    1. Seats 1 and 10 belong to no block, so a reservation there never matters.
       Any row with no reservation in seats 2..9 always yields exactly 2 groups
       (blocks 2-5 and 6-9, which are disjoint).
    2. There are at most m distinct reserved rows, so start from
       2 * (n - #touched_rows) for all the untouched rows and fix up the rest.
    3. For each touched row keep three flags: left = seats 2-5 free,
       middle = seats 4-7 free, right = seats 6-9 free. A reserved seat c kills
       left if 2 <= c <= 5, middle if 4 <= c <= 7, right if 6 <= c <= 9.
    4. Per row the answer is the maximum number of pairwise-disjoint free blocks.
       Left and right are disjoint; middle overlaps both. So the maximum is 2 when
       left and right are both free, otherwise 1 when any block is free, else 0.
    5. That equals (left + middle + right) minus 1 when middle is free together
       with at least one of left/right: all three free -> 3-1 = 2 (take left and
       right); middle plus exactly one side -> 2-1 = 1; middle alone -> 1; left
       and right only -> 2 with no correction.
    6. Key insight: only rows that appear in reservedSeats can differ from the
       default 2, which keeps the work independent of n.

Your solution:
    MATCHES BEST - the code builds the per-row 3-flag map over the reserved seats
    only, seeds the total with 2 * (n - blocks.size()) for untouched rows, and
    applies the same overlap correction (subtract 1 when the middle block is free
    alongside the left or the right block). Time O(m), Space O(m).
*/

class Solution {
    public:
        int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
            unordered_map<int, vector<bool>> blocks;
            for (auto seat : seats){
                int r = seat[0], c = seat[1];
                if (!blocks.count(r)){
                    blocks[r] = vector<bool>(3, true);
                }
                if (c >= 2 && c <= 5){
                    blocks[r][0] = false;
                }
                if (c >= 4 && c <= 7){
                    blocks[r][1] = false;
                }
                if (c >= 6 && c <= 9){
                    blocks[r][2] = false;
                }
            }
            int res = 2 * (n - blocks.size());
            for (auto& [r, block] : blocks){
                res += block[0] + block[1] + block[2];
                if (
                    (block[1] && block[0]) ||
                    (block[1] && block[2])
                ){
                    --res;
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