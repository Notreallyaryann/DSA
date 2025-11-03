class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int i=0,j=n-1;
        int ans=0,count=0;
        while(i<=j){
        if(count<2){
            ans+=cost[j];
            count++;
            j--;
        }
        else if(count==2){
            j--;
            count=0;//reset
        }
        }
        return ans;
    }
};