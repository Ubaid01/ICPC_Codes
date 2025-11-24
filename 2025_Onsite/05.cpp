#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define nl "\n"
#define int long long

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int combination(int n, int r) {
    if (r > n) 
        return 0;
    if (r == 0 || r == n) 
        return 1;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int countWays(int N, int T, int M) {
    int remainingInsects = T - N * M;
    if ( remainingInsects < 0 )
        return 0;

    return combination(remainingInsects + N - 1, N - 1);
}

vvi memo ;
int solve( int N , int T , int& MM ) {
    if( !N )
        return !T ? 1 : 0 ;
    else if( T <= 0 )
        return 0 ;
    
    if( memo[N][T] != -1 )
        return memo[N][T] ;
    
    int res = 0 ;
    for( int i = MM ; i <= T ; i++ )
        res += solve( N - 1 , T - i , MM ) ;
    
    return memo[N][T] = res ;
}

signed main() {
    int t = 1 ;
    cin >> t ;
    while (t--) {
        int N, T, M;
        cin >> N >> T >> M;
        // cout << countWays(N, T, M) << nl ;

        memo = vvi( N + 1 , vi( T + 1 , -1) );
        cout << solve(N, T, M) << nl ;
    }

    return 0;
}
