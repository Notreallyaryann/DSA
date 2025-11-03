class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    
    void Inorder(Node*root,vector<int>&arr){
        if(!root) return;
        
        Inorder(root->left,arr);
        arr.push_back(root->data);
        Inorder(root->right,arr);
    }
    
    
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int>arr1;
        vector<int>arr2;
        Inorder(r1,arr1);
        Inorder(r2,arr2);
        
       int n=arr1.size();
       int m=arr2.size();
       vector<int>ans;
       
      int i=0,j=0;
      
      while(i<n && j<m){
          if(arr1[i]==arr2[j]){
              if(ans.empty() || ans.back()!=arr1[i]){ //skip duplicates
                  ans.push_back(arr1[i]);
                
              }
                  i++;
                  j++;
          }
              else if(arr1[i]<arr2[j]){
                  i++;
              }else{
                  j++;
              }
          }
      
        
        return ans;
        
    }
};