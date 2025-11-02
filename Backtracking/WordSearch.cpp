class Solution {
public:
int n,m;
bool DFS(vector<vector<char>>& board, string word,vector<vector<int>>&vis,int i,int j,int idx){
int drow[] = {1, -1, 0, 0};
int dcol[] = {0, 0, 1, -1};


if(idx==word.size()) return true;
if(i<0 || i>=n || j<0 || j>=m) return false;
if(vis[i][j] || board[i][j]!=word[idx]) return false;


vis[i][j]=1;
for(int dir=0;dir<4;dir++){
    int new_r=i+drow[dir];
    int new_c=j+dcol[dir];

    if(DFS(board,word,vis,new_r,new_c,idx+1)) return true;
}
vis[i][j]=false; //backtrack
return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(DFS(board,word,vis,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};