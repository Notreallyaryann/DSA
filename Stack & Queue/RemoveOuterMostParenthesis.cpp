class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string result;
        for(char ch:s){
            if(ch=='('){
                if(!st.empty()){
                    result+=ch;
                }
                st.push(ch);
            }else if(ch==')'){
                st.pop();
                if(!st.empty()) result+=ch;
            }
            
        }
        return result;
    }
};