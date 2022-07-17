class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 0;
        if(digits[digits.size()-1]==9){
            ans.push_back(0);
            carry = 1;
        }
        else{
            ans.push_back(digits[digits.size()-1]+1);
        }
        for(int i = digits.size()-2; i>=0; i--){
            digits[i]+= carry;
            carry = digits[i]/10;
            digits[i]%= 10; 
            ans.push_back(digits[i]);
        }
        if(carry){
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
