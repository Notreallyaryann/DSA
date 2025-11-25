class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
//skip spaces
        while(i<n && s[i]==' '){
            i++;
        }

        //check sign
int sign =1;
if (i < n && (s[i] == '-' || s[i] == '+')){
    if(s[i]=='-'){
    sign =-1;
    }
       i++;
}
//now Read Digits
long long num=0;
bool hasDigit=false;
while(i<n && isdigit(s[i])){
    hasDigit=true;
    int digit=s[i]-'0';

    num=num*10+digit;
if(sign==1 && num>INT_MAX) return INT_MAX;
if (sign == -1 && -num < INT_MIN) return INT_MIN;

    i++;
}
if(!hasDigit) return 0;
return int(num*sign);
    }
};