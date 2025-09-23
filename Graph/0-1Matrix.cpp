class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,-1));
      queue<pair<int,int>>q;


//push all 0-cells into queue
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(mat[i][j]==0){
            q.push({i,j});
            dis[i][j]=0;
        }
    }
}

 int drow[] = {-1,0,1,0};
 int dcol[] = {0,1,0,-1};

while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
q.pop();
    for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];

if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dis[nrow][ncol]==-1){
    dis[nrow][ncol]=dis[r][c]+1;
    q.push({nrow,ncol});
}

    }
}
return dis;

    }
};