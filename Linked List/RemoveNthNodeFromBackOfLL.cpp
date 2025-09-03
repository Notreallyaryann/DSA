class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode*temp=head;
int count=0;
 while(temp){
count++;
temp=temp->next;
      } 
temp=head;
int k=count-n;

if(k==0){
    ListNode*newhead=head;
    head=head->next;
    delete(newhead);
    return head;
}
for(int i=1;i<k;i++){
temp=temp->next;
} 
ListNode*curr=temp->next;
temp->next=curr->next;
delete(curr);
return head;
    }
};