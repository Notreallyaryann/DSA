class Solution {
public:
void backtracking(vector<string>&result,string curr,int open,int close,int n){
    //agar curr ka size n ke equal ho to curr ko result me push krdo

    if(curr.size()==2*n){
        result.push_back(curr);
        return;
    }
 if(open<n){
 backtracking(result,curr +"(",open+1,close,n); 
}if (close<open){
     backtracking(result,curr +")",open,close+1,n);
}
}
    vector<string> generateParenthesis(int n) {
        vector<string>result;
      backtracking(result,"",0,0,n);  
      return result;
    }
}; 