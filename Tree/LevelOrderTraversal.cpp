class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
    vector<vector<int>>ans;
    if(!root) return ans;
    
    queue<Node*>q;
    q.push(root);
    

    
    while(!q.empty()){
        int n=q.size();
        vector<int>level;
        while(n--){
            Node*temp=q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(level);
    }
    return ans;
    }
};