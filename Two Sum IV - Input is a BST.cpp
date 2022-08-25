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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        vector<int> v;
        solve(root, v);
        unordered_map<int,int> mp;
        for(int i = 0; i<v.size(); i++){
            if(mp.find(k-v[i])==mp.end()){
                mp[v[i]]=i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
