class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*temp=head;

        while(temp && temp->next){
            if(temp->val==temp->next->val){
                ListNode*duplicate=temp->next;
                temp->next=duplicate->next;

            } else{
            temp=temp->next;
            }
        }
        return head;
    }
};