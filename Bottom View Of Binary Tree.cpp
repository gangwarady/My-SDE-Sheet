#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(root==NULL)
        return ans;
    map<int,int> mp;
    queue <pair<BinaryTreeNode<int> *, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *temp = it.first;
        if(temp->left)
            q.push({temp->left,it.second-1});
        if(temp->right)
            q.push({temp->right, it.second+1});
        mp[it.second]=temp->data;
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}
