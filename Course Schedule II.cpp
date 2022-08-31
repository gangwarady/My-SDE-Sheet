class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<int> adj[numCourses];
        for(int i = 0; i<prereq.size();i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }
        vector<int> ind(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            for(auto it: adj[i])
                ind[it]++;
        }
        queue<int> qu;
        for(int i = 0; i<numCourses; i++){
            if(!ind[i])
                qu.push(i);
        }
        vector<int> ans;
        while(!qu.empty()){
            int node  = qu.front();
            qu.pop();
            for(auto it: adj[node]){
                ind[it]--;
                if(ind[it]==0)
                    qu.push(it);
            }
            ans.push_back(node);
        }
        if(ans.size()!=numCourses){
          ans.clear();
        }
        return ans;
    }
};
