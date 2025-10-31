class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {


        // code here
        int n=q.size();
        int remaining=n-k;
        stack<int>s;
        
        while(k--){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
        q.push(s.top());
        s.pop();
        }
        while(remaining--){
        q.push(q.front());
        q.pop();
        }
        return q;
    }
};