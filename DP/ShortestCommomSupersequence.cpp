
//MLE


class Solution {
public:

string solve(string &str1, string &str2,int n,int m,vector<vector<string>>&dp){

  if(n == 0) return str2.substr(0, m);
  if(m == 0) return str1.substr(0, n);

if(dp[n][m]!="") return dp[n][m];
if(str1[n-1]==str2[m-1]){
    return solve(str1,str2,n-1,m-1,dp)+str1[n-1];
}

string take1=solve(str1,str2,n-1,m,dp)+str1[n-1];
string take2=solve(str1,str2,n,m-1,dp)+str2[m-1];


return dp[n][m]=(take1.size() < take2.size()) ? take1 : take2;


}

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<string>>dp(n+1,vector<string>(m+1,""));
    return solve(str1,str2,n,m,dp);
    }
};