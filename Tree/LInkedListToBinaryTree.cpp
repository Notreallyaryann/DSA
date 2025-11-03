class Solution {
  public:
    Node *linkedListToBinaryTree(NodeLL *head) {
        // code here
         NodeLL*temp=head;
        vector<int>arr;
        
        while(temp){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        int n=arr.size();
        
  Node*root=new Node(arr[0]);
  
 queue<Node*>q;
 q.push(root);
 
 int i=1;
 while(i<n && !q.empty()){
    Node*temp=q.front();
    q.pop();
    
    if(i<n ){
        temp->left=new Node(arr[i]);
        q.push(temp->left);
    }
    i++;
    
    if(i<n ){
        temp->right=new Node(arr[i]);
        q.push(temp->right);
    }
    i++;
 }
      
        
return root;
    }
};