class Solution {
public:
int solve(vector<int>& days,vector<int>& costs,int n,int i, vector<int>&dp){
if(i>=n) return 0;
if(dp[i]!=-1) return dp[i];
//1 day pass
int cost1=costs[0]+solve(days,costs,n,i+1,dp);

//7 days pass
int j=i;
while(j<n && days[j]<days[i]+7){
    j++;
} // loop tells where the coverage ends
int cost7=costs[1]+solve(days,costs,n,j,dp);

//30 days pass
j=i;

while(j<n && days[j]<days[i]+30){
    j++;
}
int cost30=costs[2]+solve(days,costs,n,j,dp);

return dp[i]=min({cost1,cost7,cost30});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(days,costs,n,0,dp);
    }
};