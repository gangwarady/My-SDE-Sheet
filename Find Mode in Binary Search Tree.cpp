/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, unordered_map<int,int> &mp){
        if(root==NULL)
            return;
        mp[root->val]++;
        solve(root->left, mp);
        solve(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        unordered_map<int,int> mp;
        solve(root, mp);
        int maxi = -1;
        for(auto &it: mp){
            if(it.second>maxi){
                maxi = it.second;
            }
        }
        for(auto &it: mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
