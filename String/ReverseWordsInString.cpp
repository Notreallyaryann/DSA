class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result="";
        string token="";

        while(ss>>token){ //The >> operator extracts words separated by whitespace
            result=token+" "+result;
        }
        int n=result.size();
        return result.substr(0,n-1);
    }
};



//m2

class Solution {
public:
    string reverseWords(string s) {
        //reverse whole string

        reverse(s.begin(),s.end());

        int i=0;
        int l=0,r=0; //reverse krege 
        int n=s.length();

        while(i<n){
            while(i<n && s[i]!=' ') {//i ko agar char dikha to r ko dege and i++ and r++ kr dege
                 s[r]=s[i];
                 i++;
                 r++;
            }
            if(l<r) {//reverse jab i ko space mile
            reverse(s.begin()+l ,s.begin()+r);
            s[r]=' '  ; //ek space le lega
            r++;

            l=r;
            }
            i++;
        }
        //while loop khatam i bahar aagya
        return s.substr(0,r-1);
    }
};