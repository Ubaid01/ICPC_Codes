#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<map>
#include<set>
#include<climits>
#include<sstream>
#include<string>
#include<cmath>

// const int MOD = 1e9 + 7;
// const int INF = INT_MAX;
// const long long LINF = LLONG_MAX;

// typedef long long ll;
// typedef pair<int, double>   pid;
// typedef pair<int, int>   pii;
// typedef pair<double, int>   pdi;


using namespace std;

int solve(vector<vector<int>>& dp, vector<vector<int>>& grid, int i, int j){
    if (i == 0 && j == 0){
        return grid[0][0];
    }
    if (i < 0 || j < 0){
        return -10000000;
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = grid[i][j] + max(solve(dp, grid, i - 1, j), solve(dp, grid, i, j - 1));
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases;
    cin >> cases;
    vector<int> res(cases);
    for (int i = 0;i < cases;i++){
        int N, M, u;
        cin >> N;
        cin >> M;
        vector<vector< int>> grid(N, vector<int>(M));
        for (int j = 0;j < N;j++){
            for (int k = 0;k < M;k++){
                cin >> grid[j][k];
            }
        }
        vector<vector< int>> dp(N + 1, vector<int>(M + 1, -1));
        res[i] = solve(dp, grid, N - 1, M - 1);
    }
    for (int i = 0;i < cases;i++){
        cout << res[i] << endl;
    }
    return 0;
}