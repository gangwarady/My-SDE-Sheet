class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int msf = 0;
        while(start<end){
            msf= max(msf, min(height[start], height[end])*(end-start));
            if(height[start]<=height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return msf;
    }
};
