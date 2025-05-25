#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

// bool DFS( vector<vector<long long>>& adj , int node , int parent , vector<bool>& visited ) {
//     visited[node] = true ;
//     for( ll& ne : adj[node] ) {
//         if( !visited[ne] && DFS( adj , ne , node, visited )  )
//             return true ;
//         else if( ne != parent ) {
//             // cout << ne << " " << parent << " " ;
//             return true ;
//         }
//     }

//     // visited[node] = false ;
//     return false ;
// }

bool isBipartite( vector<vector<ll>>& adj , int src , vector<int>& colors ) {
    colors[src] = 0 ;
    queue<int> q ;
    q.push( src ) ;

    while( !q.empty() ) {
        int node = q.front();
        q.pop() ;

        for( ll& ne : adj[node] ) {
            if( colors[ne] == -1 ) {
                colors[ne] = 1 - colors[node] ;
                q.push( ne ) ;
            }
            else if ( colors[node] == colors[ne] )
                return false ;
        }
    }
    return true ;
}

pair<ll , ll> Dijk( vector<vector<ll>>& adj , ll src , vector<bool>& visited ) {
    visited[src] = true ;

    int levels = 0 , lastNode = 0 ;
    queue<int> q ;
    q.push( src ) ;
    while( !q.empty() ) {
        int size = q.size() ;
        while( size-- ) {
            int node = q.front() ;
            q.pop() ;

            for( ll& ne : adj[node] ) {
                if( !visited[ne] ) {
                    lastNode = ne ;
                    visited[ne] = true ;
                    q.push( ne ) ;
                }
            }
        }
        levels++ ;
    }

    return { levels , lastNode } ;
}

int main() {
    int t ;
    cin >> t ;
    while( t-- ) {
        int n , r ;
        cin >> n >> r ;
        vector<vector<ll>> adj( n + 1 ) ;
        for( ll i = 0 ; i < r ; i++ ) {
            ll u , v ;
            cin >> u >> v  ;
            adj[u].push_back( v ) ;
            adj[v].push_back( u ) ;
        }    

        vector<int> colors( n + 1 , -1 ) ;
        bool flag = false ;
        for( int i = 1 ; i <= n ; i++ ) {
            if( colors[i] == -1 && !isBipartite( adj , i , colors ) ) {
                // cout << i << " " ;
                flag = true ;
                break ;
            }
        }

        if( flag ) {
            cout << -1 << '\n' ;
            continue ;
        }

        vector<bool> visited1( n + 1 , false ) ;
        vector<bool> visited2( n + 1 , false ) ;
        pair<ll, ll> ans = {-1, -1} ; 
        ll total = 0 ;
        for( int i = 1 ; i <= n ; i++ ) {
            if( !visited1[i] ) {
                pair<ll, ll> r = Dijk( adj , i , visited1 ) ;
                pair<ll, ll> res = Dijk( adj , r.second , visited2 ) ;
                total = max( total , res.first ) ;
            }
        }

        cout << total << '\n' ;
    }
    return 0 ;
}

// team_233
// tgddwxr3eucp