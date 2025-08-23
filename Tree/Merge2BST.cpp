class Solution {
  public:
  void inorder(Node *root , vector<int>&temp){
      if(!root) return;
      
      inorder(root->left,temp);
      temp.push_back(root->data);
      inorder(root->right,temp);
      
  }
   
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>arr1;
        vector<int>arr2;
        vector<int>temp;
        vector<int>ans;
     inorder(root1,arr1);
     inorder(root2,arr2);
     int n=arr1.size();
     int m=arr2.size();
     int i=0,j=0;
     
     while(i<n && j<m){
         if(arr1[i]<arr2[j]){
             ans.push_back(arr1[i]);
             i++;
         }else{
             ans.push_back(arr2[j]);
             j++;
         }
     }
     while(i<n){
            ans.push_back(arr1[i]);
             i++;
     }
     while(j<m){
         ans.push_back(arr2[j]);
             j++;
     }
     return ans;
    }
};