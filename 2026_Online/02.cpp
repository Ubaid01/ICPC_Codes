#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;

#define NED_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define nl '\n'
#define all(x) x.begin(), x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
using vi = vector<int> ;
using vvi = vector<vi> ;
using vs = vector<string> ;

vvi memo ;
int check( int cur , int mask , vi& a , vs& str ) {
    // if( cur == str.size() || mask == ( 1 << str.size() ) - 1 ) // Both true always at end.
    if( cur == str.size() )
        return 0 ;
    
    if( memo[cur][mask] != -1 ) 
        return memo[cur][mask] ;

    int res = str[cur][0] == 'A' ? INT_MIN : INT_MAX ;
    for( int i = 0 ; i < str.size() ; i++ ) {
        if( mask & ( 1ll << i ) ) continue;

        int adv = 0 ;
        if( str[cur][2] == 'p' )
            adv = str[cur][0] == 'A' ? a[i] : -1ll * a[i] ;
        
        int rem = adv + check( cur + 1 , mask | ( 1ll << i ) , a , str ) ;
        if( str[cur][0] == 'A' )
            res = max( res , rem ) ;
        else
            res = min( res , rem ) ;
    }
    return memo[cur][mask] = res ;
}

void solve() {
    int n ;
    cin >> n ;
    vi a(n) ;
    for( int i = 0 ; i < n ; i++ ) cin >> a[i] ;
    
    int m ;
    cin >> m ;
    // cin.ignore() ;
    string temp ;
    getline(cin, temp) ;

    vs str(m) ;
    for( int i = 0 ; i < m ; i++ ) {
        string s ;
        getline(cin, s) ;
        str[i] = s ;
    }

    memo = vvi( m , vi( 1ll << m , -1 ) ) ;
    sort( all(a) , greater<>() ) ;
    int res = check( 0 , 0 , a , str ) ;
    if( res >= 0 )
        cout << "A " << res << nl ;
    else
        cout << "B " << -1ll * res << nl ;
}

signed main() {
    NED_IO
    int t = 1 ;
    // cin >> t ;
    for( int i = 1 ; i <= t ; i++ ) { 
        solve() ; 
    } 
    return 0;
}
