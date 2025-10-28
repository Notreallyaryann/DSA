class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();

  vector<int>minRow(n,INT_MAX);
  vector<int>maxCol(m,INT_MIN);

//row minimum
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
  minRow[i]=min(minRow[i],matrix[i][j]);

    }
  } 
//col max

for(int j=0;j<m;j++){
    for(int i=0;i<n;i++){
        maxCol[j]=max(maxCol[j],matrix[i][j]);
    }
}
vector<int>ans;

//find common element
for(int i=0;i<minRow.size();i++){
    for(int j=0;j<maxCol.size();j++){
        if(minRow[i]==maxCol[j]) ans.push_back(minRow[i]);
    }
}

return ans;
    }
};