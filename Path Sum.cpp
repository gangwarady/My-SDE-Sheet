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
    bool solve(TreeNode* root, int targetSum, int currSum ){
        if(currSum==targetSum && root->left==NULL && root->right==NULL)
            return true;
        bool val1 = false, val2 = false;
        if(root->left)
            val1 = solve(root->left, targetSum, currSum+root->left->val);
        if(root->right)
            val2 = solve(root->right, targetSum, currSum+root->right->val);
        return val1 || val2;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return solve(root, targetSum, root->val);
    }
};
