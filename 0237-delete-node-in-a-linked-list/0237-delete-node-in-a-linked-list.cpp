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
    void deleteNode(ListNode* node) {
        ListNode*p1=NULL;
        p1=node;
        ListNode*p2=NULL;
        while(p1->next!=NULL){
            p1->val=p1->next->val;
            p2=p1;
            p1=p1->next;
        }
        p2->next=NULL;
        delete(p1);
        
    }
};