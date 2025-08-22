class MyQueue {
public:
stack<int>input;
stack<int>output;
int peekElement=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekElement=x;
        }
      input.push(x);
    }
    
    int pop() {
        if(output.empty()){ //input ko output me dalo
  while(!input.empty()){
    output.push(input.top());
    input.pop();
  }
           
        }
        int val=output.top();
        output.pop();
        return val;
    }
    
    int peek() {
      if(output.empty()) return peekElement;

      else{
        return output.top();
      } 
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
        else return false;
    }
};