class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
vector<int>result;
        for(auto &t:nums){
        m[t]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
          int count=min(2,it->second)  ;

          for(int i=0;i<count;i++){
            result.push_back(it->first);
          }
        }
        nums=result;
        return nums.size();
    }
};