class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n=prices.size();
        sort(prices.begin(),prices.end());
        int min_amount=0,max_amount=0;
        
        int i=0,j=n-1;
        
        while(i<=j){
            min_amount+=prices[i];
            i++;
            j=j-k; //free me mile
        }
        
        i=0,j=n-1;
        while(i<=j){
            max_amount+=prices[j];
            j--;
            i=i+k;//free me mila
        }
        
vector<int> ans;
   ans.push_back(min_amount);
    ans.push_back(max_amount);
   return ans;

    }
};