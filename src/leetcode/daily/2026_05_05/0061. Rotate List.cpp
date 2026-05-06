#include <vector>
#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
        ListNode* rotateRight(ListNode* head, int k) {
            if (head == nullptr) return nullptr;
            ListNode* tail = head;
            int num_node = 1;
            while (tail->next){
                ++num_node;
                tail = tail->next;
            }
            k %= num_node;
            if (k == 0) return head;
            k = (num_node - k);
            // head -> new_head: k
            // head -> new_tail: k-1
            ListNode* new_tail = head;
            for (int i = 0; i < k-1; ++i){
                new_tail = new_tail->next;
            }
            ListNode* new_head = new_tail->next;
            tail->next = head;
            new_tail->next = nullptr;
            return new_head;
        }
};

int main(){
    Solution sol;
    vector<int> heads = {1,2,3,4,5};
    int k = 2;
    auto* head = new ListNode();
    auto* curr = head;
    for (size_t i = 0; i < heads.size(); ++i){
        curr->val = heads[i];
        if (i + 1 < heads.size()){
            curr->next = new ListNode();
            curr = curr->next;
        }
    }
    head = sol.rotateRight(head, k);
    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}