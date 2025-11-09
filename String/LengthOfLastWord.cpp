class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        int length=0;

        while(n>=0 && s[n]==' '){
            n--;
        }
        while(n>=0 && s[n]!=' '){
            length++;
            n--;
        }
        return length;
    }
};