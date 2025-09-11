class Solution {
  public:
  
  int solve(vector<int> &coins,int n,int sum,int i, vector<vector<int>>&dp){
      if(i>=n || sum<0) return 1e9;
  
      if(sum==0) return 0;  //no coin needed
      
      if(dp[i][sum]!=-1) return dp[i][sum];
      int take=1+solve(coins,n,sum-coins[i],i,dp);
      int not_take=solve(coins,n,sum,i+1,dp);
      
      
      return dp[i][sum]=min(take,not_take);
      
      
  }
  
  
  
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    int ans=solve(coins,n,sum,0,dp);
    if(ans==1e9) return -1;
    else return ans;
    }
};