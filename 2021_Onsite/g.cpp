#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main(){
    int t ;
    cin >> t ;
    while( t-- ) {
        int n , k ;
        cin >> n >> k ;
        long long cost = 0LL ;
        vector<vector<int>> arr( n ) ;
        for( int i = 0 ; i < n ; i++ ) {
            arr[i].resize( n - i ) ;
            for( int j = 0 ; j < n - i ; j++ )
                cin >> arr[i][j] ;
            
            sort( arr[i].begin(), arr[i].end() ) ;
            for( int j = 0 ; j < k - i ; j++ )
                cost += arr[i][j] ;
        }

        cout << cost << '\n' ;
    }
    return 0;
}