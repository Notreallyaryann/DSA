class Solution {
  public:
  
  int solve(int i, vector<int>& arr, int n,int target,   vector<vector<int>>&dp){
    if (i >= n) {
    if (target == 0) {
        return 1;  // valid subset
    } else {
        return 0;  // sum does not match target
    }
}
   if(dp[i][target]!=-1) return dp[i][target];  
     int take=0;
     
     if(arr[i]<=target){
   take=solve(i+1,arr,n,target-arr[i],dp);
     }
     int not_take=solve(i+1,arr,n,target,dp);
      
      return dp[i][target]=take+not_take;
  }
  
  
  
    int perfectSum(vector<int>& arr, int target) {
      int n=arr.size();
      vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
return solve(0,arr,n,target,dp);
    }
};