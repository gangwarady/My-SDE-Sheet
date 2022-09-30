int Solution::cntBits(vector<int> &A) {
    long long ans = 0;
    for(int i =0; i<32;i++){
        long long count =0;
        for(int j=0;j<A.size();j++){
            if(A[j]&1) count++;
            A[j]>>=1;
        }
        ans += count *(A.size()-count)*2;
    }
    return ans%1000000007;
}
