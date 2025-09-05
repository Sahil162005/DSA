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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*p1=head;
        ListNode*p2=NULL;
        ListNode*p3=NULL;
        while(p1!=NULL){
            p2=p1->next;
            p1->next=p3;
            p3=p1;
            p1=p2;

        }
        return p3;
    }
};