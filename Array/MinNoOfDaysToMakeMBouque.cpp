class Solution {
public:
bool possible(vector<int>& bloomDay,int mid,int m, int k){
    int bouqcount=0;
    int consecutivecount=0;
 for(int i=0;i<bloomDay.size();i++){
    if(bloomDay[i]<=mid){ //matlab flower bloom kr chuka hoga
        consecutivecount++;
    }else{
        consecutivecount=0;

    }
    if(consecutivecount==k){ //ek bouque bna sakte
        bouqcount++;
        consecutivecount=0;
    }
 }
return  bouqcount>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
      int n=bloomDay.size();
      int l=1;
      int r=*max_element(bloomDay.begin(),bloomDay.end());
 if ((long long)m * k > n) return -1;  // edge case: not enough flowers
      while(l<r){
        int mid=l+(r-l)/2;

    if(possible(bloomDay,mid,m,k)){
        r=mid;
    }else{
        l=mid+1;
    }
      } 
      return l; 
    }

};