#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std ;

void Dijkstra( int& finalDist , int start , int end , vector<vector<pair<int,int>>>& adj , set<pair<int,int>>& firstShortestEdges , vector<int>& shortestPath ) {
    int m = adj.size();
    vector<int> dist( m , INT_MAX ) ;
    vector<int> parent( m , -1 ) ;
    vector<int> pathLength( m , 0 );

    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<>> pq ;
    pq.push( {0, {1, start} } );  // (dist, pathLen, node).
    dist[start] = 0;
    pathLength[start] = 1 ;

    while ( !pq.empty() ) {
        int curDist = pq.top().first , node = pq.top().second.second ;
        int curPathLen = pq.top().second.first ;
        pq.pop();
        if ( curDist > dist[node] || adj[node].size() == 1 )
            continue;

        for ( pair<int,int>& n : adj[node] )  {
            int adjNode = n.first, wt = n.second ;
            if( firstShortestEdges.find( { node, adjNode } ) != firstShortestEdges.end() || 
                firstShortestEdges.find( { adjNode, node } ) != firstShortestEdges.end() )
                    continue ;
            
            bool betterPath = false;
            if ( dist[node] + wt < dist[adjNode] ) 
                betterPath = true;
            else if ( dist[node] + wt == dist[adjNode] ) {
                if ( curPathLen + 1 < pathLength[adjNode] )
                    betterPath = true;
                else if ( curPathLen + 1 == pathLength[adjNode] )
                    betterPath = ( node > parent[adjNode] ) ; // If same path length, choose higher index
            }

            if ( betterPath ) {
                dist[adjNode] = dist[node] + wt ;
                parent[adjNode] = node ;
                pathLength[adjNode] = curPathLen + 1 ;
                pq.push( { dist[adjNode], { pathLength[adjNode] , adjNode } } ) ;
            }
        }
    }

    if( dist[end] == INT_MAX ) {
        // cout << "-1\n" ;
        return ;
    }

    // cout << dist[end] << " " ;
    finalDist = dist[end] ;
    for( int city = end ; parent[city] != -1 ; city = parent[city] )
        shortestPath.push_back( city + 1 ) ; // For 1-based.

    shortestPath.push_back( start + 1 ) ;
    reverse( shortestPath.begin(), shortestPath.end() ) ;
    // for( int& city : path )
    //     cout << city << " " ;
    // cout << '\n' ;
}

int main(){
    int t ;
    cin >> t ;
    while( t-- ) {
        int m ;
        cin >> m ;
        int src , exit , num ;
        cin >> src >> exit ;
        vector<vector<pair<int,int>>> adj( m ) ; // MISTAKE ; also initialized "cols" with 'm' after from map so garbage.
        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                cin >> num ; // weight.
                if( num != 0 )
                    adj[i].push_back( {j , num} ) ;
            }
        }

        // for( auto& itr : adj ) { // By unordered_map.
        //     cout << itr.first << " " ;
        //     for( int i = 0 ; i < adj[itr.first].size() ; i++ )
        //         cout << adj[itr.first][i].first << " " << adj[itr.first][i].second << ", " ;
        //     cout << endl ;
        // }

        // 1st path is predetermined by bandits i.e. it will be shortest path SO try some other shortest path with same prescriptions.
        set<pair<int,int>> banShortestPath ;
        vector<int> shortestPath ;
        int firstDist = INT_MAX ;
        Dijkstra( firstDist , src - 1 , exit - 1 , adj , banShortestPath , shortestPath ) ; // -1 for 0-based.

        if( firstDist == INT_MAX ) {
            cout << "-1\n" ;
            continue ; 
        }

        int l = shortestPath.size() ;
        for( int i = 1 ; i < l ; i++ ) {
            int u = shortestPath[i - 1] - 1 , v = shortestPath[i] - 1 ; // Again do for 0-based.
            banShortestPath.insert( {u , v} ) ;
            banShortestPath.insert( {v, u} ) ;
        }

        int secondDist = INT_MAX ;
        vector<int> alternatePath ;
        Dijkstra( secondDist , src - 1 , exit - 1 , adj , banShortestPath, alternatePath ) ;
        if( secondDist == INT_MAX ) {
            cout << "-1\n" ;
            continue;
        }
        else {
            cout << secondDist << " " ;
            for( int& city : alternatePath )
                cout << city << " " ;
            cout << '\n' ;
        }
    }
    return 0;
}