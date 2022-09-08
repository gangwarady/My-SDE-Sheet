class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
         //cout<<m<<" "<<n;
        if(n>m) return findMedianSortedArrays(nums2, nums1);
        int low =0, high = n;
        int mdn = (m+n+1)/2;
        while(low<=high){
            int cut1= (low+high)/2;
            int cut2= mdn - cut1;
            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int l2 =(cut2==0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1==n)?INT_MAX:nums1[cut1];
            int r2 = (cut2==m)?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1){
                if((m+n)%2){
                   
                    return max(l1,l2);
                }
                else{
                    //cout<<max(l1,l2)<<" "<<min(r1,r2);
                    return (float(max(l1,l2)+min(r1,r2))/2);
                }
            }
            else if(l1>r2)
                high = cut1-1;
            else
                low = cut1+1;
                
        }
        return 0;
    }
};
