class Solution {
public:
bool Prime(int a) {
    if (a <= 1) return false;

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
      vector<int>result;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j || i+j==n-1){
              result.push_back(nums[i][j]);
                }
            }
        }
int maxPrime=0;
      for(int i=0;i<result.size();i++){
        if(Prime(result[i])) {
maxPrime=max(maxPrime,result[i]);
        }
      } 
      
      return maxPrime; 
    }
};