#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std ;

void solve( string& keyword , unordered_set<string>& hash , int i , int& count , vector<string>& vec , vector<vector<string>>& res ) {
    if( i == keyword.size() ) {
        res.push_back( vec ) ;
        count++ ;
        return ;
    }

    string str = "" ;
    for( int j = i ; j < keyword.size() ; j++ ) {
        if( keyword[j] == ',' )
            continue;

        str += keyword[j] ;
        if( hash.find( str ) != hash.end() ) {
            vec.push_back( str ) ;
            solve( keyword , hash , j + 1 , count , vec , res ) ;
            vec.pop_back() ;
        }
    }
}

int main(){
    int t ;
    cin >> t ;
    while( t-- ) {
        string list , keyword ;
        cin >> list >> keyword ;

        unordered_set<string> hash ;
        string temp = "" ;
        for( int i = 0 ; i < list.size() ; i++ ) {
            for( char& ch : list ) {
                if( ch != ',' )
                    temp += ch ;
                else if( !temp.empty() ) {
                    hash.insert( temp ) ;
                    temp = "" ;
                }
            }
        }

        if( !temp.empty() )
            hash.insert( temp ) ;

        // for( auto& itr : hash )
        //     cout << itr << endl ;
        
        int count = 0 ;
        vector<string> vec ;
        vector<vector<string>> res ;
        solve( keyword , hash , 0 , count , vec , res ) ;
        for( vector<string>& temp : res ) {
            for( string& str : temp )
                cout << str << " " ;
            cout << endl ;
        }
        cout << count << '\n' ;
    }
    return 0;
}