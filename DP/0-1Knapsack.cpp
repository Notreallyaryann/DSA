class Solution {
  public:
  
  
  int solve(int i,int W, vector<int> &val, vector<int> &wt,int n,vector<vector<int>>&dp){
      if(i>=n) return 0;
      
     if(dp[i][W]!=-1) return dp[i][W];
      
int take=0;

if(wt[i]<=W){
    take=val[i]+solve(i+1,W-wt[i],val,wt,n,dp);
}

int not_take=solve(i+1,W,val,wt,n,dp);





return dp[i][W]=max(take,not_take);

  }
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(0,W,val,wt,n,dp);
    }
};