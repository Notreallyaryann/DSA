class Solution {
public:
void inorder(TreeNode* root, int low, int high,int &ans){
  
 if (!root) return;

inorder(root->left,low,high,ans);
if(root->val>=low && root->val<=high){
    ans+=root->val;
}
inorder(root->right,low,high,ans);

}
    int rangeSumBST(TreeNode* root, int low, int high) {
       int ans=0;

     inorder(root,low,high,ans); 
     return ans;
    }
};



//M-2 (optimised)

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;

        if(root->val<low){
           return rangeSumBST(root->right,low,high);
        }else if(root->val>high){
           return  rangeSumBST(root->left,low,high);
        }else{
return root->val+ rangeSumBST(root->right,low,high)+rangeSumBST(root->left,low,high);
        }
    }
};