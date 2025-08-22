//m1

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





//m2

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum_s=0;
        int sum_t=0;

        for(char &ch:s){
            sum_s+=ch;
        }
for(char &ch:t){
            sum_t+=ch;
        }
//sum_t>sum_s

return (char)(sum_t-sum_s);
    }
};





//m3 ->xor

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;

        for(char &ch:s) res=res^ch;
        for(char &ch:t) res=res^ch;

        return (char)res;
    }
};