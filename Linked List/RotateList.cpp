class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       vector<int>arr;
   if (!head || !head->next || k == 0) return head;
       while(head){
        arr.push_back(head->val);
        head=head->next;
       } 
       int n=arr.size();
vector<int>temp(n);
       for(int i=0;i<n;i++){
                temp[(i+k)%n] = arr[i];
       }
   //rebuild ll
   ListNode*dummy=new ListNode(-1);
           ListNode* curr=dummy;
   for(int i=0;i<temp.size();i++){
    curr->next=new ListNode(temp[i]);
    curr=curr->next;
   }
   return dummy->next;
    }
};