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
    void solve(TreeNode* root, int curr, int targetSum, vector<vector<int>> &ans, vector<int> &row){
        row.push_back(root->val);
        if(curr==targetSum && root->left==NULL && root->right==NULL){
            ans.push_back(row);
            return;
        }
        if(root->left){
            solve(root->left, curr + root->left->val, targetSum, ans, row);
            row.pop_back();
        }
        if(root->right){
            solve(root->right, curr + root->right->val,targetSum, ans, row);
            row.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        vector<int> row;
        
        solve(root, root->val, targetSum, ans, row);
        return ans;
    }
};
