#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isValidMapping(vector<pair<int, int>>& targetEdges, vector<int>& mapping, vector<set<int>>& roadNetwork) {
    // First check if required edges exist in original network.
    for ( pair<int,int>& edge : targetEdges ) {
        int u = mapping[edge.first];
        int v = mapping[edge.second];
        if ( roadNetwork[u].find(v) == roadNetwork[u].end() && roadNetwork[v].find(u) == roadNetwork[v].end() )
            return false ;
    }
    
    // Then if mapped nodes have same structure.
    vector<int> targetDegrees( mapping.size() , 0 ) ;
    for ( pair<int,int>& edge : targetEdges ) {
        targetDegrees[edge.first]++ ;
        targetDegrees[edge.second]++ ;
    }

    vector<int> mappedDegrees(mapping.size(), 0);
    for (int i = 0; i < mapping.size(); i++) {
        for (int j = 0; j < mapping.size(); j++) {
            if ( i != j ) {
                int u = mapping[i];
                int v = mapping[j];
                if ( roadNetwork[u].find(v) != roadNetwork[u].end() ||
                    roadNetwork[v].find(u) != roadNetwork[v].end() )
                    mappedDegrees[i]++ ;
            }
        }
    }
    
    // Compare the degree sequences
    for (int i = 0; i < mapping.size(); i++) {
        if ( targetDegrees[i] != mappedDegrees[i] ) {
            // cout << targetDegrees[i] << " " << mappedDegrees[i] << endl ;
            return false;
        }
    }
    
    return true;
}

void findMappings( int k, int index, vector<int>& mapping, vector<bool>& visited,vector<pair<int, int>>& targetEdges, vector<set<int>>& roadNetwork, set<vector<int>>& uniqueMappings ) {
    if ( index == k ) { // If nodes inserted are 'k'.
        if ( isValidMapping( targetEdges, mapping, roadNetwork ) ) {
            vector<int> sortedMapping = mapping ;
            sort( sortedMapping.begin() , sortedMapping.end() ) ;
            uniqueMappings.insert( sortedMapping ) ;
        }
        return ;
    }

    for ( int i = 0 ; i < roadNetwork.size() ; i++ ) {
        if ( !visited[i] ) {
            visited[i] = true;
            mapping[index] = i ;
            findMappings(k, index + 1, mapping, visited, targetEdges, roadNetwork, uniqueMappings);
            visited[i] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // n -> city-nodes, m -> city-edges.
    vector<set<int>> adj(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int k, p;
    cin >> k >> p; // k -> network-nodes, p -> network-edges
    vector<pair<int,int>> targetNetwork ;
    
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        targetNetwork.push_back( {u, v} ) ;
    }

    set<vector<int>> uniqueMappings;
    vector<int> mapping(k, -1);
    vector<bool> visited(n, false);

    findMappings(k, 0, mapping, visited, targetNetwork, adj, uniqueMappings);
    // for( auto& itr : uniqueMappings ) {
    //     for( int n : itr )
    //         cout << n << " " ;
    //     cout << '\n' ;
    // }

    cout << uniqueMappings.size() << '\n' ;
    return 0;
}