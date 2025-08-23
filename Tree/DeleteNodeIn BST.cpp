class Solution {
public:
TreeNode* minValue(TreeNode* root){
TreeNode*curr=root;
while(curr&&curr->left){
    curr=curr->left;
}
return curr;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root) return NULL;

if(root->val==key){
//0 child

if(!root->left && !root->right){
    delete(root);
    return NULL;
}

//1 left child
else if(!root->right && root->left){
    TreeNode*temp=root->left;
    delete(root);
    return temp;
}
//1 right child 
else if(root->right && !root->left){
     TreeNode*temp=root->right;
    delete(root);
    return temp;
}
//2 child
//minimum value in right subtree or maximum value in left subtree
else {
   TreeNode*temp=minValue(root->right) ;
    root->val=temp->val;
    root->right = deleteNode(root->right, temp->val);
}

}else if(root->val<key){
 root->right=   deleteNode( root->right, key) ;
}
else{
root->left= deleteNode( root->left,  key);
}
return root;

    }
};