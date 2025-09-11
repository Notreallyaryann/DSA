class Solution {
  public:
    void mirror(Node* node) {
        // code here
        if(!node) return;
        Node*temp=node->right;
        
        node->right=node->left;
        node->left=temp;
        
        mirror(node->left);
        mirror(node->right);
        
    }
};