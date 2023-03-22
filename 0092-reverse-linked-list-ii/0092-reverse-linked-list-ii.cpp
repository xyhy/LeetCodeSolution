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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right <= left)   return head;
        int range = right - left + 1;
        ListNode* cur = head;
        ListNode* tmp = nullptr;
        ListNode* tmphead = nullptr;
        ListNode* tmptail = nullptr;
        ListNode* front = nullptr;
        for(int i = 1; i < left; i++){
            if(i == left-1) front = cur;
            cur=cur->next;
        }
        while(range--){
            ListNode* newnode = new ListNode(cur->val);
            tmphead = newnode;
            if(tmptail == nullptr)  tmptail = newnode;
            if(tmp == nullptr)  tmp = newnode;
            if(tmp != tmphead){
                tmphead->next = tmp;
                tmp = tmphead;
            }
            cur = cur->next;
        }
        if(tmptail != nullptr)  tmptail->next = cur;
        if(front != nullptr)  front->next = tmphead;
        if(left == 1)   return tmphead;
        return head;
    }
};