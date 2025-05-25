#include<iostream>
using namespace std ;

int main(){
    int t ;
    cin >> t ;
    while( t-- ) {
        int n ;
        cin >> n ;    
        if( n <= 5 )
            cout << n << '\n' ;
        else {
            int r = n / 2 ;
            n -= ( r + 2 ) ;
            cout << ( n + 1 ) * r << '\n' ; // As 1st take red = n/2 greedily. So (n + 1).
        }
    }
    return 0;
}