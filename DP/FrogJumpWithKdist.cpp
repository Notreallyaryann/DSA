class Solution {
public:


int solve(int i,int n,int k,vector<int>& heights,vector<int>&dp){
    if(i==n-1) return 0;

if(dp[i]!=-1) return dp[i];

int one_step=INT_MAX;

if(i+1<n){
one_step=abs(heights[i+1]-heights[i])+solve(i+1,n,k,heights,dp);
}
int k_step=INT_MAX;
if(i+k<n){
k_step=abs(heights[i+k]-heights[i])+solve(i+k,n,k,heights,dp);
}

return dp[i]=min(one_step,k_step);

}
    int frogJump(vector<int>& heights, int k) {
    int n=heights.size();
    vector<int>dp(n+1,-1);
return solve(0,n,k,heights,dp);
    }
};