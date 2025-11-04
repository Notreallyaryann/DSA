class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int swaps=0;
        vector<int>Sortedarr(arr.begin(),arr.end());
        sort(Sortedarr.begin(),Sortedarr.end());
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==Sortedarr[i]) continue; //no need to swap
            
    int curridx=mp[Sortedarr[i]]; //jha hona chhaiye 
    mp[arr[i]]=curridx; //update map
    swap(arr[i],arr[curridx]);//swap
    swaps++;
        }
        return swaps;
    }
};