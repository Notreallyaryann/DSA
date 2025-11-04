class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
     
     vector<double>ans;
        if(!root) return ans;
    
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            int levelcount=n;
             long long sum=0;
            while(n--){
            TreeNode*temp=q.front();
            q.pop();

            sum+=temp->val;

          if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
          
            }
           double avg = (double)sum / (double)levelcount;

            ans.push_back(avg);
        }
        return ans;
    }
};