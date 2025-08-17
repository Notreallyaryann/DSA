class Solution {
public:

int M=1e9 + 7;
vector<vector<int>>adj={
    {4,6}, //0
    {6,8}, //1
    {7,9},  //2
    {8,4},  //3
    {0,3,9}, //4
    {},   //5
    {0,1,7},   //6
    {2,6}, //7
    {1,3},   //8
    {2,4},   //9

};
int solve(int n,int cell,vector<vector<int>>&dp){
    if(n==0) return 1; // we got our number of length n 
if(dp[n][cell]!=-1) return dp[n][cell];
    //visit neighbours
int ans=0;
for(int &nextcell:adj[cell]){
    ans=(ans+solve(n-1,nextcell,dp))%M;
}
return dp[n][cell]=ans;
}
    int knightDialer(int n) {
       int result=0;
 vector<vector<int>>dp(n+1,vector<int>(10,-1));
       for(int cell=0;cell<=9;cell++){
        result=(result+solve(n-1,cell,dp))%M;
       } 
       return result;
    }
};