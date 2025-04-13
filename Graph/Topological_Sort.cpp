#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }
        vector<int> Indegree(V);
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                Indegree[adj[i][j]]++;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (!Indegree[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++)
            {
                Indegree[adj[node][j]]--;
                if (!Indegree[adj[node][j]])
                {
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};
