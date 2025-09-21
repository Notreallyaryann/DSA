class Solution {
public:

int solve(int i,int buy,int n,vector<int>& prices, int fee,vector<vector<int>>&dp){
if(i>=n) return 0;
if(dp[i][buy]!=-1) return dp[i][buy];

if(buy){
    int take=-prices[i]+solve(i+1,0,n,prices,fee,dp);
    int skip=solve(i+1,1,n,prices,fee,dp);

    return dp[i][buy]=max(take,skip);
}
else{
    int sell=prices[i]-fee +solve(i+1,1,n,prices,fee,dp);

    int not_sell  =solve(i+1,0,n,prices,fee,dp);

    return dp[i][buy]=max(sell,not_sell);
}

}



    int maxProfit(vector<int>& prices, int fee) {
       int n=prices.size();
vector<vector<int>>dp(n+1,vector<int>(2,-1));
       return solve(0,1,n,prices,fee,dp); 
    }
};