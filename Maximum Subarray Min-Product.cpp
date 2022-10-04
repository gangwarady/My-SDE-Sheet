class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> prefix(n);
        prefix[0] = nums[0];
        for(int i =1; i<n; i++){
            prefix[i]= prefix[i-1]+nums[i];
        }
        stack<pair<int,int>> st1,st2;
        int left[n];
        int right[n];
        for(int i =0; i<n; i++){
            int count = 1;
             while (!st1.empty() && (st1.top().first) > nums[i]) {
                count += st1.top().second;
                st1.pop();
            }
            st1.push({ nums[i], count });
            left[i] = count;
        }
         for(int i =n-1; i>=0; i--){
            int count = 1;
            while (!st2.empty() && (st2.top().first) >= nums[i]) {
                count += st2.top().second;
                st2.pop();
            }

            st2.push({ nums[i], count });
            right[i] = count;
        }
        long long int maxi = 0;
        for(int i=0;i<n;i++){
            int a = i-left[i]+1;
            int b = i+right[i]-1;
            long long int subArraySum;
            if(a>0)
                subArraySum = prefix[b]-prefix[a-1];
            else
                subArraySum = prefix[b];
            maxi = max(maxi, subArraySum*nums[i]);
        }
        return maxi%1000000007;
    }
};
