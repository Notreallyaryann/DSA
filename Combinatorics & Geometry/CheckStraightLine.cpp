class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n<=2) return true;
         bool isline=1;
        for(int i=0;i<n-2;i++){
        int x1=coordinates[i][0] ,y1=coordinates[i][1];
        int x2=coordinates[i+1][0]  ,y2=coordinates[i+1][1];
        int x3=coordinates[i+2][0] , y3=coordinates[i+2][1];
 

 //m1=m2 (if they are collinear)
        if((y2-y1)*(x3-x1)!=(y3-y1)*(x2-x1)){
        isline=0;
               break;
            }
    
    }
        return isline;
    }
};