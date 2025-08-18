class Solution {
public:
int solve(string &word1,string &word2,int n,int m, vector<vector<int>>&dp){
if(n==0 || m==0) return 0;
if(dp[n][m]!=-1) return dp[n][m];
if(word1[n-1]==word2[m-1]){
    return dp[n][m]= 1+solve(word1,word2,n-1,m-1,dp);
}else{
    return dp[n][m]=max(solve(word1,word2,n-1,m,dp),solve(word1,word2,n,m-1,dp));
}

}
int lcs(string &word1,string &word2,int n,int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(word1,word2,n,m,dp);
}

    int minDistance(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
int lcslen=lcs(word1,word2,n,m);
       int  insertion=m-lcslen;
       int deletion=n-lcslen;

       return insertion+deletion;
    }
};