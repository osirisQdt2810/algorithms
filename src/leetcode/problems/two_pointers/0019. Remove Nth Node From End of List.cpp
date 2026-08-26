#include <vector>
#include <iostream>

using namespace std;

/*
LC 19 - Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Problem:
    Given the head of a linked list, remove the nth node from the end of the list and
    return its head.

    Constraints:
        The number of nodes in the list is sz.
        1 <= sz <= 30
        0 <= Node.val <= 100
        1 <= n <= sz

    Follow up: Could you do this in one pass?

Examples:
    Input:  head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Input:  head = [1], n = 1
    Output: []

    Input:  head = [1,2], n = 1
    Output: [1]

Best solution:
    Two pointers separated by a gap of n, advanced together in a single pass
    (the follow-up's one-pass answer).

Time & Space complexity:
    Time:  O(sz) - one traversal; each node is visited by each pointer at most once.
    Space: O(1) - three pointers, no auxiliary structure.

Approach (detail):
    1. Introduce a dummy node in front of head (dummy->next = head). This removes the
       special case "the node to delete is the head": the predecessor of any target,
       including the first node, is then a real node.
    2. Set fast = dummy and advance it n steps. Set slow = dummy.
    3. Move fast and slow forward one step at a time until fast->next == nullptr. The gap
       of n is preserved by construction, so when fast sits on the last node, slow sits
       exactly n+1 nodes from the end - i.e. on the predecessor of the target. This is the
       key insight: a fixed offset between two pointers converts "nth from the end" into a
       local condition testable without knowing the length.
    4. Unlink with slow->next = slow->next->next (freeing the removed node if the caller
       owns it), and return dummy->next as the new head.
    5. n <= sz is guaranteed, so fast never runs off the list during the initial n steps.

Your solution:
    SUBOPTIMAL - the code is correct but makes two traversals instead of one: a first loop
    counts total_nodes, then a second loop walks to index target = total_nodes - n and
    unlinks it while tracking prev. Its own complexity is Time O(sz), Space O(1) - the same
    asymptotics as the best solution - so the gap is a constant factor, 2 passes vs 1, and
    it does not answer the follow-up's one-pass requirement. It passes trivially under
    sz <= 30. Correctness holds on the edges: when the head itself is the target, target
    is 0 and prev is still nullptr, so the code reassigns head = curr->next rather than
    dereferencing prev, and a single-node list correctly returns nullptr.
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int total_nodes = 0;
            ListNode* tmp = head;
            while (tmp){
                ++total_nodes;
                tmp = tmp->next;
            }

            ListNode* prev = nullptr;
            ListNode* curr = head;
            int iter = 0, target = total_nodes - n; // 1 2

            while (curr){
                if (iter == target){
                    if (prev == nullptr){
                        head = curr->next;
                    }
                    else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    break;
                }
                ++iter;
                ListNode* tmp = curr;
                curr = curr->next;
                prev = tmp;
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
    Solution sol;

    // h[1] h[2] h[3] h[4] h[5] h[6]
    // (l r) => min(h[l], h[r]) * (r-l)
    return 0;
}