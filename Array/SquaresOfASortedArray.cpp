class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            ans.push_back(nums[i]*nums[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//m2


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1,k=n-1;
        vector<int>result(n);


        while(k>=0){
            int a=nums[i]*nums[i];
            int b=nums[j]*nums[j];


            if(a>b){
                result[k]=a;
                i++;
                k--;
            }else{
                result[k]=b;
                j--;
                k--;
            }
        }
        return result;
    }
};