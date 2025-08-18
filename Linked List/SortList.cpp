class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
   vector<int>arr;

   while(head){
    arr.push_back(head->val);
    head=head->next;
   }
   int n=arr.size();
   sort(arr.begin(),arr.end());

   ListNode* newhead=new ListNode(arr[0]);
   ListNode*curr=newhead;

   for(int i=1;i<n;i++){
    curr->next=new ListNode(arr[i]);
    curr=curr->next;
   } 
return newhead;
    }
};