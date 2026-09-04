#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

/*
LC 2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points
https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

Problem:
    A critical point in a linked list is defined as either a local maxima or a
    local minima.

    A node is a local maxima if the current node has a value strictly greater than
    the previous node and the next node. A node is a local minima if the current
    node has a value strictly smaller than the previous node and the next node.
    Note that a node can only be a local maxima/minima if there exists both a
    previous node and a next node.

    Given a linked list head, return an array of length 2 containing
    [minDistance, maxDistance] where minDistance is the minimum distance between
    any two distinct critical points and maxDistance is the maximum distance
    between any two distinct critical points. If there are fewer than two critical
    points, return [-1, -1].

    Constraints:
        The number of nodes in the list is in the range [2, 10^5]
        1 <= Node.val <= 10^5

Examples:
    Input: head = [3,1]
    Output: [-1,-1]
    Explanation: There are no critical points in [3,1].

    Input: head = [5,3,1,2,5,1,2]
    Output: [1,3]
    Explanation: There are three critical points: the third node (local minima,
    1 < 3 and 1 < 2), the fifth node (local maxima, 5 > 2 and 5 > 1) and the sixth
    node (local minima, 1 < 5 and 1 < 2). minDistance = 6 - 5 = 1 and
    maxDistance = 6 - 3 = 3.

    Input: head = [1,3,2,2,3,2,2,2,7]
    Output: [3,3]
    Explanation: There are two critical points, the second and the fifth node, so
    both distances are 5 - 2 = 3. The last node is not a local maxima because it
    has no next node.

Best solution:
    A single traversal with a sliding window of three consecutive nodes, keeping
    only the index of the first critical point and of the previous one.

Time & Space complexity:
    Time:  O(n) - each node is visited once and each critical test is O(1).
    Space: O(1) - only a handful of indices and three node pointers are held; the
           critical points are never materialised into a list.

Approach (detail):
    1. Criticality is a purely local property: node i is critical iff it has both
       neighbours and its value is strictly greater than both or strictly smaller
       than both. So one pass over consecutive triples (prev, curr, next) detects
       every critical point, and no node outside 1..n-2 can ever qualify.
    2. maxDistance is always last_critical - first_critical. Distances grow with
       separation, so the widest pair is necessarily the outermost pair; there is
       no need to compare any other pair.
    3. minDistance is always achieved by two *consecutive* critical points. If two
       critical points are not adjacent in the critical sequence, some critical
       point lies strictly between them, and either half of the split is a strictly
       shorter distance. So tracking just the previous critical index and taking a
       running minimum over consecutive gaps is enough.
    4. Keep first_crit (set once, at the first detection), prev_crit and curr_crit.
       On each detection, shift prev_crit <- curr_crit, curr_crit <- i, and if
       prev_crit is valid fold curr_crit - prev_crit into the running minimum.
    5. If the running minimum never got updated, fewer than two critical points
       exist, so return [-1, -1]; otherwise return
       [min_gap, curr_crit - first_crit] where curr_crit is the last one seen.

Your solution:
    MATCHES BEST - the committed code is this exact single-pass algorithm: it
    walks prev/curr/next in lockstep, folds consecutive gaps into min_dist, and
    reports curr_crit - first_crit as the maximum, in O(n) time and O(1) space.
    The early [-1,-1] return when head->next->next is null is safe because the
    constraints guarantee at least two nodes.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        vector<int> nodesBetweenCriticalPoints(ListNode* head) {
            int curr_crit = -1, prev_crit = -1;
            int first_crit = -1;
            vector<int> base{-1, -1};

            ListNode* prev = head;
            ListNode* curr = head->next;
            ListNode* next = head->next->next;
            if (next == nullptr) return base;

            int idx = 1;
            int min_dist = INT_MAX;
            while (next){
                int p1 = prev->val, p2 = curr->val, p3 = next->val;
                // cout << p1 << " " << p2 << " " << p3 << "\n";
                if (
                    (p2 < p1 && p2 < p3) ||
                    (p2 > p1 && p2 > p3)
                ){
                    prev_crit = curr_crit;
                    curr_crit = idx;
                    // cout << "\t" << prev_crit << " " << curr_crit << " " << "\n";
                    if (first_crit < 0){
                        first_crit = curr_crit;
                    }
                    if (prev_crit >= 0){
                        min_dist = min(min_dist, curr_crit - prev_crit);
                    }
                }
                next = next->next;
                curr = curr->next;
                prev = prev->next;
                ++idx;
            }
            return (min_dist == INT_MAX) ? base : vector<int>({min_dist, curr_crit - first_crit});
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