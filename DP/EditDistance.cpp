class Solution {
public:
int solve(string &word1,string &word2,int n,int m,vector<vector<int>>&dp){
    if(n==0) return m;
    if(m==0) return n;
if(dp[n][m]!=-1) return dp[n][m];
if(word1[n-1]==word2[m-1]){
    return dp[n][m]=solve(word1,word2,n-1,m-1,dp);
}
//if mismatch try insert,delete,replace

//After inserting, word2[j-1] is matched, so we move j-1
int insertop=solve(word1,word2,n,m-1,dp);

//After replacement both last characters are the same so move index back
int replaceop=solve(word1,word2,n-1,m-1,dp);

//After deleting, move i-1 because that character is gone
int deleteop=solve(word1,word2,n-1,m,dp);

//Each operation costs 1 step
return dp[n][m]=1+min({insertop,replaceop,deleteop});

}
    int minDistance(string word1, string word2) {
      int n=word1.size();
      int m=word2.size();
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return solve(word1,word2,n,m,dp);  
    }
};