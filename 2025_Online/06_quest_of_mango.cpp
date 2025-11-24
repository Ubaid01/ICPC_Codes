#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<map>
#include<set>
#include<climits>
#include<sstream>
#include<string>
#include<cmath>
using namespace std;

pair<int, int> bfs(int start, vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> d(n, -1);

    q.push(start);
    visited[start] = true;
    d[start] = 0;

    int fd = start, dd = 0;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                d[neighbor] = d[node] + 1;
                q.push(neighbor);
                if (d[neighbor] > dd){
                    dd = d[neighbor];
                    fd = neighbor;
                }
            }
        }
    }

    return { fd, dd };
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;
    vector<vector<int>> res(cases);
    for (int i = 0;i < cases;i++){
        int N, u, v;
        cin >> N;

        vector<vector<int>> graph(N);
        for (int j = 0; j < N - 1; j++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ls, d, h;
        pair<int, int> pp;
        pp = bfs(0, graph);
        ls = pp.first;
        pp = bfs(ls, graph);
        d = pp.second;
        vector<int> highests(N);
        for (int k = 0; k < N; k++){
            highests[k] = graph[k].size();
        }

        sort(highests.begin(), highests.end());
        res[i] = { d,highests.back(),highests[N - 2] };
    }
    for (int i = 0;i < cases;i++){
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }
    return 0;
}
