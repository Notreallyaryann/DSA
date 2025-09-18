class Solution {
  public:
  
bool solve(int i,vector<int>& arr, int sum,int n,  vector<vector<int>>&dp){
      if(sum==0) return true;
      if(i>=n) return false;
      
      
      if(dp[i][sum]!=-1) return dp[i][sum];
      //choose curr element if its not greater than sum
      bool take=false;
      if(arr[i]<=sum){
      take=   solve(i+1,arr,sum-arr[i],n,dp);
       }
      
      
  //skip
      
      
   bool not_take= solve(i+1,arr,sum,n,dp);
      
     return  dp[i][sum]=take||not_take ;
      
  }
  
  
    bool isSubsetSum(vector<int>& arr, int sum) {
     int n=arr.size();
     vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,arr,sum,n,dp);
    }
};