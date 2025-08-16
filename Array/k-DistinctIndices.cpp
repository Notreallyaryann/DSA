class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
   vector<bool>mark(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]==key){
                for(int j=0;j<n;j++){
                    if(abs(j-i)<=k){
                        mark[j]=true;
                    }
                }
            }
        }
        vector<int>result;
for(int i=0;i<n;i++){
    if(mark[i]) result.push_back(i);
}
return result;
    }
};