class Solution {
  public:
  void find(Node*root,int pos,int &left,int &right){
      if(!root) return;
      
      left=min(left,pos);
      right=max(right,pos);
      
      find(root->left,pos-1,left,right);
      find(root->right,pos+1,left,right);
      
      
  }
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        int left=0,right=0;
        find(root,0,left,right);
        vector<vector<int>>ans(right-left+1);
        
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(-1*left);
        
        
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            
            int pos=index.front();
            index.pop();
            
            
            ans[pos].push_back(temp->data);
            
            if(temp->left){
                q.push(temp->left);
                index.push(pos-1);
            }
                if(temp->right){
                q.push(temp->right);
                index.push(pos+1);
            }
        }
        
        return ans;
        
    }
};