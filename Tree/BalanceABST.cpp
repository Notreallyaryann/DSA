class Solution {
public:
void inorder(TreeNode* root,vector<int>&temp){
if(!root) return;

inorder(root->left,temp);
temp.push_back(root->val);
inorder(root->right,temp);
}


TreeNode* construct(int l,int r ,vector<int>temp){
    if(l>r) return NULL;
    int mid=l+(r-l)/2;
TreeNode* root=new TreeNode(temp[mid]);
root->left=construct(l,mid-1,temp);
root->right=construct(mid+1,r,temp);
return root;

}
 TreeNode* balanceBST(TreeNode* root) {
 vector<int>temp;
inorder(root,temp);
int l=0,r=temp.size()-1;
return construct(l,r,temp);
    }
};