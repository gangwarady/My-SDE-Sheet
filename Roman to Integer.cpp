class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        char prev = NULL;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='I'){
                ans +=1;
            }
            else if(s[i]=='V'){
                if(prev=='I'){
                    ans+=3;
                }
                else{
                    ans+=5;
                }
            }
            else if(s[i]=='X'){
                if(prev=='I'){
                    ans+=8;
                }
                else{
                    ans+=10;
                }
            }
            else if(s[i]=='L'){
                if(prev=='X'){
                    ans+=30;
                }
                else{
                    ans+=50;
                }
            }
            else if(s[i]=='C'){
                if(prev=='X'){
                    ans+=80;
                }
                else{
                    ans+=100;
                }
            }
            else if(s[i]=='D'){
                if(prev=='C'){
                    ans+=300;
                }
                else{
                    ans+=500;
                }
            }
            else if(s[i]=='M'){
                if(prev=='C'){
                    ans+=800;
                }
                else{
                    ans+=1000;
                }
            }
            prev = s[i];
        }
        return ans;
    }
};
