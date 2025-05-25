#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

bool BellmanFord(int& finalDist, int start, int end, vector<vector<pair<int, int>>>& adj, set<pair<int, int>>& bannedEdges, vector<int>& shortestPath) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    vector<int> pathLength(n, INT_MAX); // To track the number of cities in the path
    vector<int> parent(n, -1);
    dist[start] = 0;
    pathLength[start] = 1;

    // Relax all edges (n-1) times
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (auto& [v, wt] : adj[u]) {
                if ( dist[u] == INT_MAX || bannedEdges.count({u, v}) || bannedEdges.count({v, u}))
                    continue;

                // Apply conditions for path selection
                bool betterPath = false;
                if (dist[u] + wt < dist[v]) {
                    betterPath = true; // Prefer smaller distance
                } else if (dist[u] + wt == dist[v]) {
                    if (pathLength[u] + 1 < pathLength[v]) {
                        betterPath = true; // Prefer fewer cities
                    } else if (pathLength[u] + 1 == pathLength[v]) {
                        betterPath = (u > parent[v]); // Prefer higher index
                    }
                }

                if (betterPath) {
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                    pathLength[v] = pathLength[u] + 1;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < n; ++u) {
        for (auto& [v, wt] : adj[u]) {
            if (bannedEdges.count({u, v}) || bannedEdges.count({v, u}))
                continue;

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                return false; // Negative-weight cycle detected
            }
        }
    }

    if (dist[end] == INT_MAX) {
        return true; // No path exists
    }

    // Build the shortest path
    finalDist = dist[end];
    for (int node = end; node != -1; node = parent[node]) {
        shortestPath.push_back(node + 1); // Convert to 1-based
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;
        int src, exit, num;
        cin >> src >> exit;
        vector<vector<pair<int, int>>> adj(m);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> num;
                if (num != 0) {
                    adj[i].push_back({j, num});
                }
            }
        }

        // Step 1: Find the first shortest path
        set<pair<int, int>> bannedEdges;
        vector<int> shortestPath;
        int firstDist = INT_MAX;

        if (!BellmanFord(firstDist, src - 1, exit - 1, adj, bannedEdges, shortestPath)) {
            cout << "-1\n"; // Negative cycle detected
            continue;
        }

        if (firstDist == INT_MAX) {
            cout << "-1\n"; // No path exists
            continue;
        }

        // Ban the edges of the first shortest path
        int l = shortestPath.size();
        for (int i = 1; i < l; i++) {
            int u = shortestPath[i - 1] - 1, v = shortestPath[i] - 1; // Convert to 0-based
            bannedEdges.insert({u, v});
            bannedEdges.insert({v, u});
        }

        // Step 2: Find the second shortest path
        vector<int> alternatePath;
        int secondDist = INT_MAX;

        if (!BellmanFord(secondDist, src - 1, exit - 1, adj, bannedEdges, alternatePath)) {
            cout << "-1\n"; // Negative cycle detected
            continue;
        }

        if (secondDist == INT_MAX) {
            cout << "-1\n"; // No alternate path exists
        } else {
            cout << secondDist << " ";
            for (int city : alternatePath) {
                cout << city << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
