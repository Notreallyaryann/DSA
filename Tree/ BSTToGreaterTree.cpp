class Solution {
public:
int solve(TreeNode* root, int total){
    if(!root) return 0;
    solve(root->right,total);
    total+=root->val;
     root->val=total;
    solve(root->left,total);
}
    TreeNode* convertBST(TreeNode* root) {
        int total=0;
        solve(root,total);
        return root;
    }
};