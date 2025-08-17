class Solution {
public:
int solve(vector<int>& nums,int n,int i,int target, vector<vector<int>>&dp){
    if(i>=n || target<0) return false;
     if(target==0) return true;

if(dp[i][target]!=-1) return dp[i][target];
    int take=solve(nums,n,i+1,target-nums[i],dp);
    int not_take=solve(nums,n,i+1,target,dp);


    return dp[i][target]=take || not_take;
}
    bool canPartition(vector<int>& nums) {
       
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false; //cant be partitioned
        int target=sum/2;
       vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(nums,n,0,target,dp);
    }
};