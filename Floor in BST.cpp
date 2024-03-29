#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(!root)
        return INT_MAX;
    if(root->val==X)  return X;
    if(root->val>X)    return floorInBST(root->left, X);
    int fval = floorInBST(root->right, X);
    return (fval<=X)?fval : root->val;
}
