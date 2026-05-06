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
    private:
        void relink(ListNode* root, ListNode* A, ListNode* B){
            if (A == nullptr && B == nullptr) return;
            if (A == nullptr){
                root->next = B;
                relink(B, A, B->next);
            }
            else if (B == nullptr){
                root->next = A;
                relink(A, B, A->next);
            }
            else {
                if (A->val <= B->val){
                    root->next = A;
                    relink(A, B, A->next);
                }
                else {
                    root->next = B;
                    relink(B, A, B->next);
                }
            }
        }

    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr) return list2;
            if (list2 == nullptr) return list1;
            if (list1->val <= list2->val){
                relink(list1, list1->next, list2);
                return list1;
            }
            else {
                relink(list2, list2->next, list1);
                return list2;
            }
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