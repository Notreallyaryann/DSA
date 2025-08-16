class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int n=nums.size();
        vector<int>smaller;
        vector<int>larger;
        vector<int>equal;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                smaller.push_back(nums[i]);
            }else if (nums[i]==pivot){
                equal.push_back(nums[i]);
            }else{
                larger.push_back(nums[i]);
            }
        }
nums.clear();

nums.insert(nums.end(),smaller.begin(),smaller.end());
nums.insert(nums.end(),equal.begin(),equal.end());
nums.insert(nums.end(),larger.begin(),larger.end());

return nums;
    }
};