#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(vector<int> &ans, TreeNode<int> *root, int level){
    if(root==NULL)
        return;
    if(ans.size()==level)
        ans.push_back(root->data);
    solve(ans, root->left, level+1 );
    solve(ans, root->right, level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    solve(ans, root, 0);
    return ans;
}
