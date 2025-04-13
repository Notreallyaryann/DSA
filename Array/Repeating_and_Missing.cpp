#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int totalElements = n * m;
        vector<int> hash(totalElements + 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int value = grid[i][j];
                if (value >= 1 && value <= totalElements)
                {
                    hash[value]++;
                }
            }
        }

        int missing = -1, repeating = -1;
        for (int i = 0; i <= n * m; i++)
        {
            if (hash[i] == 2)
            {
                repeating = i;
            }
            else if (hash[i] == 0)
            {
                missing = i;
            }
        }
        return {repeating, missing};
    }
};