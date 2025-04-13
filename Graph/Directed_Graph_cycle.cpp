#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        int v = edges.size();
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> ans;
        vector<int> Indegree(V, 0);
        queue<int> q;
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
        int count = ans.size();
        // matlab kuch nodes kabhi process nhi hue to cycle exist krti hai
        if (count != V)
            return true;
        else
            return false;
    }
};