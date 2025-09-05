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
        ListNode*pa=headA;
        ListNode*pb=headB;
        int l1=0,l2=0;
        while(pa!=NULL){
            l1++;
            pa=pa->next;
        }
        while(pb!=NULL){
            l2++;
            pb=pb->next;
        }
        int diff;
        pa=headA;
        pb=headB;
        if(l1>l2){
            diff=l1-l2;
            while(diff!=0){
                diff--;
                pa=pa->next;
            }
        }
        else if(l2>l1){
            diff=l2-l1;
            while(diff!=0){
                diff--;
                pb=pb->next;
            }
        }
        while(pa!=NULL && pb!=NULL){
            if(pa==pb){
                return pa;
            }
            pa=pa->next;
            pb=pb->next;
        }

        return NULL;
    }
};