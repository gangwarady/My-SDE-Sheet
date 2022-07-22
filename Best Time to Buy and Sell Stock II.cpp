class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sell=prices[0],total=0;
        for(int i =0; i<prices.size(); i++){
            sell = prices[i];
            if(buy>prices[i]){
                buy = prices[i];
            }
            else if(buy!=sell){
                sell = prices[i];
                total += sell-buy;
                buy = prices[i];
            }
        }
        return total;
    }
};
