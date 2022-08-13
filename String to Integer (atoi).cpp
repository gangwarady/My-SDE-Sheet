class Solution {
public:
    int myAtoi(string s) {
     int i = 0;
        int sign = 1;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(s[i]=='-'||s[i]=='+'){
            if(s[i]=='-')
                sign = -1;
            i++;
        }
        long long ans = 0;
        while(i<s.size()){
            if(!isdigit(s[i]))
                break;
            ans = ans*10 + (s[i]-'0');
            if(ans>=pow(2,31)){
                if(sign == -1)
                    return -1*pow(2,31);
                else
                    return pow(2,31) - 1;
            }
            i++;
        }
        return (int)ans*sign;
    }
};
