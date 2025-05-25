#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
ll oddSum( ll n ) { return n * n ; }
ll evenSum( ll n ) { return n * ( n - 1 ) ; } 

int main(){
    int t ;
    cin >> t ;
    vector<pair<ll,string>> arr ;
    ll maxNum = 0LL ;
    while( t-- ) {
        ll d , w , y ;
        cin >> d >> w >> y ;
        string str = to_string(d) + to_string(w) + to_string(y) ;
        long long val = stoll( str ) ;
        arr.push_back( { d, str } ) ;
        maxNum = max( maxNum, val ) ;
    }

    vector<ll> count( maxNum , 0 ) ;
    for( ll i = 2 ; 2 * i <= maxNum ; i++ ) {
        for( ll j = 2 * i ; j < maxNum ; j += i )
            count[j]++ ;
    }

    for( int i = 0 ; i < arr.size() ; i++ ) {
       string str = arr[i].second ;
       ll d = arr[i].first ;
       ll odd = 0LL , even = 0LL ;
       for( char& ch : str ) {
            if( ( ch - '0' ) & 1 )
                odd += ch - '0' ;
            else
                even += ch - '0' ;
       }

       ll val = stoll( str ) ;
       ll ct = 0LL ;
       bool flag = false ;
       for( ll j = 1 ; j <= val ; j++ ) {
            if( !fmodl( oddSum( j ) , odd ) && !fmodl( evenSum( j ) , even ) && count[j] >= 5 ) {
                ct++ ;
                if( ct >= d ) {
                    flag = true ;
                    break ;
                }
            }
       }

       if( flag )
            cout << "Case" << i + 1 << ":Terrorist Found\n" ;
        else
            cout << "Case" << i + 1 << ":Peace\n" ;
            
    }
    return 0;
}