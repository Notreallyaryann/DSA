class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int peakIndex=0;

        for(int i=0;i<n;i++){
            if(nums[i]>nums[peakIndex]){
                peakIndex=i;
            }
        }
        return peakIndex;
    }
};


//m-2
