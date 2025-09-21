class Solution {
public:

int solve(int i,int k, int buy,int n,vector<int>& prices, vector<vector<vector<int>>>&dp){
    if(k==0 || i==n) return 0;
if(dp[i][k][buy]!=-1) return dp[i][k][buy];
if(buy){
    int take=-prices[i]+solve(i+1,k,0,n,prices,dp);

int not_take=solve(i+1,k,1,n,prices,dp);


return dp[i][k][buy]=max(take,not_take);
}
else{
int sell=prices[i]+solve(i+1,k-1,1,n,prices,dp);

int not_sell=solve(i+1,k,0,n,prices,dp);

return dp[i][k][buy]= max(sell,not_sell);

}


}

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
    //index,transaction,buy   

 vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1))) ;   
        return solve(0,k,1,n,prices,dp);
    }
};