#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int ans =0;
    int xorr=0;
    unordered_map<int,int> mp;
    for(auto it: arr){
        xorr = xorr^it;
        if(xorr==x)ans++;
        if(mp.find(xorr^x)!=mp.end())
            ans+=mp[xorr^x];
        
        mp[xorr]++;
    }
    return ans;
}
