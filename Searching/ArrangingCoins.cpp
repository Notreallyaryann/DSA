class Solution {
public:
    int arrangeCoins(int n) {
         long long low=1,high=n;
         long long ans=0;
       
 while(low<=high){
         long long mid=low+(high-low)/2;
        long long coins_needed=mid*(mid+1)/2;  //1,2,3.......k
        if(coins_needed==n) return mid;
        else if(coins_needed<n) { //can fill more
             ans = mid; //best valid so far
              low=mid+1;
        }else{
       high=mid-1;
        }
 }
        return ans;
    }
};