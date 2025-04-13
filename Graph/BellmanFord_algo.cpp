#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        int e = edges.size();
        dist[src] = 0;
        // relax edges v-1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (int j = 0; j < e; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // to detect cycle
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] == 1e8)
                continue;
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {

                // cycle detected
                vector<int> ans;
                ans.push_back(-1);
                return ans;
            }
        }
        return dist;
    }
};
