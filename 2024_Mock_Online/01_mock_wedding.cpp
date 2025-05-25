#include<iostream>
#include<vector>

using namespace std;

int budget;

int solve(vector<vector<int>>& dp, vector<vector<int>>& prices, int curr_budget, int idx){
    if (curr_budget < 0) return -1;
    if (idx == prices.size()){
        return 0;
    }
    if (dp[idx][curr_budget] != -1) return dp[idx][curr_budget];
    int max_spent = -1;
    for (int i = 0;i < prices[idx].size();i++){
        int curr = solve(dp, prices, curr_budget - prices[idx][i], idx + 1);
        if (curr != -1){
            max_spent = max(curr + prices[idx][i], max_spent);
        }
    }
    //cout << "idx " << idx << " max " << max_spent << endl;
    return dp[idx][curr_budget] = max_spent;
}

int main(){
    int cases, categories;
    cin >> cases;
    vector<int> result;
    for (int i = 0;i < cases;i++){
        cin >> budget;
        cin >> categories;
        vector<vector<int>> prices(categories);
        vector<vector<int>> dp(categories + 1, vector<int>(budget + 1, -1));
        for (int j = 0;j < categories;j++){
            int items;
            cin >> items;
            for (int k = 0;k < items;k++){
                int x;
                cin >> x;
                prices[j].push_back(x);
            }
        }
        result.push_back(solve(dp, prices, budget, 0));
    }
    for (int i = 0;i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}