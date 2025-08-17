class Solution {
public:
void bfs(int start,vector<vector<int>>& isConnected, vector<bool>&vis){
    queue<int>q;
    int n=isConnected.size();
    q.push(start);
    vis[start]=1;

    while(!q.empty()){
        int neighbour=q.front();
        q.pop();

        for(int j=0;j<n;j++){
            if(isConnected[neighbour][j]&& !vis[j]){
             q.push(j);
             vis[j]=1 ;
            }
        }
    }
}


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int province=0;
        vector<bool>vis(n,0);
for(int i=0;i<n;i++){
    if(!vis[i]){
        bfs(i,isConnected,vis);
        province++;
    }
}
return province;
    }
};