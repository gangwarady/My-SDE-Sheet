class Solution {
public:
    int mySqrt(int x) {
        if(x==1||x==0){
            return x;
        }
        long long low = 1;
        long long high = x/2;
        long long ans;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long midSqr = mid * mid;
            
            if(midSqr == x) return mid;
            
            if(x < midSqr){
                high = mid-1;
            }else{
                low = mid+1;
                ans = mid;
            }
        }
        return ans;
    }
};
