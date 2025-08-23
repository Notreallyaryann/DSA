class Solution {
public:
TreeNode*BST(vector<int>& preorder,int lowerbound,int upperbound,int &index){
    if(index>=preorder.size() || preorder[index]<lowerbound || preorder[index]>upperbound) return NULL;

    TreeNode* root=new TreeNode(preorder[index++]);
    //left ka range lowerr se root tak
root->left=BST(preorder,lowerbound,root->val,index);
root->right=BST(preorder,root->val,upperbound,index);
return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
     return  BST(preorder,INT_MIN,INT_MAX,index) ;
    }
};