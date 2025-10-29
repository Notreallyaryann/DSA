class Solution {
public:
int searchFirst(vector<int>& nums, int target){
    int n=nums.size();
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans= mid; //possible 
            high=mid-1; //left search space me search kro
            
        }else if(nums[mid]<target) low=mid+1;
        else  high=mid-1;
    }

    return ans;
}


int searchLast(vector<int>& nums, int target){
     int n=nums.size();
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans= mid; //possible 
            low=mid+1; //right search space me search kro
            
        }else if(nums[mid]<target) low=mid+1;
        else  high=mid-1;
    }

    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
     int first=   searchFirst(nums,target);
       int last= searchLast(nums,target);

       return {first,last};
    }
};