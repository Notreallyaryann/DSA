class Solution {
public:
int solve(int i,int buy,int n, vector<int>& prices,vector<vector<int>>&dp){

    if(i>=n) return 0;
if(dp[i][buy]!=-1) return dp[i][buy];
if(buy){

int take=-prices[i]+solve(i+1,0,n,prices,dp);
int skip=solve(i+1,1,n,prices,dp);

return  dp[i][buy]=max(take,skip);
}
else{
    //i+2 because of cooldown
    int sell=prices[i]+solve(i+2,1,n,prices,dp);
    int not_sell=solve(i+1,0,n,prices,dp);

    return  dp[i][buy]=max(sell,not_sell);
}
}


    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        //index,buy
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,n,prices,dp);

    }
};