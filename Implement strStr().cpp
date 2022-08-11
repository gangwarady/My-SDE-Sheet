class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        int n1 = haystack.size(), n2 = needle.size();
        for(int i = 0 ;i<n1; i++){
            if(haystack[i]==needle[0]){
                int temp = i;
                j = 0;
                while(temp<n1 && j<n2 && haystack[temp]==needle[j]){
                    temp++; j++;
                }
                if(j==n2){
                    return i;
                }
            }
        }
        return -1;
    }
};
