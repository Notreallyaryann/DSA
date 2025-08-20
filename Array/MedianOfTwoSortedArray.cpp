class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
          return  findMedianSortedArrays(nums2,nums1); //swap hogye
        }
        int m=nums1.size();
        int n=nums2.size();



        if(m == 0){   // handle empty nums1
    if(n % 2 == 1) return nums2[n/2];
    return (nums2[n/2 - 1] + nums2[n/2]) / 2.0;
}

        int l=0;
        int r=m;

        while(l<=r){
         int px=l+(r-l)/2;   //kitne elements num1 se lege
         int py=(m+n+1)/2-px;  //from nums2

         //left half 
int x1=(px==0)?INT_MIN :nums1[px-1];  //(-1 ->0 based)nums1 se kitne element liye uska
int x2=(py==0)?INT_MIN:nums2[py-1];

//right half wala empty kab hoga jab left wale me sare le liye
int x3=(px==m)?INT_MAX:nums1[px];
int x4=(py==n)?INT_MAX:nums2[py];

if(x1<=x4 && x2<=x3){
    if((m+n)%2==1){ //odd
  return max(x1,x2);
    }
 //2,4,8|| 9,10,12
    return (max(x1,x2) + min(x3,x4))/ 2.0;
}
if(x1>x4 ){
    r=px-1;
}else{
    l=px+1;
}
        }
        return -1;
    }
};