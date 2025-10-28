class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int count1=0,count2=0;
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());
       
       for(int i=0;i<n;i++){
        if(s2.contains(nums1[i])){
             count1++;
        }
       }
    for(int j=0;j<m;j++){
        if(s1.contains(nums2[j])){
            count2++;
        }
    }
return {count1,count2};

    }
};