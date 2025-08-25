
class Solution {
public:
int height(TreeNode* root){
    if(!root) return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}
void Find(TreeNode* root, int start,TreeNode*&temp){
if(!root) return;
if(root->val==start) 
temp=root;
Find(root->left,start,temp);
Find(root->right,start,temp);
return;
}
int Burn(TreeNode* root, int start,int&timer){
    if(!root) return 0;
    if(root->val==start) return -1;
   int left= Burn(root->left,start,timer);
   int right= Burn(root->right,start,timer);

   //left burn
   if(left<0){
    timer=max(timer,abs(left)+right);
   return left-1;
   }
   //right burn
   if(right<0){
    timer=max(timer,abs(right)+left);
    return right-1;
   }
   //noburn
   return max(left,right)+1;
}
    int amountOfTime(TreeNode* root, int start) {
      int timer=0;
      Burn(root,start,timer);
      TreeNode*temp=NULL;
      Find(root,start,temp);
      height(root);
      int num=height(temp)-1;
      return max(timer,num);
    }
};