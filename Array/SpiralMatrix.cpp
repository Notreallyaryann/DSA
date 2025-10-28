class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dir=0;
        int top = 0, down = n - 1;
        int left = 0, right = m - 1;
    /*
     dir=0 left->right
     dir=1 top->down
     dir=2  right->left
     dir=3  down->top
    ->top
    ->down 
    */
  
    vector<int>ans;
while(top <= down && left <= right){
    if(dir==0){
        //row constant

        for(int i=left;i<=right;i++){
 ans.push_back(matrix[top][i]);
        }
        top++;
    }
    if(dir==1){
        //col constant
        for(int j=top;j<=down;j++){
            ans.push_back(matrix[j][right]);
        }
        right--;
    }

    if(dir==2){
        //row constant

        for(int i=right;i>=left;i--){
            ans.push_back(matrix[down][i]);
        }
     down--;
    }
    if(dir==3){
        //col constant
        for(int j=down;j>=top;j--){
            ans.push_back(matrix[j][left]);
        }
        left++;
    }
    dir++;

    if(dir==4) dir=0;
}

return ans;
    }
};