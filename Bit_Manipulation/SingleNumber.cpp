class Solution {
public:
//a^a=0   , 2^2^1 =1
    int singleNumber(vector<int>& nums) {
      int n=nums.size();
      int result=0;

      for(int i=0;i<n;i++){
        result=result^nums[i];
      }
return result;
    }
};