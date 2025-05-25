#include<bits/stdc++.h>
using namespace std ;

void memo( int i , string str , string& org, unordered_set<string>& hash ) {
    // cout << str << '\n' ;
    if( !str.empty() && hash.find( str ) != hash.end() )
        return ;

    hash.insert( str ) ;
    if( i == org.length() )
        return ;

    memo( i + 1 , str + org[i] , org , hash ) ;
    memo( i + 1 , str , org , hash ) ;
}

int main(){
    int t ;
    cin >> t ;
    while( t-- ) {
        int h ;
        cin >> h ;
        string str ;
        cin >> str ;
        unordered_set<string> hash ;
        memo( 0 , "" , str , hash ) ;
        cout << ( hash.size() % 21092013 ) << '\n' ;
    }
    return 0;
}