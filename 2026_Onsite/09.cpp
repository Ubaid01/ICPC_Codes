#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define readFile(file) freopen(file, "r", stdin);
#define writeFile(file) freopen(file, "w", stdout);

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
template <size_t N>
using ai = array<int, N>;
const int MOD = 1e9 + 7 ;
// #define INT_MAX LLONG_MAX

#define all(x) begin(x), end(x)
#define nl "\n"
#define f first
#define ss second
#define ctlz __builtin_clzll
#define cttz __builtin_ctzll 
#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];
void yesNo( bool b ) { cout << ( b ? "YES" : "NO" ) << nl ; }
int binaryExp( int base , int exp , int mod ) { int res = 1LL ; base %= mod ;  while ( exp > 0 ) {  if ( exp & 1 ) res = (res * base) % mod ;  base = (base * base) % mod ;  exp >>= 1LL ;  }  return res ; }
vi sieve( int n ) { vb isPrime( n + 1 , true ) ; isPrime[0] = isPrime[1] = false ;  vi primes ; for( int i = 2 ; i * i <= n ; i++ ) {  if( isPrime[i] ) {  primes.push_back( i ) ;  for( int j = i * i ; j <= n ; j += i )  isPrime[j] = false ;  }  }  return primes ;  }

int ask( int i , int j , char ch ) {
    cout << "? " << i << " " << j << " " << ch << endl ;
    int x ;
    cin >> x ;
    return x ;
}

bool cur = true ;
void solve() {
    int n , q ;
    cin >> n >> q ;

    int ww = -1 , bd = -1 , chor = -1 ;
    for( int i = 1 ; i <= n ; i++ ) {
        int a = ask( i , i , 'B' ) ;
        int b = ask( i , i , 'B' ) ;
        int c = ask( i , i , 'B' ) ;
        if( b != c )
            ww = i ;
        else if( b == 1 && c == 1 ) {
            if( !a ) bd = i ;
            else chor = i ;
        }

        if( ww != -1 && bd != -1 && chor != -1 ) break ;
    }

    cout << "! " << bd << " " << chor << " " << ww << endl ;
}

signed main() {
    FAST_IO
    int t = 1 ;
    // cin >> t ;
    for( int i = 1 ; i <= t ; i++ ) { 
        // cout << "Case " << i << ": " << nl ; 
        solve() ; 
    } 
    return 0;
}

// team16
// 88timhm65qgc