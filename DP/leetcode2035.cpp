class Solution {
public:
int solve(int i,int count,int sum1,int n ,int total,vector<int>& nums,vector<vector<vector<int>>>&dp){
    if(i==2*n){
if(count==n){
    return abs(sum1-(total-sum1));
}else{
    return INT_MAX;
}
    }
if(dp[i][count][sum1]!=-1) return dp[i][count][sum1];

//put num in first array
int first=INT_MAX;
int second=INT_MAX;
if(count<n){
    first=solve(i+1,count+1,sum1+nums[i],n,total,nums,dp);

    //put in second array
second=solve(i+1,count,sum1,n,total,nums,dp);
}
return dp[i][count][sum1]=min(first,second);

}



    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
      //sum1->  sum of the first array so far
      //count -> how many elements are in the first array.
//index,count,sum1......

vector<vector<vector<int>>>dp(2*n,vector<vector<int>>(n+1,vector<int>(total+1,-1)));
        return solve(0,0,0,n,total,nums,dp);
    }
};