#include <bits/stdc++.h>
using namespace std ;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

unsigned long long minEnergy( vector<int>& arr , int i , int j ,  vector<vector<unsigned long long>>& memo ) {
    if( i >= j )
        return 0 ;
    
    if( memo[i][j] != -1 )
        return memo[i][j] ;

    unsigned long long minVal = INT_MAX ;
    for( int k = i ; k < j ; k++ ) {
        unsigned long long temp = ( minEnergy( arr , i , k , memo ) + minEnergy( arr , k + 1 , j , memo ) ) + ( arr[i - 1] * 1ULL * arr[k] * arr[j] * 1ULL ) ;
        minVal = min( minVal , temp ) ;
    }

    return memo[i][j] = minVal ;
}

int main(){
    Fast_IO 

    int t ;
    cin >> t ;

    int n ;
    while( t-- ) {
        cin >> n ;

        vector<int> arr( n + 1 ) ;
        
        vector<vector<unsigned long long>> memo( n + 1 , vector<unsigned long long>( n + 1 , -1 ) ) ;
        for( int i = 0 ; i <= n ; i++ )
            cin >> arr[i] ;
        
        cout << minEnergy( arr , 1 , n , memo ) << endl ;
    }
    return 0;
}