class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       int n=nums.size();

       set<int>s(nums.begin(),nums.end());

       int m=s.size();

       if(n!=m) return true;
       return false; 
    }
};