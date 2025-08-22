class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode*prev=NULL;
       ListNode*temp=head;
      
if(!head) return NULL;
       while(temp ){
         ListNode*curr=temp->next;
       
        temp->next=prev;
        prev=temp;
        temp=curr;
       } 
       return prev;
    }
};