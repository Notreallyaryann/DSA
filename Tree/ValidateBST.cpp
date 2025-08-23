class Solution {
public:
void inorder(TreeNode* root, vector<int>&arr){
    if(!root) return ;

    inorder(root->left,arr);
arr.push_back(root->val);
   inorder(root->right,arr);
}
    bool isValidBST(TreeNode* root) {
     vector<int>arr;
     inorder(root,arr);   
bool flag=1;

for(int i=0;i<arr.size()-1;i++){
    if(arr[i]>=arr[i+1]){
        flag=0;
        break;
    }
}
return flag;
    }
};