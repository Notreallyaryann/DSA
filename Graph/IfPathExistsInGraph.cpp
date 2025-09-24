class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // bidirectional
        }
    queue<int>q;
    vector<bool>vis(n,0);
    q.push(source);
    vis[source]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();
if(node==destination) return true;
        for(int j=0;j<adj[node].size();j++){
            if(!vis[adj[node][j]]){
                vis[adj[node][j]]=1;
                q.push(adj[node][j]);
            }
        }
    }

return false;

    }
};