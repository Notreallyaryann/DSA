class Solution {
public:
void Inorder(TreeNode*root,vector<int>&arr){
if(!root) return ;
Inorder(root->left,arr);
arr.push_back(root->val);
Inorder(root->right,arr);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      vector<int>arr1;
      vector<int>arr2;
    Inorder(root1,arr1);
    Inorder(root2,arr2);

    int n=arr1.size();
    int m=arr2.size();

    int i=0,j=0;
vector<int>ans;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }else if(arr1[i]>arr2[j]){
           ans.push_back(arr2[j]);
           j++;
        }else{
            ans.push_back(arr1[i]);
            ans.push_back(arr2[j]);
            i++;
            j++;
        }
    }
while(i<n) {
ans.push_back(arr1[i]);
i++;
} 
while(j<m) {
ans.push_back(arr2[j]);
    j++;
}
    return ans;
    }
};