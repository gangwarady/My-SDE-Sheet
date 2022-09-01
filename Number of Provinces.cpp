class Solution {
public:
    void solve(int node, vector<int>&vis, vector<int>adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it])
                solve(it,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sze = isConnected.size();
        vector<int>adj[sze];
        for(int i =0; i<sze; i++){
            for(int j=0; j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(sze,0);
        int ans = 0;
        for(int i =0;i<sze; i++){
            if(!vis[i]){
                solve(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};
