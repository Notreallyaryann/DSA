class Solution {
public:
int solve(string word1, string word2,int n ,int m,vector<vector<int>>&dp){
  if(n==0) return m;
  if(m==0) return n;
if(dp[n][m]!=-1) return dp[n][m];
    if(word1[n-1]==word2[m-1]){
        return dp[n][m]=solve(word1,word2,n-1,m-1,dp);
    }
//if not matched then apply 3 op

//insert

int insertop=1+solve(word1,word2,n,m-1,dp);

//delete

int deleteop=1+solve(word1,word2,n-1,m,dp);

//replace
int replaceop=1+solve(word1,word2,n-1,m-1,dp);
return dp[n][m]= min({insertop,deleteop,replaceop});
}
    int minDistance(string word1, string word2) {
      int n=word1.size();
      int m=word2.size();
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
  return   solve(word1,word2,n,m,dp);  
    }
};