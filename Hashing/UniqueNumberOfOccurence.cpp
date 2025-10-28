class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
    mp[arr[i]]++;
}

set<int>seen;

 for(auto it=mp.begin(); it!=mp.end();it++){
  if(seen.find(it->second)!=seen.end()) return false;
  seen.insert(it->second);
 }

 return true;
    }
};