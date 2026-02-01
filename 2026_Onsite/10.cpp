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

int dijkstra( vvi& adj , vi& vis , int n ) {
    priority_queue< vi, vector<vi> , greater<vi>> pq ; 
    // pq.push( { 0 , src } ) ;
    vi dist( n + 1 , INT_MAX ) ;
    vi par( n + 1 , -1 ) ;
    dist[0] = 0 ;

    for( int i = 1 ; i <= n ; i++ ) {
        if( vis[i] ) {
            pq.push( { 0 , i } ) ;
            dist[i] = 0 ;
        }
    }

    while( !pq.empty() ) {
        int d = pq.top()[0] ;
        int node = pq.top()[1] ;
        pq.pop() ;

        if( d > dist[node] ) continue ;
        for( int& ngbr : adj[node] ) {
            if( dist[node] + 1 < dist[ngbr] ) {
                dist[ngbr] = dist[node] + 1 ;
                par[ngbr] = node ;
                pq.push( { dist[ngbr] , ngbr } ) ;
            }
        }
    }

    // for( int i = 1 ; i <= n ; i++ ) cout << i << " " << dist[i] << nl ;
    return accumulate( all(dist) , 0ll ) ;
}

void DFS( int st , int i , vi& vis , vvi& adj , vector<set<int>>& vis3 ) {
    if( vis[i] ) return ;
    vis[i] = 1 ;

    for( auto& it : adj[i] ) {
        // cout << st << " " << it << nl ;
        DFS( st , it , vis , adj , vis3 ) ;
        vis3[st].insert( it ) ;
    }
}

void solve() {
    int n , m ;
    cin >> n >> m ;

    vvi adj( n + 1 ) , adj2( n + 1 ) ;
    for( int i = 0 ; i < m ; i ++ ) {
        int u , v ;
        cin >> u >> v ;
        adj[u + 1].push_back( v + 1 ) ;
        adj2[v + 1].push_back( u + 1 ) ;
    }

    vector<set<int>> vis3( n + 1 ) ;
    for( int i = 1 ; i <= n ; i++ ) {
        vi vis( n + 1 , 0 ) ;
        DFS( i , i , vis , adj , vis3 ) ;
        // for( auto& it : vis3[i] ) 
        //     cout << it << " " ;
        // cout << nl ;
    }

    int q ;
    cin >> q ;
    while( q-- ) {
        int k ;
        cin >> k ;
        vi vis( n + 1 , 0 ) ;
        vi ya ;
        for( int i = 0 ; i < k ; i++ ) {
            int x ;
            cin >> x ;
            x++ ;
            vis[x] = 1 ;
            ya.push_back( x ) ;
        }

        bool f1 = false ;
        for( int i = 1 ; i <= n ; i++ ) {
            if( !vis[i] ) {
                bool f = false ;
                for( int& x : ya ) {
                    if( vis3[i].count(x) ) {
                        f = true ;
                        break ;
                    }
                }
                if( !f ) {
                    f1 = true ;
                    break ;
                }
            }
        }

        if( f1 ) {
            cout << -1 << nl ;
        }
        else {
            cout << dijkstra( adj2 , vis , n ) << nl ;
        }
    }
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