class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int n=nums.size();
      
vector<int>missing;
        int min_element=INT_MAX;
        int max_element=INT_MIN;

        for(int i=0;i<n;i++){
            min_element=min(min_element,nums[i]);
            max_element=max(max_element,nums[i]);
        }

for(int range=min_element;range<=max_element;range++){
    if(s.find(range)==s.end()){
        missing.push_back(range);
    }
}
return missing;
    }
};