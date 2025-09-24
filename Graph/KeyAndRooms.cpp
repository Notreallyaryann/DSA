class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,0);
        queue<int>q;
         q.push(0);
         vis[0]=1;

         while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int j=0;j<rooms[node].size();j++){
                int key=rooms[node][j];
                if(!vis[key]){
                    vis[key]=1;
                    q.push(key);
                }
            }
         }
for(int i=0;i<vis.size();i++){
    if(!vis[i]){
        return false;
    }
}
return true;
    }
};