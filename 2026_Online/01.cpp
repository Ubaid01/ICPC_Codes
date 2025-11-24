/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-23 11:09 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can't remember the past are condemned to repeat it.
*                                                 -Dynamic Programming.
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

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

int res=0;

vi ss1(Node *curr){
    vi aa={-1,-1,-1};//sum,mm,mx
    if(curr->left && curr->right){
        // cout<<curr->val<<" "<<curr->left->val<<" "<<curr->right->val<<endl;
        vi ya=ss1(curr->left);
        vi ya1=ss1(curr->right);
        if(ya[0]==-1 || ya1[0]==-1) return {-1,-1,-1};
        if(ya[2]<curr->val && ya1[1]>curr->val){
            res=max(res,curr->val+ya[0]+ya1[0]);
            return {curr->val+ya[0]+ya1[0],ya[1],ya1[2]};
        }
        else return {-1,-1,-1};
    }
    else if(curr->left){
        vi ya=ss1(curr->left);
        if(ya[0]==-1) return {-1,-1,-1};
        if(ya[2]<curr->val){
            res=max(res,curr->val+ya[0]);
            return {ya[0]+curr->val,ya[1],curr->val};
        }
        else return {-1,-1,-1};
    }
    else if(curr->right){
        vi ya=ss1(curr->right);
        if(ya[0]==-1) return {-1,-1,-1};
        if(ya[1]>curr->val){
            res=max(res,curr->val+ya[0]);
            return {ya[0]+curr->val,curr->val,ya[2]};
        }
        else return {-1,-1,-1};
    }
    else{
        res=max(res,curr->val);
        return {curr->val,curr->val,curr->val};
    }
}

void solve() {
    res=0LL;
    string line;
    getline(cin, line);  
    stringstream ss(line);
    vi arr;
    int x;
    while (ss >> x) {
        arr.push_back(x);
    }
    if(arr[0]==-1){ cout<<0<<endl; return;}
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    // map<int, vector<int>> graph;
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        else curr->left=nullptr;
        i++;
        if (i >= arr.size()) break;
        if (arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        } else {
            curr->right=nullptr;
        }
        i++;
    }
    vi ya=ss1(root);
    cout<<res<<endl;
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