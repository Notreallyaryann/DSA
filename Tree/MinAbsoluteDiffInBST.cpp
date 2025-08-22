class Solution {
public:
void inorder(TreeNode* root,vector<int>&ans){

    if(!root) return ;

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);


}
    int getMinimumDifference(TreeNode* root) {
    //BST->inorder=sorted
vector<int>ans;
  inorder(root,ans);
int mindiff=INT_MAX;
for(int i=0;i<ans.size()-1;i++){
mindiff=min(mindiff,abs(ans[i+1]-ans[i]));
}
return mindiff;
    }
};