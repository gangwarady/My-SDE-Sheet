class Solution {
public:
    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first!=p2.first) return p1.first<p2.first;
        else return p1.second<p2.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        for(int i =0; i<arr.size();i++){
            int count =0;
            for(int j=0; j<32; j++){
                if((arr[i]>>j)&1)count++;
            }
            v.push_back({count,arr[i]});
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for(auto it: v){
            ans.push_back(it.second);
        }
        return ans;
    }
};
