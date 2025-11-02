class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
     
        queue<TreeNode*>q;
        vector<vector<int>>ans;
           if(!root) return ans;
       q.push(root);

while(!q.empty()){
int n=q.size();
 vector<int>levels; //to clear levels
while(n--){
      
    TreeNode*temp=q.front();
    q.pop();
    levels.push_back(temp->val);
    
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
}
ans.push_back(levels);
}

return ans;
    }
};