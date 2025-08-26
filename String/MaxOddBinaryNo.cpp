class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        string result=string(n,'0');
        int i=0;
        for(char &ch :s){
            if(ch=='1'){
                if(result[n-1]=='1'){ //for odd no lsb me 1 hona jaruri hai
                    result[i]='1';  //ab starting se dalo
                    i++;
                }else{
                    result[n-1]='1';
                }
            }
        }
        return result;
    }
};