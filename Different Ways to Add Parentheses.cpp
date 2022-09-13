class Solution {
public:
    vector<int> solve(string expression, unordered_map<string,vector<int>> &dp){
        vector<int> result;
        int size = expression.size();
        for(int i =0; i<size; i++){
            if(!isdigit(expression[i])){
                vector<int> result1, result2;
                string substr = expression.substr(0,i);
                if(dp.find(substr)!=dp.end()){
                    result1 = dp[substr];
                }
                else
                    result1 = solve(substr, dp);
                substr = expression.substr(i+1);
                 if(dp.find(substr)!=dp.end()){
                    result2 = dp[substr];
                }
                else
                    result2 = solve(substr, dp);
                for(auto it: result1){
                    for(auto it2: result2){
                        if(expression[i]=='+'){
                            result.push_back(it+it2);
                        }
                        else if(expression[i]=='-'){
                            result.push_back(it-it2);
                        }
                        else{
                            result.push_back(it*it2);
                        }
                    }
                }
                
            }
           
        }
         if(result.empty()){
            result.push_back(stoi(expression));
        }
        return dp[expression]= result;
    }
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string,vector<int>> dp;
        return solve(expression, dp);
    }
};
