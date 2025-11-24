#include <bits/stdc++.h>
using namespace std ;
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int design( string& s ) {
    unordered_map<char,int> freq;
    int x = s.size() - 1 ;
    bool found = true;

    for(int i = 0 ; i < s.size() ; i++ , x--) {
        freq[s[i]]++ ;
        if( s[i] != s[x] )
            found = false;
    }
    if( found )   
        return 0;

    int odd = 0;
    for( auto& itr : freq ) {
        if(itr.second % 2 != 0) 
            odd++;
        if( odd > 1 ) // Only 1-unique allowed.
            return -1;
    }

    int swaps = 0;
    int l = 0;
    int r = s.size() - 1 ;
    while( l < r ) {
        if( s[l] == s[r] ) {
            l++ ;
            r-- ;
        } 
        else {
            int k = r ;
            while ( k > l && s[k] != s[l] )
                k--;

            if( k == l ) {
                swap( s[l], s[l + 1] ) ; // Both equal-so right side is correct-position.
                swaps++;
            }
            else {
                while ( k < r ) {
                    swap(s[k], s[ k + 1] ) ; // Else swap all in mid-way.
                    k++;
                    swaps++;
                }
                l++ ;
                r-- ;
            }
        }
    }

    return swaps ;
}

int main(){
    Fast_IO 

    int t ;
    cin >> t ;
    
    string s ;
    while( t-- ) {
        cin >> s ;
        cout << design( s ) << endl ;
    }

    return 0;
}