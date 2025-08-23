Node*BST(int post[],int lowerbound,int upperbound,int &index){
    if(index<0 || post[index]<lowerbound || post[index]>upperbound) return NULL;
    
    Node*root=new Node(post[index--]);
// build right subtree first (because in postorder, right comes before left when traversing backwards)
    root->right=BST(post,root->data,upperbound,index);
    root->left=BST(post,lowerbound,root->data,index);
    
    return root;
}
Node *constructTree(int post[], int size) {
    // code here
    int index=size-1;
   return BST(post,INT_MIN,INT_MAX,index);
}