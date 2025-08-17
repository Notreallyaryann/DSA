class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //remove leaf node jiska degree 1 ho
         if (n == 1) return {0};
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<int>ans;
        for(auto &edge :edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
     indegree[u]++; //dono ka degree inc kro 
     indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
while(!q.empty()){
     ans.clear(); //ans.clear() ensures we only keep the current BFS layer — the last one is the answer
            int size = q.size();
            
            for (int k = 0; k < size; k++) { // process one BFS level
                int node = q.front();
                q.pop();
                ans.push_back(node);
            
    for(int i=0;i<adj[node].size();i++){
        indegree[adj[node][i]]--;
        if( indegree[adj[node][i]]==1){
            q.push(adj[node][i]);
        }
    }
}
}
return ans;
    }
};