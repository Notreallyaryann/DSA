class Solution {
public:
    bool checkRecord(string s) {
       int countA=0;
       int countConsecultiveLate=0;


       for(char c : s) {
        if(c=='A'){
            countA++;
            if(countA>1){
                return false;
            }
            countConsecultiveLate=0;
        }else if(c=='L'){
            countConsecultiveLate++;
            if(countConsecultiveLate>2){
                return false;
            }
        }else{
            countConsecultiveLate=0;
        }
       }
       return true;
    }
};