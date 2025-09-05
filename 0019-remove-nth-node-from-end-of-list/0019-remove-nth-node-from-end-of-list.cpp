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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p1=head;
        ListNode*p2=NULL;
        int cnt=0;
        while(p1!=NULL){
            cnt++;
            p1=p1->next;
        }
        int pos=cnt-n;
        cnt=0;
        p1=head;
        if(pos==0){
            head=p1->next;
            return head;
        }
        else{
        while(cnt!=pos){
            p2=p1;
            p1=p1->next;
            cnt++;
        }
        p2->next=p1->next;
        delete(p1);
        }
        return head;
    }
};