// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);  
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        vector<bool> vis(V, 0);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        p.push({0, src}); // dist,node
  
        while (!p.empty()) {
            int node = p.top().second;  
            p.pop();
            if (vis[node]) continue;
            vis[node] = 1;

            for (int j = 0; j < adj[node].size(); j++) {  
                int neighbour = adj[node][j].first;
                int wt = adj[node][j].second;
         
                if (!vis[neighbour] && dist[node] + wt < dist[neighbour]) {
                    dist[neighbour] = dist[node] + wt;   
                    p.push({dist[neighbour], neighbour});
                }
            }
        }
        return dist;  
    }
};
