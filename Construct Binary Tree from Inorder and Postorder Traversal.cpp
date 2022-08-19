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
    TreeNode* solve( vector<int>& inorder,int start,int end, vector<int>& postorder,int ps,int pe,unordered_map<int,int> & mp){
        if(end<start || pe<ps)
            return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = mp[root->val];
        int numsleft = inroot-start;
        root->left = solve(inorder, start, inroot-1,postorder, ps, ps+numsleft-1, mp);
        root->right = solve(inorder, inroot+1, end, postorder, ps+numsleft, pe-1,mp);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]]= i;
        }
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};
