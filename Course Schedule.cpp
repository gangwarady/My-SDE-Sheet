class Solution {
public:
    bool solve(int node, vector<int> adj[], vector<int>&vis, vector<int>&dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(solve(it,adj,vis,dfsvis))
                    return true;
            }
            else if(dfsvis[it])
                return true;
        }
        dfsvis[node]=0;
        return false;
    }


    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<int> adj[numCourses];
        for(int i = 0; i<prereq.size();i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            if(!vis[i])
                if(solve(i,adj,vis,dfsvis)==true)
                    return false;
        }
        return true;
    }
};
