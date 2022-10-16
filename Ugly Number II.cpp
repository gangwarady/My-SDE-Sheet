class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>num(n);
        num[0]=1;
        int t2 = 0, t3=0, t5=0;
        for(int i =1; i<n; i++){
            num[i]= min({num[t2]*2, num[t3]*3, num[t5]*5});
            if(num[i]==num[t2]*2)t2++;
            if(num[i]==num[t3]*3)t3++;
            if(num[i]==num[t5]*5)t5++;
        }
        return num[n-1];
    }
};
