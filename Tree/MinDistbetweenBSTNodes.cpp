class Solution {
public:
void Inorder(TreeNode* root,vector<int>&ans){
    if(!root) return;
    Inorder(root->left,ans);
    ans.push_back(root->val);
    Inorder(root->right,ans);
}
    int minDiffInBST(TreeNode* root) {
        vector<int>ans;
        Inorder(root,ans);
        int n=ans.size();
        int minDist=INT_MAX;

        for(int i=0;i<n-1;i++){
            minDist=min(minDist,ans[i+1]-ans[i]);
        }
        return minDist;
    }
};