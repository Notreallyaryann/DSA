class Solution {
public:
int currNum=0;
int currFreq=0;
int maxFreq=0;
vector<int>result;

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
if(root->val==currNum){
    currFreq++;
}else{
    currNum=root->val;
    currFreq=1;
}

if(currFreq>maxFreq){
    result={};
    maxFreq=currFreq;
}
if(currFreq==maxFreq){
    result.push_back(root->val);
}
    inorder(root->right);
}
    vector<int> findMode(TreeNode* root) {
   inorder(root);
    return result;
    }
};