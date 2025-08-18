
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode*temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
      int k=count-n;  
if(k==0){
    ListNode*newhead=head;
    head=head->next;
    delete(newhead);
    return head;
    }
 temp=head;

 for (int i = 1; i < k; i++) {  
   temp = temp->next;
        }

ListNode*remove=temp->next;
temp->next=remove->next;
delete(remove);

return head;
    }
};