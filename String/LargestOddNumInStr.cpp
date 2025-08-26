class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            char c=num[i];

            if((c-'0')%2==1){ //odd 
            return num.substr(0,i+1);
            }
        }
        return "";
    }
};