

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> Indegree(V, 0);
        vector<vector<int>> adj(V);
        vector<int> ans;
        queue<int> q;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);  // u -> v
        }
        
        // compute indegree
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                Indegree[adj[i][j]]++;
            }
        }

        // push nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (Indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // BFS (Kahn's algo)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int j = 0; j < adj[node].size(); j++) {
                Indegree[adj[node][j]]--;
                if (Indegree[adj[node][j]] == 0) {
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};




