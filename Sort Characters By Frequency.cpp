class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: mp){
            pq.push(make_pair(it.second,it.first));
        }
        string ans;
        for(int i=0; i<mp.size(); i++){
            int val = pq.top().first;
            while(val--){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};
