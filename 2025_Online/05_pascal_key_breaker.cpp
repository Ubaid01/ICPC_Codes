#include <bits/stdc++.h>
using namespace std ;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

unsigned long long comb(int n, int r) {
    if (r == 0 || n == r)
        return 1;
    
    // C(n, r) = C(n, n - r) FOR optimization.
    if (r > n - r)
        r = n - r;
    
    unsigned long long res = 1;
    for ( int i = 1; i <= r; i++ )
        res = res * (n - r + i) / i;
    
    return res ;
}

int main(){
    Fast_IO 

    int t ;
    cin >> t ;

    int n , r , x , y ;
    while( t-- ) {
        cin >> n >> r ;
        cin >> x >> y ;
        cout << comb( n , r - 1 ) * pow( x , n - r + 1 ) * pow(y , r - 1) << endl ; // For 1 based-r.
    }
    return 0;
}