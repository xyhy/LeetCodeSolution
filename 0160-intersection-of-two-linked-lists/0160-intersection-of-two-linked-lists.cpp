/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr)    return nullptr;
        ListNode *cur = headA;
        ListNode *tmpA=headA, *tmpB=headB;
        int sizea=0, sizeb=0, gap=0;
        while(cur != nullptr){
            cur = cur->next;
            sizea++;
        }
        cur = headB;
        while(cur != nullptr){
            cur = cur->next;
            sizeb++;
        }

        if(sizea > sizeb){
            gap = sizea-sizeb;
            while(gap--)    tmpA = tmpA->next;
            while(tmpA != nullptr && tmpB != nullptr){
                if(tmpA == tmpB)    return tmpA;
                else{
                    tmpA = tmpA->next;
                    tmpB = tmpB->next;
                }
            }    
        } else if (sizeb > sizea) {
            gap = sizeb-sizea;
            while(gap--)   tmpB = tmpB->next;
            while(tmpA != nullptr && tmpB != nullptr){
                if(tmpA == tmpB)    return tmpA;
                else{
                    tmpA = tmpA->next;
                    tmpB = tmpB->next;
                }
            }
        } else {
            while(tmpA != nullptr && tmpB != nullptr){
                if(tmpA == tmpB)    return tmpA;
                else{
                    tmpA = tmpA->next;
                    tmpB = tmpB->next;
                }
            }
        }
        return nullptr;

    }
};