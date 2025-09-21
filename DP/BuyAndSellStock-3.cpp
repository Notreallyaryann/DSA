class Solution {
public:
int solve(int i,int transaction,int buy,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
    if(transaction ==0 || i==n) return 0;

if(dp[i][transaction][buy]!=-1) return dp[i][transaction][buy];
if(buy){

//can buy
int take=-prices[i]+solve(i+1,transaction,0,prices,n,dp);

//didnt buy

int skip=solve(i+1,transaction,1,prices,n,dp);


return dp[i][transaction][buy]= max(take,skip);
}
else{
//sell


int sell=prices[i]+solve(i+1,transaction-1,1,prices,n,dp);
//not sell

int not_sell=solve(i+1,transaction,0,prices,n,dp);


return dp[i][transaction][buy]= max(sell,not_sell);
}

}


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
//index,transaction,buy
vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(0,2,1,prices,n,dp);
    }
};