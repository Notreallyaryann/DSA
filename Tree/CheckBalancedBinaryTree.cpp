class Solution {
public:
int check(TreeNode* root,bool&ans){
    if(!root) return 0;

   int left= check(root->left,ans);
    int right=check(root->right,ans);
if(abs(left-right)>1) ans=0;

return 1+max(left,right);

}
    bool isBalanced(TreeNode* root) {
        bool ans=1;

     check(root,ans);
     return ans;
    }
};