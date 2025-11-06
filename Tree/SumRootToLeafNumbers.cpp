class Solution {
public:
int  find(TreeNode* root,int sum){
    if(!root) return 0;

    sum=sum*10+root->val;
    if(!root->left && !root->right) return sum ;

 return find(root->left,sum)+ find(root->right,sum);
}
    int sumNumbers(TreeNode* root) {
   
      return  find(root,0);
       
    }
};