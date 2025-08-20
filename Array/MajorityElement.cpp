class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
     
    int majority_element=nums[0];
       int vote=1;
        for(int i=1;i<n;i++){
            if(nums[i]==majority_element){
                vote++;
            }else{
                vote--;;
            }
            if(vote==0){
                majority_element=nums[i];
                vote=1;
            }
        }

return majority_element;
    }
};