class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        queue<int>q;
        vector<int>color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);
        
 while(!q.empty()){
    int node=q.front();
    q.pop();

    for(int i=0;i<graph[node].size();i++){
        if(color[graph[node][i]]==-1){
            color[graph[node][i]]= (color[node]+1)%2;
            q.push(graph[node][i]);
        }
        else if(color[graph[node][i]]==color[node]){
            return false;
        }
    }
 }
     }
        }
 return true;
    }
};