

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        //Directed graph
  //Single source shortest path algo(negative weight)
  //relax edges(v-1) times then, relax one more time aur agar distance phir se change hoti hai then their is cycle
  vector<int>dist(V,1e8);

  dist[src]=0;
  int e=edges.size();
  
  //relax edges v-1 times
  
  for(int i=0;i<V-1;i++){
      for(int j=0;j<e;j++){
          
  
    
 int u=edges[j][0];
  int v=edges[j][1];
  int w=  edges[j][2];
  
  
  
   if (dist[u] != 1e8 && dist[u] + w < dist[v]){
     dist[v]=dist[u]+w;
 
      }   
  }
  }
 //relax one more time to detect cycle
 
for(int j=0;j<e;j++){
 int u=edges[j][0];
  int v=edges[j][1];
  int w=  edges[j][2];
  
   if (dist[u] != 1e8 && dist[u] + w < dist[v]){
   //cycle detected
   vector<int>ans;
   ans.push_back(-1);
   return ans;
 
      } 
}
     return dist;
    }
};
