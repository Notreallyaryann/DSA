class Solution {
public:
    int minInsertions(string s){
        int insert=0;
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(i+1<n && s[i+1]==')'){
                    i++;
                }else{
                    insert++;
                }
                if(!st.empty()){
                    st.pop();
                }else{
                    insert++;
                }
            }
        }
        return insert+st.size()*2;
    }
};