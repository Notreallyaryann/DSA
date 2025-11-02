//TLE(leetcode) 
//TC=0(n^2)

class Solution {
public:
void Inorder(TreeNode* root,vector<int>&ans){
    if(!root) return ;

    Inorder(root->left,ans);
    ans.push_back(root->val);
    Inorder(root->right,ans);
}


bool isValidBST(TreeNode* root){
    vector<int>ans;
    Inorder(root,ans);
    int n=ans.size();
    for(int i=0;i<n-1;i++){
        if(ans[i]>=ans[i+1]) return false;
    }
    return true;
}

int FindSum(TreeNode* root){
    if(!root) return 0;
    return root->val+FindSum(root->left)+FindSum(root->right);
}

    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        int maxSum=0;

        if(isValidBST(root)){
            maxSum=max(maxSum,FindSum(root));
        }
        //now left and right subtree
        int leftMax=maxSumBST(root->left);
        int rightMax=maxSumBST(root->right);

         return max({maxSum, leftMax, rightMax});
    }
};