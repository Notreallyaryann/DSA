class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
     queue<pair<int,int>>q;

//first row
for(int j=0;j<m;j++){
    if(grid[0][j]==1){
        grid[0][j]=2;
        q.push({0,j});
    }
}
// first col
for(int i=0;i<n;i++){
    if(grid[i][0]==1){
        grid[i][0]=2;
        q.push({i,0});
    }
}

//last row
for(int j=0;j<m;j++){
    if(grid[n-1][j]==1){
        grid[n-1][j]=2;
        q.push({n-1,j});
    }
}
// last col
for(int i=0;i<n;i++){
    if(grid[i][m-1]==1){
        grid[i][m-1]=2;
        q.push({i,m-1});
    }
}
int drow[]={   -1,0,1,0};
int dcol[]={0,1,0,-1};

while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();

    for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];

    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
        grid[nrow][ncol]=2;
        q.push({nrow,ncol});

    }
    }
}
int count=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==1){
            count++;
        }
    }
}


return count;

    }
};