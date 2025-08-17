class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        vector<int>ans;
       for(auto &edge : prerequisites){
        int u=edge[0];
        int v=edge[1];
        adj[v].push_back(u); // v->u
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
        }
        }
        queue<int>q;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
while(!q.empty()){
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(int j=0;j<adj[node].size();j++){
       indegree[adj[node][j]]--;
       if(indegree[adj[node][j]]==0){
         q.push(adj[node][j]);
       }

    }
}
if(ans.size()==n){
    return true;
}

else{
    return false;
}
    }
};