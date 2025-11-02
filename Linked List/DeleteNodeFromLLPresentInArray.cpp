class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      unordered_set<int>s(nums.begin(),nums.end());

      while(head!=NULL && s.find(head->val)!=s.end()){
        head=head->next;
      }
 
 ListNode*curr=head;
 while(curr!=NULL && curr->next!=NULL){
    if(s.find(curr->next->val)!=s.end()){  
curr->next=curr->next->next;


 }else{
    curr=curr->next;
 }
 }
return head;
    }
};