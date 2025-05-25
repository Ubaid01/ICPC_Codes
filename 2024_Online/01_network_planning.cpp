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

// const int MOD = 1e9 + 7;
// const int INF = INT_MAX;
// const long long LINF = LLONG_MAX;

// typedef long long ll;
// typedef pair<int, double>   pid;
// typedef pair<int, int>   pii;
// typedef pair<double, int>   pdi;


using namespace std;

double dijkstra(int n, int vertex, vector<vector<pair<int, int>>>& graph){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> distances(n, 100000000);
    distances[vertex] = 0;
    pq.push({ 0, vertex });

    while (!pq.empty()){
        int d = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (d > distances[current]) continue;

        for (auto& edge : graph[current]){
            int next = edge.first;
            int w = edge.second;

            if (distances[current] + w < distances[next]){
                distances[next] = distances[current] + w;
                pq.push({ distances[next], next });
            }
        }
    }
    int  sum = 0;
    for (int i = 0;i < n;i++){
        sum += distances[i];
    }
    return (sum * 1.0) / (n - 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases;
    cin >> cases;
    vector<int> res(cases);
    for (int i = 0;i < cases;i++){
        int N, M, u, v, w;
        cin >> N;
        cin >> M;
        vector<vector<pair<int, int>>> graph(N);
        for (int j = 0;j < M;j++){
            cin >> u >> v >> w;
            graph[u - 1].push_back({ v - 1,w });
            graph[v - 1].push_back({ u - 1,w });
        }
        pair<int, double> min_distance = { -1,10000000000 };
        double curr;
        for (int j = 0;j < N;j++){
            curr = dijkstra(N, j, graph);
            if (curr < min_distance.second) min_distance = { j,curr };
        }
        res[i] = min_distance.first;
    }
    for (int i = 0;i < cases;i++){
        cout << res[i] + 1 << endl;
    }
    return 0;
}