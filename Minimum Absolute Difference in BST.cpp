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
    void solve(TreeNode* root, vector<int> &v){
        if(root==NULL)
            return;
        v.push_back(root->val);
        solve(root->left, v);
        solve(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<int> v;
        solve(root, v);
        sort(v.begin(), v.end());
        int mini = INT_MAX;
        for(int i = 0; i<v.size()-1; i++){
            mini = min(mini, v[i+1]-v[i]);
        }
        return mini;
    }
};
