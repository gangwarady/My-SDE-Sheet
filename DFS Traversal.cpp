void dfs(vector<int> &comp, int node, unordered_map<int,vector<int>> &adj, unordered_map<int,int> &vis){
    comp.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(comp, it, adj, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    unordered_map<int,vector<int>> adj;
    for(int it =0; it<edges.size(); it++){
       adj[edges[it][0]].push_back(edges[it][1]);
        adj[edges[it][1]].push_back(edges[it][0]);
    }
    unordered_map<int,int> vis;
    for(int i =0; i<V; i++){
        if(!vis[i]){
            vector<int> comp;
            dfs(comp, i, adj, vis);
            ans.push_back(comp);
        }
    }
    return ans;
}
