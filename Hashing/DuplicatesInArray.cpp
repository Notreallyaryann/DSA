class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int>seen;
        set<int>duplicate;

        for(auto &num :nums){
            if(seen.find(num)!=seen.end()){
                duplicate.insert(num);
            }else{
                seen.insert(num);
            }
        }
vector<int>ans(duplicate.begin(),duplicate.end());
return ans;
    }
};