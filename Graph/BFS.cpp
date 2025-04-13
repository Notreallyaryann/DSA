#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        // Code here
        int v = adj.size();
        vector<bool> vis(v, 0);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!vis[adj[node][j]])
                {
                    vis[adj[node][j]] = 1;
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};
