class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';  // mark as visited

         while (!q.empty()) {
            int r = q.front().first;
          int c = q.front().second;
          q.pop();

        for (int k = 0; k < 4; k++) {
                            int nrow = r + drow[k];
       int ncol = c + dcol[k];

  if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1') {
      grid[nrow][ncol] = '0';
            q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }

        return island;
    }
};