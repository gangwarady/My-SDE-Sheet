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
    int i = 0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int,int> &mp){
        if(end<start)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        int val = root->val;
		int index = mp[val];
        root->left = solve(preorder, inorder, start, index-1,mp);
        root->right = solve(preorder, inorder, index+1, end,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]]= i;
        }
        
        return solve(preorder, inorder, 0, inorder.size()-1,mp);
    }
};
