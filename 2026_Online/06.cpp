#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;

#define NED_IO ios::sync_with_stdio(false); cin.tie(nullptr);

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Ordered Set (PBDS): Used when need indexing in sets for keys NOT duplicates. To use dups; replace 'T' with pair<T, int> and use counter for 2nd with increasing value.
// os.order_of_key(x) -> # elements strictly < x (like lower_bound index)
// os.find_by_order(k) -> iterator to k-th smallest (0-based)
// Think of:
//   order_of_key(x)  -> "index of x" if sorted
//   find_by_order(k) -> "element at index k"
// Use for: rank queries, inversion count, kth smallest/largest, etc.

#define int long long
using pi = pair<int, int> ;
using ppi = pair<int , pi> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vs = vector<string> ;
using vpi = vector<pi> ;
using vvi = vector<vi> ;
const int MOD = 1e9 + 7 ;
const int INF = LLONG_MAX ;

#define all(x) begin(x), end(x)
#define nl "\n"
#define f first
#define ss second
void yesNo( bool b ) { cout << ( b ? "YES" : "NO" ) << nl ; }
int binaryExp( int base , int exp , int mod ) { int res = 1LL ; base %= mod ;  while ( exp > 0 ) {  if ( exp & 1 ) res = (res * base) % mod ;  base = (base * base) % mod ;  exp >>= 1LL ;  }  return res ; }

const int mod = 1000000007;
const int M = 2000;
const int MAX = 2 * M;

int fact[8001], inv_fact[8001];

int binaryExp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 8000; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv_fact[8000] = binaryExp(fact[8000], mod-2);
    for (int i = 8000; i >= 1; i--) {
        inv_fact[i-1] = inv_fact[i] * i % mod;
    }
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n-r] % mod;
}

void solve() {
precompute();
    int N;
    cin >> N;
    vpi packs(N);
    vvi dp(MAX+1, vi(MAX+1, 0));
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        packs[i] = {a, b};
        dp[M - a][M - b]++;
    }

    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }

    int T = 0, S = 0;
    for (int i = 0; i < N; i++) {
        int a = packs[i].first, b = packs[i].second;
        T = (T + dp[M + a][M + b]) % mod;
        S = (S + nCr(2*a + 2*b, 2*a)) % mod;
    }

    int inv2 = binaryExp(2, mod-2);
    int ans = (T - S + mod) % mod * inv2 % mod;
    cout << ans << nl;

}

signed main() {
    NED_IO
    int t = 1 ;
    // cin >> t ;
    for( int i = 1 ; i <= t ; i++ ) { 
        // cout << "Case " << i << ": " << nl ; 
        solve() ; 
    } 
    return 0;
}