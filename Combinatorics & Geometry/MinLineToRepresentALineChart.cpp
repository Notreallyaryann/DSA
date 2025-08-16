class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n=stockPrices.size();
        if(n<=1) return 0;
        if(n==2) return 1;
         int line=1;
  
sort(stockPrices.begin(),stockPrices.end());

        for(int i=0;i<n-2;i++){
long long x1=stockPrices[i][0],  y1=stockPrices[i][1];
long long x2=stockPrices[i+1][0], y2=stockPrices[i+1][1];
long long x3=stockPrices[i+2][0], y3=stockPrices[i+2][1];

if((y2-y1)*(x3-x1)!=(y3-y1)*(x2-x1)){
    line++;     //If not collinear → we must start a new line
}

        }
        return line;
    }
};