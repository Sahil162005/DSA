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
    ListNode*reversenode(ListNode*p1,ListNode*p2){
        ListNode*curr=p1;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        ListNode*stop=p2->next;
        while(curr!=stop){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode*findKth(ListNode* p1, int k){
        while(k>1 && p1!=NULL){
            p1=p1->next;
            k--;
        }
        return p1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*p1=head;
        ListNode*p3=NULL;
        ListNode*pre=NULL;;
        bool firstrev=true;
        while(p1!=NULL){
            ListNode*p2=findKth(p1,k);
            if(p2==NULL){
                break;
            }
            p3=p2->next;
          ListNode*newhead=  reversenode(p1,p2);
            if(firstrev){
                head=newhead;
                firstrev=false;
            }
            else{
                pre->next=newhead;
            }
            p1->next=p3;
            pre=p1;
            p1=p3;
        }
        return head;
    }
};