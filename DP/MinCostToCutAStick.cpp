class Solution {
public:
int solve(vector<int>& cuts,int l,int r,vector<vector<int>>&dp){
if(r-l<2) return 0; //we cant cut 

if(dp[l][r]!=-1) return dp[l][r];
int result=INT_MAX;
for(int index=l+1;index<=r-1;index++){
int cost =(cuts[r]-cuts[l]) +
solve(cuts,l,index,dp)+
solve(cuts,index,r,dp);

result =min(result,cost);
}
return dp[l][r]=result;
}
    int minCost(int n, vector<int>& cuts) {
       //just kaatne se pehle uska length kya hai that is cost
       //alag alag way me katege to shayad aur acha ans mil jaye 
       //cuts l+1 se start hai aur r-1 per end

       sort(cuts.begin(),cuts.end());
       cuts.insert(begin(cuts),0); //0 starting of stick
       cuts.push_back(n); //end of stick
       //length of stick=cut[r]-cut[l]
int m=cuts.size();
       vector<vector<int>>dp(m,vector<int>(m+1,-1));
return solve(cuts,0,m-1,dp);
 
    }
};