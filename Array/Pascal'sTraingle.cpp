class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle;
        

        for(int i=0;i<numRows;i++){
            vector<int>row(i+1,1);
            //j=0 && j=i is always 1 no need to change
            for(int j=1;j<i;j++){
                row[j]=triangle[i-1][j]+triangle[i-1][j-1];
            }
            triangle.push_back(row);
        }
return triangle;
    }
};