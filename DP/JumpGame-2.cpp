class Solution {
public:
int solve(int i,int n,vector<int>& nums,vector<int>&dp){

if(i>=n-1) return 0;
if(dp[i]!=-1) return dp[i];
int minJump=1e9;

for(int jump=1;jump<=nums[i];jump++){

    if(i+jump<n){
  minJump=min(minJump,1+solve(jump+i,n,nums,dp));
    }

}

 return dp[i]= minJump;
}

    int jump(vector<int>& nums) {
       int n=nums.size();
vector<int>dp(n,-1);
       return solve(0,n,nums,dp); 
    }
};