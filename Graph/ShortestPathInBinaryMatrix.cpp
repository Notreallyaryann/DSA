class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

 if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
queue<pair<pair<int,int>, int>> q;

vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

q.push({{0,0},1});   //dist[0][0]=1

int drow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

while(!q.empty()){
    int r=q.front().first.first;
    int c=q.front().first.second;
    int d=q.front().second;
q.pop();

if(r==n-1 && c==n-1) return d;

for(int i=0;i<8;i++){
    int nrow=r+drow[i];
    int ncol=c+dcol[i];

if(nrow>=0 && nrow<n &&  ncol>=0 && ncol<m &&grid[nrow][ncol]==0 &&dist[nrow][ncol]>d+1){
    dist[nrow][ncol]=d+1;
    q.push({{nrow,ncol},d+1});
}
}


}
return -1;
    }
};