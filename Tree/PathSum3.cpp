class Solution {
public:
void DFS(TreeNode* root, long long targetSum,int &count){
    if(!root) return ;

//not necessray leaf ho
    if(root->val==targetSum) count++;
  
    DFS(root->left,targetSum-root->val,count);
    DFS(root->right,targetSum-root->val,count);
    
}
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int count =0;
// Count paths starting from the current node
        DFS(root,targetSum,count);

// Recursively check for other starting points
     count+=   pathSum(root->left,targetSum);
     count+=pathSum(root->right,targetSum);
        return count;
    }
};