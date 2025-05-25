#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

int color = 1;
unordered_map<int, pair<vector<int>, unordered_set<int>>> graph;
vector<bool> visited(101, false);
void addEdge(int a, int b) {
    graph[a].first.push_back(b);
    graph[b].first.push_back(a);
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    // give info about the color to all neighbours
    for(auto i: graph[start].first) {
        graph[i].second.insert(1);
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto i : graph[node].first) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                // first decide to which color the node should be assigned
                int colorAssigned = -1;
                for(int j=1; j<=color; j++) {
                    if(graph[i].second.find(j) == graph[i].second.end()) {
                        colorAssigned = j;
                        break;
                    }
                }
                if(colorAssigned == -1) {
                    color++;
                    colorAssigned = color;
                }
                // inform the neighbours about the color
                for(auto j: graph[i].first) {
                    graph[j].second.insert(colorAssigned);
            }
        }
    }
}
}

int main() {
    long long T;
    cin >> T;
    while(T--) {
        long long s, e;
        cin >> s >> e;
        if(s == 0) {
            cout << 0 << endl;
            continue;
        }
        for(int i=0; i<s; i++) {
            long long a, b;
            cin >> a >> b;
            addEdge(a, b);
        }
        // BFS
        for(int i=1; i<=s; i++) {
            if(!visited[i]) {
                bfs(i);
            }
        }
        cout << color << endl;
    }
}