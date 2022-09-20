#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode<int> * temp = it.first;
        if(mp.find(it.second)==mp.end()){
            mp[it.second] = temp->val;
        }
        if(temp->left){
            q.push({temp->left, it.second-1});
        }
        if(temp->right){
            q.push({temp->right, it.second+1});
        }
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}
