class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
     int l=0,r=m-1;


     while(l<n && r>=0){
        if(matrix[l][r]==target){
            return true;
        }else if(matrix[l][r]<target){
            l++;
        }else{
            r--;
        }
     }
     return false;
    }
};


//m2 Binary Search

class Solution {
public:
int BS(vector<int>&rows,int target){
    int l=0;
    int r=rows.size()-1;

    while(l<=r){
int mid=l+(r-l)/2;

if(rows[mid]==target){
    return mid;
}else if(rows[mid]<target){
l=mid+1;
}else{
    r=mid-1;
}
    }
    return -1;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
for(int i=0;i<n;i++){
  int ind=  BS(matrix[i],target);
  if(ind!=-1){
    return true;
  }
}
return false;
    }
};