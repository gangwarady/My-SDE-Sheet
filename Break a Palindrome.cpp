class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1 ||palindrome.size()==0 ){
            return "";
        }
        int flag = 0;
            for(int j =0; j<palindrome.size()/2; j++){
                if(palindrome[j]!='a'){
                    palindrome[j]='a';
                    flag = 1;
                    break;
                }
            }
            if(flag==0) palindrome[palindrome.size()-1]='b';
        
        return palindrome;
    }
};
