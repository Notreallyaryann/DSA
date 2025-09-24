class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
vector<bool>vis(n,0);
queue<int>q;
int completeComponents=0;
for(int start=0;start<n;start++){
    if(!vis[start]){
       vis[start]=1;
        q.push(start);


vector<int>nodes;   //to cal vertices
int edgecount=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        nodes.push_back(node);


        for(int j=0;j<adj[node].size();j++){
         edgecount++;
         if(!vis[adj[node][j]]){
            vis[adj[node][j]]=1;
            q.push(adj[node][j]);
         }
        }
    }
    int k=nodes.size();
int expectedEdges= k * (k - 1) / 2;
int actualEdges=edgecount/2;

if(actualEdges==expectedEdges) completeComponents++;
    }
}


return completeComponents;
    }
};