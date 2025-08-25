class Solution {
public:
 TreeNode* BuildBST(vector<int>arr,int l,int r){

      if(l>r) return NULL;
        int mid=l+(r-l)/2;

        TreeNode* root=new TreeNode(arr[mid]);
        root->left=BuildBST(arr,l,mid-1);
        root->right=BuildBST(arr,mid+1,r);
      
      return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
      vector<int>arr;
      ListNode*temp=head;

      while(temp){
        arr.push_back(temp->val);
        temp=temp->next;
      }  
      int n=arr.size();
return BuildBST(arr,0,n-1);
      
    }
};