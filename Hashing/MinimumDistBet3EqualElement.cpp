class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int min_dist=INT_MAX;
        map<int,vector<int>>indices; //number->[index]
        //store all indices
      for(int i=0;i<n;i++){
          indices[nums[i]].push_back(i);
      }

for(auto it=indices.begin();it!=indices.end();it++ ){
    vector<int>idx=it->second;
    if(idx.size()<3) continue;

    for(int i=0;i+2<idx.size();i++){
        int i1=idx[i];
        int i2=idx[i+1];
        int i3=idx[i+2];
int dist=abs(i2-i1)+abs(i3-i2)+abs(i1-i3);
        min_dist=min(min_dist,dist);
    }
}
        if(min_dist==INT_MAX ) return -1;

        return min_dist;
        
    }
};