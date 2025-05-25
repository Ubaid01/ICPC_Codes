#include <iostream>
#include <vector>
#include <sstream>
#include<unordered_set>
#include<queue>
using namespace std;

struct Node {
    int val ;
    Node* left, *right;
    Node( int val ) : val(val) , left(nullptr) , right(nullptr) {}
} ;

Node* buildTree( vector<int>& inorder , vector<int>& postorder , int inStart , int inEnd , int& index ) {
    if( inStart > inEnd )
        return nullptr ;
    
    Node* root = new Node( postorder[index--] ) ;
    int inRoot = inStart ;
	for( int i = inStart ; i <= inEnd ; i++ ) {
		if( root -> val == inorder[i] ) {
			inRoot = i ;
			break ;
		}
	}

    root -> right = buildTree( inorder , postorder , inRoot + 1 , inEnd , index ) ;
    root -> left = buildTree( inorder , postorder , inStart , inRoot - 1 , index ) ;
    return root ;
}

void levelOrder( Node* node ) {
    if( !node ) {
        cout << "Empty: " ;
        return ;
    }

    queue<Node*> q ;
    q.push( node ) ;
    while( !q.empty() ) {
        int size = q.size();
        while( size-- ) {
            Node* cur = q.front();
            q.pop() ;
            cout << cur -> val << " " ;

            if( cur -> left )  q.push( cur -> left ) ;
            if( cur -> right ) q.push( cur -> right ) ;
        }
    }
}

void preProcessSum( Node* node , bool taken , string& path , unordered_set<int>& hash , int sum ) {
    if( !node || ( !path.empty() && !taken ) ) {
        if( !path.empty() )
            hash.insert( sum ) ;
        return ;
    }

    string temp = path + "_" + to_string( node -> val ) ;
    // cout << temp << endl ;
    preProcessSum( node -> left , true , temp , hash , sum + node -> val ) ;
    preProcessSum( node -> right , true , temp , hash , sum + node -> val ) ;
    preProcessSum( node -> left , false , path , hash , sum ) ;
    preProcessSum( node -> right , false , path , hash , sum ) ;
}

int main() {
    int t;
    cin >> t;
    string dummy;
    getline(cin, dummy);  // Clear the buffer after reading t.
    
    while(t--) {
        vector<int> inorder, postorder, weights;
        string line1, line2, line3;
        
        getline(cin, line1);
        getline(cin, line2);
        getline(cin, line3);
        
        istringstream ss1(line1); // OR create a new stream each time.
        int num;
        while( ss1 >> num )
            inorder.push_back(num) ;
        
        ss1.str( line2 ) ;
        ss1.clear() ;
        while( ss1 >> num )
            postorder.push_back(num);
        
        ss1.str( line3 ) ;
        ss1.clear() ;
        while( ss1 >> num )
            weights.push_back(num) ;

        // cout << "1st : ";
        // for(int i = 0; i < inorder.size(); i++)
        //     cout << inorder[i] << " ";
        // cout << "\n2nd: ";
        // for(int i = 0; i < postorder.size(); i++)
        //     cout << postorder[i] << " ";
        // cout << "\n3rd : ";
        // for(int i = 0; i < weights.size(); i++)
        //     cout << weights[i] << " ";
        // cout << endl;

        int index = postorder.size() - 1 ;
        Node* root = buildTree( inorder , postorder , 0 , inorder.size() - 1 , index ) ;
        // levelOrder( root ) ;
        unordered_set<int> hash ;
        string temp = "" ;
        preProcessSum( root , true , temp , hash , 0 ) ;
        // for( auto& itr : hash )
        //     cout << itr << endl ;

        for( int& sum : weights ) {
            if( hash.find( sum ) != hash.end() )
                cout << "TRUE\n" ;
            else
                cout << "FALSE\n" ;
        }
    }
    
    return 0;
}