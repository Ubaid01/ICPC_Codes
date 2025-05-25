#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> H_L1( n ) , C_L1( n ) ;
    vector<int> H_L2( m ) , C_L2( m ) ;
    for( int i = 0 ; i < n ; i++ )
        cin >> C_L1[i] ;
    
    unordered_map<int, int> hash1 , hash2 ;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> H_L1[i] ;
        hash1[ H_L1[i] ] = i ;
    }

    for( int i = 0 ; i < m ; i++ )
        cin >> C_L2[i] ;
    
    for( int i = 0 ; i < m ; i++ ) {
        cin >> H_L2[i] ;
        hash2[ H_L2[i] ] = i ;
    }
    
    int q ;
    cin >> q ;
    vector<int> queries( q ) ;
    for( int i = 0 ; i < q ; i++ )
        cin >> queries[i] ;
    
    for( int i = 0 ; i < q ; i++ ) {
        int totalCost = 0 ;
        int reqHeight = queries[i] ;
        for( auto& itr : hash2 ) {
            int findHeight = reqHeight - itr.first ;
            if( hash1.find( findHeight ) != hash1.end() ) {
                // cout << "T = " << reqHeight << " " << findHeight << " " << itr.first << endl ;
                totalCost += ( C_L2[ itr.second ] * C_L1[ hash1[ findHeight ] ] ) ;
            }
        }
        cout << totalCost << '\n' ;
    }
    
    return 0;
}