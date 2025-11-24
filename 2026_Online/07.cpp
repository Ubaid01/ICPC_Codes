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

void BFS( pi& lr , vs& grid , int d ) {
    int n = grid.size() , m = grid[0].size() ;
    int x = lr.f , y = lr.ss ;
    do {
        while( x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#' ) {
            if( grid[x][y] == '\\' ) {
                if( d == 1 )
                    d = 2 ;
                else if( d == 2 )
                    d = 1 ;
                else if( d == 3 )
                    d = 4 ;
                else
                    d = 3 ;
            }
            else if( grid[x][y] == '/' ) {
                if( d == 1 )
                    d = 4 ;
                else if( d == 2 )
                    d = 3 ;
                else if( d == 3 )
                    d = 2 ;
                else
                    d = 1 ;
            }

            if( grid[x][y] != '\\' && grid[x][y] != '/' )
                grid[x][y] = '-' ;
            if( d == 1 ) {
                y++ ;
            }
            else if( d == 2 ) {
                x++ ;
            }
            else if( d == 3 ) {
                y-- ;
            }
            else {
                x-- ;
            }
        }
    } while( x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#' && make_pair( x , y ) != lr ) ;
}

using vvb = vector<vb> ;
bool simBFS( pi& st , pi& ed , vs& grid ) {
    if( grid[st.f][st.ss] != 'S' )
        return false ;
    queue<pi> q ;
    q.push( st ) ;
    
    int n = grid.size() , m = grid[0].size() ;
    vvb vis( n , vb( m , false ) ) ;
    vis[st.f][st.ss] = true ;

    pair<int, int> dir[4] = { { 0 , 1 } , { 0 , -1 } , { 1 , 0 } , { -1 , 0 } } ;
    while( !q.empty() ) {
        int x = q.front().f , y = q.front().ss ;
        q.pop() ;

        if( x == ed.f && y == ed.ss )
            return grid[x][y] == 'T' ;
        
        for( pi& d : dir ) {
            int nx = x + d.f , ny = y + d.ss ;
            if( nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && ( grid[nx][ny] == '.' || grid[nx][ny] == 'T' ) ) {
                vis[nx][ny] = true ;
                q.push( { nx , ny } ) ;
            }
        }
    }

    return false ;
}

void solve() {
    int n , m ;
    cin >> n >> m ;
    vs grid( n ) ;
    for( int i = 0 ; i < n ; i++ )
        cin >> grid[i] ;
    
    int ct = 0 , r1 = 0 , r2 = INT_MAX ;
    pi st = { -1 , -1 }, ed = {-1, -1} , lr = { -1 , -1 } ;
    for( int i = 0 ; i < n ; i++ ) {
        for( int j = 0 ; j < m ; j++ ) {
            if( grid[i][j] == '\\' || grid[i][j] == '/' )
                ct++ ;
            
            if( grid[i][j] == 'S' )
                st = { i , j } ;
            else if( grid[i][j] == 'T' )
                ed = { i , j } ;
            else if( grid[i][j] == 'L' )
                lr = { i , j } ;
        }
    }

    int tt = 1ll << ct ;
    for( int mm = 0 ; mm < tt ; mm++ ) {
        int bt = __builtin_popcountll( mm ) ;
        int mr = 0 ;
        vs cpg = grid ;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( cpg[i][j] == '\\' || cpg[i][j] == '/' ) {
                    if( mm & ( 1ll << mr ) ) {
                        cpg[i][j] = cpg[i][j] == '\\' ? '/' : '\\' ;
                    }
                    mr++ ;
                }
            }
        }

        for( int i = 1 ; i <= 4 ; i++ ) 
            BFS( lr , cpg , i ) ;

        // for( int i = 0 ; i < n ; i++ ) {
        //     for( int j = 0 ; j < m ; j++ ) {
        //         cout << cpg[i][j] << " \n"[j == m - 1] ;
        //     }
        // }
        // cout << nl ;

        if( simBFS( st , ed , cpg ) ) {
            r1++ ;
            r2 = min( r2 , bt ) ;
        }
    }
    // cout << r1 << " " << r2 << nl ;
    if( r2 == INT_MAX )
        cout << 0 << " " << -1 << nl ;
    else
        cout << r1 << " " << r2 << nl ;
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