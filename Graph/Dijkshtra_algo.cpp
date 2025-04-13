#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        vector<int> explored(V, 0);
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            if (explored[node] == 1)
            {
                continue;

                explored[node] = 1;
            }
            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                if (!explored[neighbour] && dist[node] + weight < dist[neighbour])
                {
                    dist[neighbour] = dist[node] + weight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        return dist;
    }
};