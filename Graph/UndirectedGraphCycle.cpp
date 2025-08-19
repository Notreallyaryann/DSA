//DFS 

class Solution {
  public:
  
 bool CycleDetect(int node,int parent, vector<vector<int>>&adj, vector<bool>&vis){
     vis[node]=1;
     
     for(int j=0;j<adj[node].size();j++){
         if(parent==adj[node][j]) continue;
         if(vis[adj[node][j]]) return 1; //cycle mil gyi
        if( CycleDetect(adj[node][j],node,adj,vis)){
         return 1;   
        }
        
     }
     return 0;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
     vector<vector<int>>adj(V);
     vector<bool>vis(V,0);
     for(auto & edge:edges){
         int u=edge[0];
         int v=edge[1];
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     //node,parent,adj,vis
     for(int i=0;i<V;i++){
         if(!vis[i]){
             if(CycleDetect(i,-1,adj,vis)){
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
  
bool CycleDetect(int start,  vector<vector<int>>&adj,   vector<bool>&vis){
    queue<pair<int,int>>q;
    q.push({start,-1});   //node,parent
    vis[start]=1;

    
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        
        for(int j=0;j<adj[node].size();j++){
         if(adj[node][j]==parent) continue;
         if(vis[adj[node][j]]) return true;
         vis[adj[node][j]]=1;
         q.push({adj[node][j],node});
        }
    }
    return false;
}
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
     vector<vector<int>>adj(V);
     vector<bool>vis(V,0);
     for(auto & edge:edges){
         int u=edge[0];
         int v=edge[1];
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     //node,parent,adj,vis
     for(int i=0;i<V;i++){
         if(!vis[i]){
             if(CycleDetect(i,adj,vis)){
                 return true;
             }
         }
     }
    return false;
    }
};