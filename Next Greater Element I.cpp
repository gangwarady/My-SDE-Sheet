class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int> mp;
        for(int i =0; i<nums2.size(); i++){
            mp[nums2[i]] = -1;
        }
        stack <int> st;
        for(int i = nums2.size()-1; i>=0;i--){
            while(!st.empty()){
                if(st.top()>nums2[i]){
                    mp[nums2[i]]= st.top();
                    break;
                }
                else{
                    st.pop();
                }
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i =0; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
