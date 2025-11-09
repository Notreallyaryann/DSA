class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int>m;
int n=nums.size();
        for(int i=0;i<n;i++){
           m[nums[i]]++;
        }
        int sum=0;

        for(auto &p :m){
            if(p.second==1){
                sum+=p.first;
            }
        }
        return sum;
    }
};