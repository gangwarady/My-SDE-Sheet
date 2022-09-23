#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    for(int i =0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> q;
    vector<int> indg(v, 0);
    for(int i =0; i<v; i++){
        for(auto it : adj[i]){
            indg[it]++;
        }
    }
    for(int i =0; i<v; i++){
        if(indg[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indg[it]--;
            if(indg[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}
