class Solution {
public:
void DFS(TreeNode* root, int targetSum,    vector<vector<int>>&result, vector<int>&path){
    if(!root) return ;

    path.push_back(root->val);
    if(!root->left && !root->right && root->val==targetSum){
        result.push_back(path);
    }
    else {
    DFS(root->left,targetSum-root->val,result,path);
    DFS(root->right,targetSum-root->val,result,path);
    }

    path.pop_back(); //backtrack
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>path;
        DFS(root,targetSum,result,path);
        return result;
    }
};