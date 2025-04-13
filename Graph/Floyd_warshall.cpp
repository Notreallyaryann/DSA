#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    void shortestDistance(vector<vector<int>> &mat)
    {

        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == -1) // edge exist nhi krti
                    mat[i][j] = INT_MAX;
            }
        }
        // k=intermediate node
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][k] == INT_MAX || mat[k][j] == INT_MAX)
                        continue;
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == INT_MAX)
                    mat[i][j] = -1;
            }
        }
    }
};