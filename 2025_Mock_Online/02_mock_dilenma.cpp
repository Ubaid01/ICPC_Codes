#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

enum Visits { Not = -1 , Visiting , Visited } ;

pair<int, int> BFS(int start, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, -1) ;
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int farNode = start;
    int maxDist = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for ( int& neighbor : adj[node] ) {
            if ( dist[neighbor] == -1 ) {  // if not visited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if ( dist[neighbor] > maxDist ) {
                    maxDist = dist[neighbor];
                    farNode = neighbor;
                }
            }
        }
    }

    return {farNode, maxDist};
}

int minHeight(int n, const vector<pair<int, int>>& connections) {
    vector<vector<int>> adj(n);
    for ( auto& link : connections) {
        adj[ link.first].push_back( link.second);
        adj[ link.second].push_back( link.first);
    }

    pair<int, int> firstAttempt = BFS(0, adj, n); // Find far from '0'
    int node_A = firstAttempt.first;
    
    pair<int, int> secondAttempt = BFS(node_A, adj, n);
    int node_B = secondAttempt.first;
    // int dia = secondAttempt.second;
    
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(node_A);
    parent[node_A] = -2 ;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == node_B)
            break;
        
        for (int& neighbor : adj[node]) {
            if (parent[neighbor] == -1) {
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    
    // Path from node_A to node_B
    int current = node_B;
    int count = 0 ;
    while (current != -2) {
        // path.push_back(current) ;
        count++ ;
        current = parent[current];
    }
    
    // reverse(path.begin(), path.end()) ;
    
    // Determine the middle node(s)
    int path_length = count ;
    if ( path_length % 2 == 1 )
        return 1;
    else
        return 2;
    
    return -1 ;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> links ;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        links.push_back( {u, v} ) ;
    }
    
    cout << minHeight( n, links ) << endl;
    
    return 0;
}
