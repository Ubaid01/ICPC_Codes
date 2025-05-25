#include<bits/stdc++.h>
using namespace std;

void BFS( vector<vector<int>>& adj , vector<vector<int>>& temp , int root ) {
    queue<int> q ;
    q.push( root ) ;
    temp[root] = {} ;
    vector<bool> visited( adj.size() + 1 , false ) ;
    visited[root] = true ;

    while( !q.empty() ) {
        int u = q.front() ;
        q.pop() ;
        for( int& v : adj[u] ) {
            if( !visited[v] ) {
                visited[v] = true ;
                temp[v] = temp[u] ;
                temp[v].push_back( u ) ;
                q.push( v ) ;
            }
        }
    }
}

int main() {
    int t ;
    cin >> t ;
    while( t-- ) {
        int n , q , r ;
        cin >> n >> q >> r ;
        vector<vector<int>> temp( n + 3 ) ;
        vector<vector<int>> adj( n + 3 ) ;
        for( int i = 0 ; i < n - 1 ; i++ ) {
            int u , v ;
            cin >> u >> v ;
            adj[u].push_back( v ) ;
            adj[v].push_back( u ) ;
        }
        BFS( adj, temp, r ) ;
        for( int i = 0 ; i < q ; i++ ) {
            int u , k ;
            cin >> u >> k ;
            // for( int j = 0 ; j < temp[u].size() ; j++ ) {
            //     cout << temp[u][j] << " " ;
            // }
            if( temp[u].size() < k )
                cout << -1 << '\n' ;
            else
                cout << temp[u][ temp[u].size() - k ] << '\n' ;
        }
    }
    
    return 0 ;
}

// team_233
// tgddwxr3eucp