class Solution {
public:
    
    
    void f(int val,int n,int k,vector<int>&ans,int index){
       if(index==n){
           ans.push_back(val);
           return;
       }
    if(index==0){
        for(int i = 1; i<=9; i++){
            f(val*10 + i ,n,k,ans,index+1);
        }
    }
        else{
            int rem = val%10;
             for(int i = 0; i<=9; i++){
                if(abs(rem-i)==k){
                    f(val*10 + i,n,k,ans,index+1);
                }
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        f(0, n,k, ans, 0);
        return ans;
    }
};
