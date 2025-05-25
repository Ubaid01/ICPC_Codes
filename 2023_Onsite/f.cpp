#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int root;

void insertInTree(int temp, unordered_map<int, pair<int,pair<int, int>>>& tree) {
    if(tree.size() == 0) {
        root = temp;
        tree[temp] = {-1,{-1, -1}};
    } else {
        int hold = root;
        while(1) {
            if(hold > temp) {
                if(tree[hold].second.first == -1) {
                    tree[hold].second.first = temp;
                    tree[temp]={hold,{-1,-1}};
                    return;
                }
                else{
                    hold=tree[hold].second.first;
                }
            }
            else{
                if(tree[hold].second.second == -1) {
                    tree[hold].second.second = temp;
                    tree[temp]={hold,{-1,-1}};
                    return;
                }
                else{
                    hold=tree[hold].second.second;
                }
            }
        }
    }
}

void BFS(int start, unordered_map<int, pair<int,pair<int, int>>>& tree){
    queue<int> q;
    unordered_set<int> st;
    q.push(start);
    while(!q.empty()){
        int size=q.size();
        while(size){
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            st.insert(curr);
            if(tree[curr].second.first!=-1 && st.find(tree[curr].second.first)==st.end()){
                q.push(tree[curr].second.first);
            }
            if(tree[curr].second.second!=-1 && st.find(tree[curr].second.second)==st.end()){
                q.push(tree[curr].second.second);
            }
            if(tree[curr].first!=-1 && st.find(tree[curr].first)==st.end()){
                q.push(tree[curr].first);
            }
            size--;
        }
        cout<<endl;
    }
}

struct Node {
    int val ;
    Node* left , *right , *parent ;
    Node( int val ) : val(val) , left(nullptr), right(nullptr), parent(nullptr) {}
} ;

class BST {
private:
    Node* root ;
    Node* markStart ;
    void deleteTree( Node* node ) {
        if( !node )
            return ;

        deleteTree( node -> left ) ;
        deleteTree( node -> right ) ;
        delete node ;
    }

    void inorder( Node* node ) {
        if( !node )
            return ;
        
        inorder( node -> left ) ;
        cout << node -> val << " " ;
        inorder( node -> right ) ;
    }

public:
    BST() : root(nullptr) {}
    void insertNode( int key , int start ) {
        if( !root ) {
            root = new Node( key ) ;
            if( key == start )
                markStart = root ;
            return ;
        }

        Node* node = root , *temp ;
        while( node ) {
            temp = node ;
            if( node -> val > key )
                node = node -> left ;
            else if( node -> val < key )
                node = node -> right ;
            else
                return ;
        }

        if( temp -> val > key ) {
            temp -> left = new Node( key ) ;
            temp -> left -> parent = temp ;
            if( key == start )
                markStart = temp -> left ;
        }
        else {
            temp -> right = new Node( key ) ;
            temp -> right -> parent = temp ;
            if( key == start )
                markStart = temp -> right ;
        }
    }

    void display( ) {
        if( !markStart ) {
            cout << "Empty.\n" ;
            return ;
        }

        queue<Node*> q ;
        q.push( markStart ) ;
        unordered_set<int> hash ;
        hash.insert( markStart -> val ) ;
        cout << markStart -> val ;

        while( !q.empty() ) {
            string curLevel = "" ;
            int size = q.size() ;

            while( size-- ) { // Do for all insertions as at currentLevel.
                Node* cur = q.front() ;
                q.pop() ;
                if( cur -> left && hash.find( cur -> left -> val ) == hash.end() ) {
                    q.push( cur -> left ) ;
                    hash.insert( cur -> left -> val ) ;
                    curLevel += to_string( cur -> left -> val ) + " " ;
                }

                if( cur -> right && hash.find( cur -> right -> val ) == hash.end() ) {
                    q.push( cur -> right ) ;
                    hash.insert( cur -> right -> val ) ;
                    curLevel += to_string( cur -> right -> val ) + " " ;
                }

                if( cur -> parent && hash.find( cur -> parent -> val ) == hash.end() ) {
                    q.push( cur -> parent ) ;
                    hash.insert( cur -> parent -> val ) ;
                    curLevel += to_string( cur -> parent -> val ) + " " ;
                }
            }

            // if( child == 1 )
            //     cout << cur -> left -> val << " " ;
            // else if( child == 2 )
            //     cout << cur -> right -> val << " " ;
            // else if( child == 3 )
            //     cout << cur -> left -> val << " " << " " << cur -> right -> val << " " ;

            // if( hasParent )     
            //     cout << cur -> parent -> val << " " ;
            
            if( !curLevel.empty() )
                cout << '\n' << curLevel ; // TO handle lastLevel space.
        }
    }

    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
    ~BST() { deleteTree( root ); root = nullptr ; }
} ;

int main () {
    // int N, Start;
    // cin >> N >> Start;
    // unordered_map<int, pair<int,pair<int,int>>> tree;
    // for(int i=1; i<=N; i++) {
    //     int temp;
    //     cin >> temp;
    //     insertInTree(temp, tree);
    // }
    // BFS(Start,tree);

    BST tree ;
    int n , start ;
    cin >> n >> start ;
    while( n-- ) {
        int key ;
        cin >> key ;
        tree.insertNode( key , start ) ;
    }
    // tree.inorderTraversal( ) ;
    tree.display() ;
}