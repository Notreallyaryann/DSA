class Solution {
public:
int solve(vector<int>& coins,int amount,int i,int n, vector<vector<int>>&dp){
if(amount==0) return 0;
if(amount<0 || i>=n) return INT_MAX;

  if(dp[amount][i]!=-1) return dp[amount][i];

int take=solve(coins,amount-coins[i],i,n,dp);
if(take!=INT_MAX) take+=1;
int not_take=solve(coins,amount,i+1,n,dp);

return dp[amount][i]=min(take,not_take);


}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
       int result= solve(coins,amount,0,n,dp);
       if(result==INT_MAX) return -1;
       else return result;
    }
};