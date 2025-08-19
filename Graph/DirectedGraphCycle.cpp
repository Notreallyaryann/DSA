//DFS
class Solution {
  public:
  
  
  bool   DetectCycle(int node,vector<vector<int>>&adj, vector<bool>&path,vector<bool>&vis){
      path[node]=1;
      //ek path ko baar baar visit kr rhe isiliye use vis
 vis[node]=1;
      for(int j=0;j<adj[node].size();j++){
          if(path[adj[node][j]]) return true;
          //agar already vis hai to detectcycle ka code chlane ka need nhi hai
          if(vis[adj[node][j]]) continue;
          if(DetectCycle(adj[node][j],adj,path,vis)){
              return true;
          }
      }
      path[node]=0;
      return false;
  }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<bool>path(V,0);
        vector<bool>vis(V,0);
        for(auto &edge :edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!path[i]){
                if(  DetectCycle(i,adj,path,vis)){
                    return true;
                }
            }
        }
        return false;
      
    }
};





//BFS

class Solution {
  public:
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
  //agar graph cyclic hoga aur hum uska topological sort nikalege then sare (count!=V) sare 
      vector<vector<int>>adj(V);
       vector<int>Indegree(V,0);
       vector<int>ans;
       queue<int>q;
      for(auto &edge:edges){
          int u=edge[0];
          int v=edge[1];
          
          adj[u].push_back(v);
      
      }
   for(int i=0;i<V;i++){
       for(int j=0;j<adj[i].size();j++){
           Indegree[adj[i][j]]++;
       }
   }
  for(int i=0;i<V;i++){
      if(Indegree[i]==0){
          q.push(i);
      }
  }
  while(!q.empty()){
      int node=q.front();
      q.pop();
      ans.push_back(node);
      for(int j=0;j<adj[node].size();j++){
          Indegree[adj[node][j]]--;
          if(Indegree[adj[node][j]]==0){
              q.push(adj[node][j]);
          }
      }
  }
  int count=ans.size();
  if(count!=V){
      return true;
  }
  return false;
    }
};