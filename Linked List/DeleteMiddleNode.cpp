class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
       ListNode*temp=head;
       int count=0;
       while(temp){
          count++;
   temp=temp->next;
       } 
       temp=head;
     int mid=count/2;
 for(int i=0;i<mid-1;i++){
    temp=temp->next;
 }
       ListNode*remove=temp->next;
       temp->next=remove->next;
       delete(remove);
       return head;
    }
};


//M2

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode*slow=head;
        ListNode*fast=head;


        while(fast &&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
      ListNode*curr=head;
      while(curr->next!=slow){
        curr=curr->next;
      }
      curr->next=slow->next;
      delete(slow);
      return head;
    }
};