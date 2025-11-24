#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define nl "\n"
#define all(x) x.begin(), x.end()
using vi = vector<int>;

class DSU {
private:
public:
vi par , size ;
    DSU() : par( 26 ) , size( 26 , 1 ) {
        iota( all(par) , 0 ) ;
        // fill( all(size) , 1 ) ;
    }

    int find( int x ) {
        if( par[x] == x )
            return x ;
        return par[x] = find( par[x] ) ;
    }

    void unionSize( char u , char v ) {
        int i = u - 'A' , j = v - 'A' ;
        int pU = find( i ) , pV = find( j ) ;
        if( pU == pV )
            return ;
        if( size[pU] < size[pV] ) {
            par[pU] = pV ;
            size[pV] += size[pU] ;
        }
        else {
            par[pV] = pU ;
            size[pU] += size[pV] ;
        }
    }
} ;

void yesNo( bool f1 ) {
    cout << ( f1 ? "Yes" : "No" ) << nl ;
}

void solve() {
    // char is 3-20.
    string s1 , s2 ;
    getline( cin , s1 ) ;   
    getline( cin , s2 ) ;

    DSU d ;
    int n = min( s1.size() , s2.size() ) ;
    for( int i = 0 ; i < n ; i++ ) {
        if( s1[i] != ' ' && s2[i] != ' ' )
            d.unionSize( s1[i] , s2[i] ) ;
    }

    while( cin >> s1 >> s2 ) {
        if( s1.size() != s2.size() )
            yesNo(0) ;
        else {
            bool flag = true ;
            for( int i = 0 ; i < s1.size() ; i++ ) {
                if( s1[i] != ' ' && s2[i] != ' ' ) {
                    int u = s1[i] - 'A' , v = s2[i] - 'A' ;
                    if( d.find( u ) != d.find( v ) ) {
                        flag = false ;
                        break ;
                    }
                }
            }
            yesNo( flag ) ;
        }
    }
}

signed main(){
    int t = 1 ;
    // cin >> t ;
    while( t-- ) {
        solve() ;
    }    
    return 0;
}