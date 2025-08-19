class Solution {
  public:
  
  void DFS(int node,vector<vector<int>>& adj, vector<bool>&vis,  vector<int>&ans){
   vis[node]=1;
   ans.push_back(node);
   
   
   for(int j=0;j<adj[node].size();j++){
       if(!vis[adj[node][j]]){
           vis[adj[node][j]]=1;
           DFS(adj[node][j],adj,vis,ans);
       }
   }
   
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>vis(n,0);
        vector<int>ans;
        
        DFS(0,adj,vis,ans);
        return ans;
    }
};