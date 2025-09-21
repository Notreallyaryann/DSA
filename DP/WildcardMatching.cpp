class Solution {
public:
bool solve(string &s, string &p,int n,int m,vector<vector<int>>&dp){
if(n==0 && m==0) return true;

if(m==0) return false;

if (n == 0) {
    for (int j = 0; j < m; j++)
        if (p[j] != '*') return false;
    return true;
}

if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==p[m-1] || p[m-1]=='?'){
return dp[n][m]=solve(s,p,n-1,m-1,dp);
    }

if(p[m-1]=='*'){
   // first me star matched second star means nothing
return dp[n][m]=solve(s,p,n-1,m,dp) || solve(s,p,n,m-1,dp);
}

return false;
}




    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n,m,dp);
    }
};