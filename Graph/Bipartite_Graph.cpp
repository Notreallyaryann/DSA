#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &adj)
    {
        int V = adj.size();
        vector<int> color(V, -1);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                q.push(i);
            }

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int j = 0; j < adj[node].size(); j++)
                {
                    if (color[adj[node][j]] == -1)
                    {
                        color[adj[node][j]] = (color[node] + 1) % 2;
                        q.push(adj[node][j]);
                    }
                    else if (color[adj[node][j]] == color[node])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
