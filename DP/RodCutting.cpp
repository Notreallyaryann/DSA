class Solution {
  public:
  int solve(int i,int n,vector<int> &price, vector<vector<int>>&dp){
      
    if (n == 0) return 0;
       if (i >= price.size()) return 0;
     if(dp[i][n]!=-1) return dp[i][n];
     int not_cut=solve(i+1,n,price,dp);
     int cut=INT_MIN;
     if(i+1<=n){
      cut=price[i]+solve(i,n-(i+1),price,dp);
     }
     return dp[i][n]= max(cut,not_cut);
  }
    int cutRod(vector<int> &price) {
        // code here
       
      int n=price.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(0,n,price,dp);      
    }
};