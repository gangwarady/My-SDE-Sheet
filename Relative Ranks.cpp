class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i = 1; i<=score.size(); i++){
            pq.push(make_pair(score[i-1],i));
        }
        unordered_map<int,string> mp;
        for(int i = 1; i<=score.size(); i++){
            if(i == 1){
                mp[pq.top().second]= "Gold Medal";
                pq.pop();
            }
            else if (i==2){
                mp[pq.top().second]= "Silver Medal";
                pq.pop();
            }
            else if(i==3){
                mp[pq.top().second]= "Bronze Medal";
                pq.pop();
            }
            else{
                mp[pq.top().second]= to_string(i);
                pq.pop();
            }
        }
        vector<string> ans;
        for(int i = 1; i<=score.size(); i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
