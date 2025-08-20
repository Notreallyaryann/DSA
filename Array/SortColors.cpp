class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=0,mid=0,right=n-1;
        //mid is current element we r checking
        while(mid<=right){
        if(nums[mid]==0){
            swap(nums[mid],nums[left]);
            mid++;
            left++;
        }else if(nums[mid]==1){
            mid++;
    
        }else{
            swap(nums[mid],nums[right]);
            right--;
        }
}
    }
};