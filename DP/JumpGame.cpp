class Solution {
public:
bool solve (int i,int n,vector<int>& nums, vector<int>&dp){
    if(i>=n-1) return true;
if(dp[i]!=-1) return dp[i];

for(int jump=1;jump<=nums[i];jump++){
    if(jump+i<n){
       if( solve(i+jump,n,nums,dp)) return true;
    }
}
return  dp[i]=false;
}
    bool canJump(vector<int>& nums) {
     int n=nums.size();
     vector<int>dp(n,-1);
     return solve(0,n,nums,dp);   
    }
};