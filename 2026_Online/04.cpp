#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;

#define NED_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define nl '\n'
#define all(x) x.begin(), x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
using vi = vector<int> ;

struct Node {
    int val, cnt; 
    Node (int v = 0, int c = 0 ): val(v), cnt(c) {}
};

vector<Node> sgtr;
vi a;

Node mergeNode( Node &lf, Node &rg ) {
    if ( !lf.cnt ) 
        return rg;
    if ( !rg.cnt ) 
        return lf;
    if ( lf.val == rg.val )
        return Node(lf.val, lf.cnt + rg.cnt);
    else if (lf.cnt > rg.cnt)
        return Node(lf.val, lf.cnt - rg.cnt);
    else
        return Node(rg.val, rg.cnt - lf.cnt);
}

void build(int idx, int l, int r) {
    if (l == r) {
        sgtr[idx] = Node(a[l], 1);
        return;
    }
    int mid = l + (r - l) / 2;
    build( 2ll * idx , l, mid );
    build( 2ll * idx + 1 , mid + 1, r);
    sgtr[idx] = mergeNode(sgtr[ 2ll * idx ], sgtr[ 2ll * idx + 1 ]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) 
        return Node();
    if (ql <= l && r <= qr) 
        return sgtr[idx];
    int mid = l + (r - l) / 2;
    Node left = query( 2ll * idx , l, mid, ql, qr);
    Node right = query( 2ll * idx + 1 , mid + 1, r, ql, qr);
    return mergeNode(left, right);
}

void solve() {
    int n , q;
    cin >> n >> q;
    a = vi(n + 1) ;
    map<int, vi> pos;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i];
        pos[ a[i] ].push_back(i) ;
    }

    sgtr = vector<Node>( 4ll * n + 1 , Node() ); ; 
    build(1, 1, n);

    while ( q-- ) {
        int l, r;
        cin >> l >> r;
        Node cand = query(1, 1, n, l, r);
        if ( !cand.cnt ) {
            cout << 0 << nl ;
            continue ;
        }
        vi &vec = pos[ cand.val ] ;
        auto it1 = lower_bound( all(vec) , l) ;
        auto it2 = upper_bound( all(vec) , r) ;
        int cnt = distance(it1, it2);
        int len = r - l + 1 ;
        if ( cnt * 2ll > len ) 
            cout << cand.val << nl;
        else 
            cout << 0 << nl;
    }
}

signed main() {
    NED_IO
    int t = 1 ;
    for( int i = 1 ; i <= t ; i++ ) { 
        solve() ; 
    } 
    return 0;
}
