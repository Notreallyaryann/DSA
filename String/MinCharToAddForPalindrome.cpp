class Solution {
  public:
  void lpslength(string &s,vector<int>&lps){
    
      int pre=0,suf=1;
     
      while(suf<s.size()){
          if(s[pre]==s[suf]){
              lps[suf]=pre+1;
              pre++;
              suf++;
          }else{
              if(pre==0){
                  lps[suf]=0;
                  suf++;
              }else{
                  pre=lps[pre-1];
              }
          }
          
      }
  }
    int minChar(string &s) {
        // code here
        string t=s;
        reverse(t.begin(),t.end());
        s+='$';
        s+=t;
         vector<int>lps(s.size(),0);
        lpslength(s,lps);
        
        return t.size()-lps[s.size()-1];
    }
};