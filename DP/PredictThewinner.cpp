class Solution {
public:
int solve(vector<int>& nums,int left,int right, vector<vector<int>>&dp){
    if(left==right) return nums[left];
if(dp[left][right]!=INT_MIN) return dp[left][right];

//diff nikal rhe hai player1-player2
    int pickleft=nums[left]-solve(nums,left+1,right,dp);
    int pickright=nums[right]-solve(nums,left,right-1,dp);

    return dp[left][right]= max(pickleft,pickright);
}
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
     int diff=solve(nums,0,n-1,dp);
     if (diff>=0){ //Player 1 wins.
        return true;
     }else{
        return false;
     }
    }
};