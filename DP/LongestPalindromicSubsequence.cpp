class Solution {
public:

int solve(string &s,string &t,int n,int m,vector<vector<int>>&dp){
    if(n==0 || m==0) return 0;
if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==t[m-1]){
        return dp[n][m]= 1+solve(s,t,n-1,m-1,dp);
    }else{
        return dp[n][m]=max(solve(s,t,n-1,m,dp),solve(s,t,n,m-1,dp));
    }
}


int lcs(string s,string t){
int n=s.size();
int m=t.size();
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
return solve(s,t ,n,m,dp);
}
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        return lcs(s,t);

    }
};