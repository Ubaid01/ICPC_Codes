#include<iostream>
#include<algorithm>
using namespace std ;

int main(){
    int t ;
    cin >> t ;
    while( t-- >= 0 ) {
        string str ;
        getline( cin , str ) ;
        reverse( str.begin(), str.end() ) ;
        int len = 0 , minLen = INT_MAX ;
        for( char& ch : str ) {
            if( ch != ' ' )
                len++ ;
            else {
                minLen = min( minLen, len ) ;
                len = 0 ;
            }
        }

        minLen = min( minLen, len ) ;
        string res = "" ;
        for( char& ch : str ) {
            if( ch == ' ' )
                res.append( to_string( minLen ) ) ;
            else
                res += ch ;
        }

        cout << res << '\n' ;
    }

    return 0;
}