class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
     int maxcount=INT_MIN;
     int count=0;
        for(char &ch : s ){
           if(st.empty() || ch=='('){
            st.push(ch);
            count++;
            continue;
           }else if(ch==')'){
              maxcount=count;
            st.pop();
          
            count--;
           }
        }
        return maxcount;
    }
};