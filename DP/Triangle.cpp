

//TLE

class Solution {
public:
int solve(vector<vector<int>>& triangle,int n,int i,int j, vector<vector<int>>&dp){
if(i==n-1) return triangle[i][j];
if(dp[i][j]!=-1) return dp[i][j];
    int left_diag=solve(triangle,n,i+1,j,dp); //left diag j same
    int right_diag=solve(triangle,n,i+1,j+1,dp);

    return dp[i][j]= triangle[i][j]+ min(left_diag,right_diag); //curr val + min of left and right
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(triangle,n,0,0,dp);
    }
};




//M-2
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());  // last row copy kar li


        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};