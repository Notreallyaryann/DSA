class Solution {
  public:
  void inorder(Node *root, vector<int>&arr){
      if(!root) return;
      inorder(root->left,arr);
      arr.push_back(root->data);
      inorder(root->right,arr);
  }
    int kthLargest(Node *root, int k) {
        // Your code here
        vector<int>arr;
   
        inorder(root,arr);
             int n=arr.size();
        return arr[n-k];
    
    }
};