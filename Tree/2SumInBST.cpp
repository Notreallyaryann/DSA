class Solution {
public:
void inorder(TreeNode* root,vector<int> &arr){
    if(!root) return;

    inorder(root->left,arr );
    arr.push_back(root->val);
    inorder(root->right,arr);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root ,arr);
int n=arr.size();
int i=0,j=n-1;
bool contains=0;
while(i<j){
    if(arr[i]+arr[j]==k){
contains=1;
break;
    }else if(arr[i]+arr[j]<k){
        i++;
    }else{
        j--;
    }
}
return contains;
    }
};