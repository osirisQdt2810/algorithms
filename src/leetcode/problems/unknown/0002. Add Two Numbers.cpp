#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:


        int len(ListNode* node){
            if (node == nullptr) return 0;
            return 1 + len(node->next);
        }

        ListNode* recursive(ListNode* l1, ListNode* l2, int c){
            if (l1 == nullptr && l2 == nullptr && c == 0) return nullptr;
            int s = c;
            ListNode* l1_next = nullptr;
            ListNode* l2_next = nullptr;
            if (l1 != nullptr){
                s += l1->val;
                l1_next = l1->next;
            }

            if (l2 != nullptr){
                s += l2->val;
                l2_next = l2->next;
            }

            ListNode* sum = new ListNode(s % 10);
            sum->next = recursive(l1_next, l2_next, s / 10);
            return sum;
        }

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            return recursive(l1, l2, 0);
        }
};

int main(){
    ListNode* l11 = new ListNode(2);
    ListNode* l12 = new ListNode(4); l11->next = l12;
    ListNode* l13 = new ListNode(3); l12->next = l13;
    
    ListNode* l21 = new ListNode(5);
    ListNode* l22 = new ListNode(6); l21->next = l22;
    ListNode* l23 = new ListNode(4); l22->next = l23;

    Solution s;
    ListNode* r = s.addTwoNumbers(l11, l21);

    while (r != nullptr){
        std::cout << r->val << " ";
        r = r->next;
    }

    return 0;
}