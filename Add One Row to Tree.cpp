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
   
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp = new TreeNode(val, root, NULL);
            return temp;
        }
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(root);
        while(depth>2){
            int s = q.size();
            for(int i =0; i<s; i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
           depth--;
        }
        while(q.size()>0){
            TreeNode* ans = q.front();
            q.pop();
            TreeNode* lefty = ans->left;
            TreeNode* righty = ans->right;
            TreeNode* l1 = new TreeNode(val);
            TreeNode* r1 = new TreeNode(val);
            ans->left = l1;
            ans->right = r1;
            l1->left = lefty;
            r1->right = righty;
            
        }
        return root;
    }
};
