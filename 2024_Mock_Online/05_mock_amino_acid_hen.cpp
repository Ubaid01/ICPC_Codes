#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class UnionFind {
public:
    unordered_map<char, char> parent;
    char find(char x) {
        if ( parent.find(x) == parent.end() )
            parent[x] = x ;
        
        if ( parent[x] != x )
            parent[x] = find(parent[x]); // Path compression
        
        return parent[x];
    }
    
    void unite(char x, char y) {
        char rootX = find(x);
        char rootY = find(y);
        
        if ( rootX != rootY ) {
            parent[rootX] = rootY; // Union operation
        }
    }
};

bool canConvert(string& amino, string& equ, string& p1, string& p2) {
    if( p1.size() != p2.size() )
        return false ;
        
    UnionFind uf;

    for (int i = 0; i < amino.size(); i++) {
        if (amino[i] != ' ' && equ[i] != ' ') {
            uf.unite(amino[i], equ[i]);
        }
    }

    // for (auto& p : uf.parent)
    //     cout << p.first << " -> " << uf.find(p.first) << endl;

    for (int i = 0; i < p1.size(); i++) {
        if ( uf.find(p1[i]) != uf.find(p2[i]) )
            return false;
    }

    return true; 
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

     string p1, p2;

    // Read pairs of strings to match
    while ( cin >> p1 >> p2 ) {
        if( canConvert(s1, s2, p1, p2) )
            cout << "YES\n" ;
        else
            cout << "NO\n" ;
    }
    
    return 0;
}