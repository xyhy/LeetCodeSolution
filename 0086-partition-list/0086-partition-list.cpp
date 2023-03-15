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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;
        if(head->next == nullptr)   return head;
        ListNode* headS = nullptr;
        ListNode* headL = nullptr;
        ListNode* smaller = nullptr;
        ListNode* larger = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val < x){
                if(headS == nullptr){
                    headS = cur;
                    smaller = cur;
                } else if(headS == smaller) {
                    smaller = cur;
                    headS->next = smaller;
                } else {
                    smaller->next = cur;
                    smaller = smaller->next;
                }
            } else {
                if(headL == nullptr){
                    headL = cur;
                    larger = cur;
                } else if(headL == larger) {
                    larger = cur;
                    headL->next = larger;
                } else {
                    larger->next = cur;
                    larger = larger->next;
                }
            }
            cur = cur->next;
        }
        if(smaller != nullptr){
            smaller->next = headL;
        }
        if (larger != nullptr){
            larger->next = nullptr;
        }
        if(headS == nullptr)    return headL;
        return headS;
    }
};