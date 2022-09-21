#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    if(root==NULL)
        return {-1,-1};
    BinaryTreeNode<int>* suc = root;
    BinaryTreeNode<int>* pre = root;
    int pp=-1, ss=-1;
    while(root!=NULL){
        if(root->data==key){
            
            if(root->right){
                suc = root->right;
                while(suc->left){
                    suc = suc->left;
                }
                ss = suc->data;
            }
            if(root->left){
                pre = root->left;
                while(pre->right){
                    pre = pre->right;
                }
                pp=pre->data;
            }
            return {pp, ss};
        }
        else if(root->data<key){
            pre = root;
            pp = pre->data;
            root = root->right;
        }
        else{
            suc = root;
            ss = suc->data;
            root = root->left;
        }
    }
    return {-1, -1};
}
