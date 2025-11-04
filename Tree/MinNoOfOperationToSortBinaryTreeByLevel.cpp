class Solution {
public:

int countMinSwapsToSort(vector<int>&vec){
int swaps=0;
vector<int>sortedVec(vec.begin(),vec.end());
sort(sortedVec.begin(),sortedVec.end());
unordered_map<int,int>mp; 

for(int i=0;i<vec.size();i++){
    mp[vec[i]]=i;
}

for(int i=0;i<vec.size();i++){
    if(vec[i]==sortedVec[i]) continue; //no swap needed

    int currIdx=mp[sortedVec[i]]; //jo hona chahiye index
    mp[vec[i]]=currIdx; //map ko update kr do
    swap(vec[currIdx],vec[i]);
    swaps++;
}
return swaps;
}

    int minimumOperations(TreeNode* root) {
      
        int result=0;
      queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            int n=q.size();
            vector<int>arr;
            while(n--){
            TreeNode*temp=q.front();
            q.pop();
            arr.push_back(temp->val);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            }
            result+=countMinSwapsToSort( arr);
        }
return result;
    }
};