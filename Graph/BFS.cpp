class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        queue<int>q;
        vector<bool>vis(n);
        vector<int>ans;
        
        q.push(0);
        vis[0]=1;
        
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int j=0;j<adj[node].size();j++){
                if(!vis[adj[node][j]]){
               vis[adj[node][j]]=1;
                q.push(adj[node][j]);
            }
        }
        }
        return ans;
    }
};