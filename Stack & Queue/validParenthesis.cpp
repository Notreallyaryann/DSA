class Solution {
public:
    bool isValid(string s) {
        stack<int>st;

for(char &ch:s){

    if(st.empty() || ch=='(' || ch=='{' || ch=='['){
        st.push(ch);
        continue;
    }
    if(ch==')'){
        if(!st.empty() && st.top()=='('){
            st.pop();
        }else return false;
    }else if(ch=='}'){
        if(!st.empty() && st.top()=='{'){
            st.pop();
        }else return false;
    }else if(ch==']'){
        if(!st.empty() && st.top()=='['){
            st.pop();
        }else return false;
        
    }else {
        return false;
        } 


}
return st.empty();
    }
};