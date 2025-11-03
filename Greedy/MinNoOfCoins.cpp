class Solution {
  public:
    int findMin(int n) {
        // code here
        int currency[]={10,5,2,1};
        int coins=0,i=0,ans=0;
      while(n){
            coins=n/currency[i];
            ans+=coins;
            n=n%currency[i];
            i++;
            
      }
      return ans;
    }
};