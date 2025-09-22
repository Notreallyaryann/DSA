class Solution {
  public:
  
  int solve(int i,vector<int>& val, vector<int>& wt, int capacity,int n, vector<vector<int>>&dp){
      
if(i>=n) return 0;
int take=INT_MIN;
if(dp[i][capacity]!=-1) return dp[i][capacity];
if(wt[i]<=capacity){
    take=val[i]+solve(i,val,wt,capacity-wt[i],n,dp);
}

int not_take=solve(i+1,val,wt,capacity,n,dp);


return dp[i][capacity]=max(take,not_take);
  }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
        return solve(0,val,wt,capacity,n,dp);
    }
};