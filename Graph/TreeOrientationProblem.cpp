//leetcode 1466

class Solution {
public:
//tree reorientation problem
    int minReorder(int n, vector<vector<int>>& connections) {
vector<vector<pair<int,int>>>adj(n);


      for(auto &edge:connections){
        int u=edge[0];
        int v=edge[1];

        adj[u].push_back({v,1}); // u -> v (original direction)
        adj[v].push_back({u,0}); //v-u (reverse direction)-> towards 0

      }  

queue<int>q;
vector<bool>vis(n,0);
q.push(0);
vis[0]=1;
int changes=0;

while(!q.empty()){
int node=q.front();
q.pop();


for(int j=0;j<adj[node].size();j++){
    int neighbour=adj[node][j].first;
    int dir=adj[node][j].second;

    if(!vis[neighbour]){
        vis[neighbour]=1;
        q.push(neighbour);
        if(dir==1) changes++;
    }
}
}
return changes;
    }
};