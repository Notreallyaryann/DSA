class Solution {
public:
void solve(int start,vector<int>& candidates, int target, vector<int>&temp,vector<vector<int>>&ans){
    if(target<0) return;
if(target==0){
    ans.push_back(temp);
    return;
}

for(int i=start;i<candidates.size();i++){
//If i > start and it equals the previous element → skip it, because we already tried /this number at this level
    if(i>start && candidates[i]==candidates[i-1]) continue;
temp.push_back(candidates[i]);
solve(i+1,candidates,target-candidates[i],temp,ans);
temp.pop_back(); //backtrack

}
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
       solve(0,candidates,target,temp,ans); 
       return ans;
    }
};