class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(!root) return NULL;
        
        root->left= RemoveHalfNodes(root->left);
        root->right =RemoveHalfNodes(root->right);
        
        //half nodes remove
        if(!root->left && root->right) return root->right;
        if(!root->right&& root->left) return root->left;
        
        //good case
        return root;
        
    }
};