class Solution {
public:
void solve(int start,vector<int>& nums,vector<int>&temp, vector<vector<int>>&ans){
ans.push_back(temp); //push empty subset

for(int i=start;i<nums.size();i++ ){
//skip duplicate
//first per u can pick but at same level same element then skip
    if(i>start && nums[i]==nums[i-1]) continue;
 
 temp.push_back(nums[i]);
    solve(i+1,nums,temp,ans);
temp.pop_back();
}


}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,nums,temp,ans);
        return ans;
    }
};