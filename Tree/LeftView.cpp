class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        
        if(!root) return {};
        queue<Node*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            
            ans.push_back(q.front()->data);
            
            while(n--){
                Node* temp=q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                
                if(temp->right) q.push(temp->right);
            }
            
            
        }
        return ans;
    }
};