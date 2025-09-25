class Solution {
public:

bool canreach(vector<vector<int>>& heights,int maxEffort){
int n=heights.size();
        int m=heights[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({0,0});
        vis[0][0]=1;

int drow[]={-1,1,0,0};
int dcol[]={0,0,-1,1};



      while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
if(r==n-1 && c==m-1) return true;
    for(int i=0;i<4;i++){
       int nrow=r+drow[i];
        int ncol=c+dcol[i];

if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
    int diff=abs(heights[nrow][ncol]-heights[r][c]);
    if(diff<=maxEffort){
        vis[nrow][ncol]=1;
        q.push({nrow,ncol});
    }

}

    }
      }

return false;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
          int low=0,high=1e6;

         int ans=0;

          while(low<=high){
 int mid=low+(high-low)/2;

 if(canreach(heights,mid)){
    ans=mid;
    high=mid-1;
 }else low=mid+1;
          }
return ans;
    }
};