class Solution {
public:
    int guessNumber(int n) {
        int low=1,high=n;
        int pick;
        while(low<=high){
            int mid=low+(high-low)/2;
        int res=guess(mid);
            if(res==0) return mid;
            else if(res==1) low=mid+1;
            else  high=mid-1;
        }
        return -1;
    }
};