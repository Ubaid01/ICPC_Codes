/*   Bismillah
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
// idx.find_by_order(n); to get the nth value by order
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define pb push_back
#define f first
#define ss second
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

using pi = pair<int, int> ; 
vector<pi> res;
vector<set<int>> graph;
int DFS(int idx, vi & vis, vi & count){
    vis[idx] = 1;
    int upper = 0;// upper bhejna hy count
    int nechy = 0;// nechy sy mila
    for (auto it : graph[idx]){
        graph[it].erase(idx);//parent nikalo
        if (vis[it]){ upper++; count[it]++; }// it py subtract hoga
        else{
            int x = DFS(it, vis, count);
            if (!x) res.pb({ idx,it });
            nechy += x;//nechy sy mila
        }
    }
    nechy -= count[idx];
    return nechy + upper;
}

void solve() {
    int n , m ;
    cin >> n >> m ;

    // vector<vi> adj( n + 1 ) ;
    graph.resize( n + 1 ) ;
    for( int i = 0 ; i < m ; i++ ) {
        int u , v ;
        cin >> u >> v ;
        graph[u].insert(v) ;
        graph[v].insert(u) ;
    }

    vi vis( n + 1 , 0 ) , count( n + 1 , 0 ) ;
    int u = DFS( 1 , vis , count ) ;
    sort( all( res ) ) ;
    if( res.empty() ) 
        cout << "None" << nl ;
    else {
        cout << res.size() << nl ;
        for( pi& pp : res ) {
            if( pp.f > pp.ss ) swap( pp.f , pp.ss ) ;
            cout << pp.f << " " << pp.ss << nl ;
        }
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}