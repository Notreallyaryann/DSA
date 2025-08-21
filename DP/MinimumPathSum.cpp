class Solution {
public:
int solve(int i,int j,int n ,int m ,vector<vector<int>>& grid,vector<vector<int>>&dp){
    if(i<0 || i>=n || j<0 || j>=m) return 1e9;
    if(i==n-1 && j==m-1) return grid[i][j];
if(dp[i][j]!=-1) return dp[i][j];
    int down=grid[i][j]+solve(i+1,j,n,m,grid,dp);
    int right=grid[i][j]+solve(i,j+1,n,m,grid,dp);


    return dp[i][j]= min(down,right);
}

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,grid,dp);
    }
};