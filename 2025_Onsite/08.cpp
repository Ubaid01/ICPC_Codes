#include<bits/stdc++.h>
using namespace std;

long long Dijk( vector<vector<pair<long long,long long>>>& adj , long long src , long long end ) {
    long long n = adj.size() ;
    vector<long long> dist( n + 1 , INT_MAX ) ;
    dist[src] = 0 ;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq ;
    pq.push({ 0, src }) ;

    while( !pq.empty() ) {
        long long node = pq.top().second ;
        pq.pop() ;

        for( pair<long long,long long>& ne : adj[node] ) {
            long long neighbor = ne.first ;
            long long weight = ne.second ;
            if( dist[node] + weight < dist[neighbor] ) {
                dist[neighbor] = dist[node] + weight ;
                pq.push({ dist[neighbor], neighbor }) ;
            }
        }
    }

    return dist[end] ;
}

int main() {
    long long n , r , e , t ;
    cin >> n >> r >> e >> t ;
    vector<vector<pair<long long,long long>>> adj( n + 1 ) ;
    for( long long i = 0 ; i < r ; i++ ) {
        long long u , v , w ;
        cin >> u >> v >> w ;
        adj[u].push_back({ v, w }) ;
        adj[v].push_back({ u, w }) ;
    }    

    vector<bool> isPrime( t + 1, false ) ;
    isPrime[0] = isPrime[1] = true ;
    for( long long i = 2 ; i * i <= t ; i++ ) {
        if( !isPrime[i] ) {
            for( long long j = i * i ; j <= t ; j += i ) {
                isPrime[j] = true ;
            }
        }
    }

    long long ans = Dijk( adj , 1 , e ) ;
    long long total = 0 , count = 0 ;
    for( long long i = t - 1 ; i >= 0 ; i-- ) {
        if( !isPrime[i] ) {
            count++ ;
            // cout << i << " " ;
            total += i ;
            if( count == 3 ) 
                break ;
        }
    }
    cout << ans << " " << total << endl ;
    return 0 ;
}

// team_233
// tgddwxr3eucp