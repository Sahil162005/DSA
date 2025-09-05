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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p1=l1;
        ListNode*p2=l2;
        ListNode*newhead= new ListNode();
        ListNode*p4=newhead;
        int sum=0;
        int carry=0;
        while(p1!=NULL && p2!=NULL){
            sum=p1->val+p2->val+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode*p3=new ListNode(digit);
            p4->next=p3;
            p4=p3;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1!=NULL){
            sum=p1->val+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode*p3=new ListNode(digit);
            p4->next=p3;
            p4=p3;
            p1=p1->next;
        }
        while(p2!=NULL){
            sum=p2->val+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode*p3=new ListNode(digit);
            p4->next=p3;
            p4=p3;
            p2=p2->next;
        }
        if(carry!=0){
            ListNode*p3=new ListNode(carry);
            p4->next=p3;
        }
        return newhead->next;
    }

            
            
           
           


        
    
};