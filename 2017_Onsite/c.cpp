#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
int main(){
    int t ; 
    cin >> t ;
    while( t-- ) {
        ll n ;
        cin >> n ;
        ll i = ceil( sqrtl( n ) ) ;
        
        // cout << i * i << endl ;

        ll cur = ( i - 2 ) * ( i - 2 ) , prev = ( i - 4 ) * ( i - 4 ) ;
        ll next = i * i ;
        // cout << cur << " " << prev << " " << next << endl ;
        ll diff = floor( ( next - cur - 2 ) / 4LL ) ;
        ll side = 0LL  ,  corner = 1LL ;
        if( n == prev + 1 )
        
        
    } 
    return 0;
}