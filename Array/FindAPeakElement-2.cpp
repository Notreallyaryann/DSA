class Solution {
public:
int findMax(vector<vector<int>>& mat,int n,int m,int mid){
    int maxvalue=-1;
    int index=-1;

    for(int i=0;i<n;i++){
        if(mat[i][mid]>maxvalue){
            maxvalue=mat[i][mid];
            index=i;
        }
    }
    return index;
}

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();

       int l=0,r=m-1;
       while(l<=r){
        int mid=l+(r-l)/2;
       
       int maxRowIndex=findMax(mat,n,m,mid);
       int left=mid-1 >=0 ? mat[maxRowIndex][mid-1]:-1;   //-1 for out of bound
       int right=mid+1<m ? mat[maxRowIndex][mid+1]:-1;
if(mat[maxRowIndex][mid]>left && mat[maxRowIndex][mid]>right){
    return {maxRowIndex,mid};
}else if(mat[maxRowIndex][mid]<left){
    r=mid-1;
}else{
    l=mid+1;
}

       }
       return {-1,-1};
    }
};