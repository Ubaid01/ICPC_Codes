#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n , m ;
    cin >> n >> m ;
    vector<set<long long>> adj( n ) ;
    for( long long i = 0 ; i < m ; i++ ) {
        long long u , v ;
        cin >> u >> v ;
        adj[u].insert( v ) ;
        adj[v].insert( u ) ;
    }

    long long count = 0 ;
    unordered_set<long long> arr ;
    for( long long i = 0 ; i < n ; i++ ) {
        vector<long long> hash ;
        for( long long nei : adj[i] )
            hash.push_back( nei ) ;
        
        for( long long i = 0 ; i < hash.size() ; i++ ) {
            for( long long j = i + 1 ; j < hash.size() ; j++ ) {
                if( !arr.count( hash[j] ) && !arr.count( hash[i] ) && adj[ hash[i] ].find( hash[j] ) != adj[ hash[i] ].end() ) {
                    // cout << hash[i] << " " << hash[j] << endl ;
                    // cout << "Count = " << count << endl ;
                    count++ ;
                }
            }
        }
        arr.insert( i ) ;
    }
    
    cout << count << '\n' ;
    return 0 ;
}

// team_233
// tgddwxr3eucp