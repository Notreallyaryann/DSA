class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //While the current string does not start with the prefix, shorten the prefix
if(strs.empty()) return "";
string prefix=strs[0];


for(int i=1;i<strs.size();i++){
    //remove characters from the end until it matches
   while(strs[i].find(prefix)!=0){ //tab tak shorten kro
prefix=prefix.substr(0,prefix.size()-1);

if(prefix.empty()) return "";


   }
}
return prefix;
    }
};