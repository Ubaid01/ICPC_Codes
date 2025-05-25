#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int k, int n, vector<int>& prices) {
    if ( n == 0 || k == 0 ) 
        return 0 ;

    // If k >= n/2, we can make as many transactions as we want (unlimited transactions).
    if ( k >= n / 2 ) {
        int profit = 0 ;
        for ( int i = 1; i < n; i++ ) {
            if ( prices[i] > prices[i - 1] )
                profit += prices[i] - prices[i - 1] ;
        }
        return profit;
    }

    // Max profit for at most i transactions till day j
    vector<vector<int>> dp(k + 1, vector<int>( n ,  0 ) ) ;
    for ( int i = 1; i <= k; i++ ) {
        int maxSoFar = -prices[0];  // This stores the max value of dp[i - 1][m] - prices[m]
        for ( int j = 1; j < n; j++ ) {
            dp[i][j] = max( dp[i][j - 1], prices[j] + maxSoFar ) ;
            maxSoFar = max( maxSoFar, dp[i - 1][j] - prices[j] ) ;
        }
    }

    return dp[k][n - 1] ;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k, n;
        cin >> k >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++)
            cin >> prices[i];

        cout << maxProfit(k, n, prices) << '\n' ;
    }

    return 0;
}
