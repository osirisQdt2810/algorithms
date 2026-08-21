#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
LC 2807 - Insert Greatest Common Divisors in Linked List
https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

Problem:
    Given the head of a linked list head, in which each node contains an integer
    value. Between every pair of adjacent nodes, insert a new node with a value
    equal to the greatest common divisor of them. Return the linked list after
    insertion.
    The greatest common divisor of two numbers is the largest positive integer
    that evenly divides both numbers.

    Constraints:
        The number of nodes in the list is in the range [1, 5000].
        1 <= Node.val <= 1000

Examples:
    Input: head = [18,6,10,3]
    Output: [18,6,6,2,10,1,3]
    Explanation: insert gcd(18, 6) = 6 between the 1st and 2nd nodes,
    gcd(6, 10) = 2 between the 2nd and 3rd, and gcd(10, 3) = 1 between the 3rd and
    4th. There are no more adjacent nodes, so we return the linked list.

    Input: head = [7]
    Output: [7]
    Explanation: There are no pairs of adjacent nodes, so we return the initial
    linked list.

Best solution:
    Single in-place pass over the list, splicing one new node per adjacent pair,
    with the GCD from the Euclidean algorithm.

Time & Space complexity:
    Time:  O(n * log V) - one visit per adjacent pair; each gcd on values <= V
           costs O(log V) Euclidean steps.
    Space: O(1) extra - only two cursors; the n-1 new nodes are the required
           output, not scratch space.

Approach (detail):
    1. The insertions are mutually independent: the node placed between the i-th and
       (i+1)-th original nodes depends only on those two values, and inserting it
       does not change any other adjacent original pair. So one left-to-right pass
       settles everything, with no need to collect values first.
    2. Walk two cursors, prev and curr = prev->next. While curr is not null:
       - allocate a node holding gcd(prev->val, curr->val);
       - splice it in: prev->next = newNode, newNode->next = curr.
    3. Advance past the inserted node rather than into it: set prev = curr and
       curr = curr->next. Reading curr->next after the splice is safe because curr's
       own next pointer was never touched - only prev's was. Stepping to curr (not to
       newNode) is what stops the pass from re-examining inserted nodes and looping
       forever.
    4. gcd by the Euclidean algorithm: gcd(a, 0) = a and gcd(a, b) = gcd(b, a mod b),
       which terminates in O(log min(a,b)) steps.
    5. A single-node list enters the loop with curr == null and returns head
       unchanged, matching the n = 1 example.
    6. O(n log V) is optimal: every adjacent pair must be inspected to produce its
       required output node.

Your solution:
    MATCHES BEST - the code is exactly this one-pass splice: prev/curr cursors, a
    new node per pair carrying the recursive Euclidean gcd, and the advance to
    prev = curr / curr = curr->next that skips the node just inserted. Time
    O(n log V), Space O(1) beyond the returned nodes. The n = 1 case is handled by
    the loop guard, and head is guaranteed non-null by the constraints.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    private:
        int gcd(int a, int b){
            return (b == 0) ? a : gcd(b, a%b);
        }

    public:
        ListNode* insertGreatestCommonDivisors(ListNode* head) {
            ListNode* prev = head;
            ListNode* curr = head->next;

            while (curr != nullptr){
                ListNode* new_node = new ListNode(gcd(prev->val, curr->val));
                prev->next = new_node;
                new_node->next = curr;

                prev = curr;
                curr = curr->next;
            }
            return head;
        }
};

 auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    return 0;
}
