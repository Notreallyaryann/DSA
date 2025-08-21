//TLE

class Solution {
public:
int solve(int i,int j,int n,int m,vector<vector<int>>& matrix, vector<vector<int>>&dp){
    if(i<0 ||i>=n || j<0 || j>=m) return 1e9;

    //any cell in the last row is a valid ending point
       if(i==n-1 ) return matrix[i][j];

       if(dp[i][j]!=-1) return dp[i][j];

int down=matrix[i][j]+solve(i+1,j,n,m,matrix,dp);
int diag_left=matrix[i][j]+solve(i+1,j-1,n,m,matrix,dp);
int diag_right=matrix[i][j]+solve(i+1,j+1,n,m,matrix,dp);

return dp[i][j]=min({down,diag_left,diag_right});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int ans = 1e9;

        // Try all possible starting positions in first row
        //A falling path starts at any element in the first row
      for (int j = 0; j < m; j++) {
            ans = min(ans, solve(0, j, n, m, matrix,dp));
        }

        return ans;
    }
};




//BottomUp


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();

       vector<vector<int>>dp(n,vector<int>(m,0));

       for(int j=0;j<m;j++) dp[n-1][j]=matrix[n-1][j];

       //start from second lasr row

       for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
        int down=matrix[i][j]+dp[i+1][j];
 int diag_left = matrix[i][j] + ((j>0) ? dp[i+1][j-1] : 1e9);
int diag_right = matrix[i][j] + ((j<m-1) ? dp[i+1][j+1] : 1e9);


        dp[i][j]= min({down,diag_left,diag_right});
        }
       } 
       int ans=1e9;
       for(int j=0;j<m;j++){
         ans=min(ans,dp[0][j]);
       }
       return ans;
    }
};