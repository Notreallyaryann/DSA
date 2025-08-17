class Solution {
public:
int solve(int amount, vector<int>& coins,int n,int i, vector<vector<int>>&dp){
    if(i>=n) return 0;
    if(amount<0) return 0;
    if(amount==0) return 1;
if(dp[amount][i]!=-1) return dp[amount][i];

    int take=solve(amount-coins[i],coins,n,i,dp);
    int not_take=solve(amount,coins,n,i+1,dp);

    return dp[amount][i]=take+not_take;

}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        return solve(amount,coins,n,0,dp);
    }
};