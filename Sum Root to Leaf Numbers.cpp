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
    void solve(TreeNode* root, int curr, int &sum){
        curr = 10*curr + root->val; 
        if(root->left==NULL && root->right==NULL){
            sum+=curr;
            return;
        }
        if(root->left){
            solve(root->left, curr,sum);
            
        }
        if(root->right){
            solve(root->right, curr, sum);
            
        }
        
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum =0;
        
        solve(root,0,sum);
        return sum;
    }
};
