class Solution {
public:
void inorder(TreeNode*root ,vector<int>&arr){
    if(!root) return ;
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
      int n=arr.size();
int l=0,r=n-1;
bool consists=0;
   
while(l<r){
    if(arr[l]+arr[r]==k){
      consists=1;  
      break;
    }else if(arr[l]+arr[r]<k){
        l++;
    }else r--;
}
return consists;
    }
};