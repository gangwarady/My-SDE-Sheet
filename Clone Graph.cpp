/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node, unordered_map<Node*, Node*> &mp){
        vector<Node*> nn;
        Node* clone = new Node(node->val);
        mp[node]= clone;
        for(auto it: node->neighbors){
            if(mp.find(it)==mp.end()){
                nn.push_back(solve(it,mp));
            }
            else{
                nn.push_back(mp[it]);
            }
        }
        clone->neighbors = nn;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0){
            Node* clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node*,Node*> mp;
        return solve(node,mp);
    }
};
