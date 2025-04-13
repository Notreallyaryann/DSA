#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    void DFS(int node, vector<vector<int>> &adj, vector<int> &ans, vector<int> &vis)
    {
        vis[node] = 1;
        ans.push_back(node);
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!vis[adj[node][j]])
            {
                DFS(adj[node][j], adj, ans, vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> ans;
        DFS(0, adj, ans, vis);
        return ans;
    }
};