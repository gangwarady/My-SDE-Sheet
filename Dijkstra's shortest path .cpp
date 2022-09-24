#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int S) {
    queue<int>q;
    vector<int>dist(V, INT_MAX);
    dist[S] = 0;
    q.push(S);
    
    // Make Adjcent List
    vector< pair<int, int> >adj[V];
    for(int i = 0; i < edges; i++){
        int u = vec[i][0], v = vec[i][1], w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto &i : adj[top]){
            if(dist[top] + i.second < dist[i.first]){
                dist[i.first] = dist[top] + i.second;
                q.push(i.first);
            }
        }
    }
    return dist;
}
