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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == nullptr)   return head;
        ListNode* cur = head;
        ListNode* newhead = nullptr;
        ListNode* tmphead = nullptr;
        ListNode* tmptail = nullptr;
        ListNode* tmp = nullptr;
        ListNode* storetail = nullptr;
        int cnt = 0;
        while(cur != nullptr){
            cnt++;
            cur = cur->next;
        }
        cur = head;
        cnt = cnt/k;
        while(cnt--){
            tmphead = nullptr;
            tmptail = nullptr;
            tmp = nullptr;
            for(int i = 0; i < k; i++){
                ListNode* newnode = new ListNode(cur->val);
                tmphead = newnode;
                tmphead->next = tmp;
                tmp = tmphead;
                if(!tmptail)    tmptail = newnode;
                cur = cur->next;
            }
            if(!newhead)    newhead = tmphead;
            if(!storetail)    storetail = tmptail;
            else{
                storetail->next = tmphead;
                storetail = tmptail;
            }
        }
        storetail->next = cur;
        return newhead;
    }
};