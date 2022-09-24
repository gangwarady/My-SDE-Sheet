class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int> res;
        vector<int> degrees(n,0);
        vector<vector<int>> adj(n);
        for(int i =0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        queue<int> q;
        for(int i =0; i<n; i++){
            if(degrees[i]==1)
                q.push(i);
        }
        while(!q.empty()){
            res.clear();
            int size = q.size();
            for(int i =0; i<size;i++){
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for(auto it: adj[cur]){
                    degrees[it]--;
                    if(degrees[it]==1)
                        q.push(it);
                }
            }
        }
        return res;
    }
};
