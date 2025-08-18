class Solution {
public:
    bool isPalindrome(ListNode* head) {
       vector<int>arr;
       while(head){
        arr.push_back(head->val);
        head=head->next;
       }
       int n=arr.size();
       int left=0;
       int right=n-1;
       while(left <right){
        if(arr[left]!=arr[right]){
            return false;
        }
        left++;
        right--;
       }
       return true;
        }
};