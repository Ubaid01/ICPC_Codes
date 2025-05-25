// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n ;
//     cin >> n ;
//     vector<string> arr( n ) ;
//     for( int i = 0; i < n ; i++ )
//         cin >> arr[i] ;

//     vector<vector<vector<int>>> mat( n , vector<vector<int>>( 21 , vector<int>( 26 , 0 ) ) ) ;
//     for( int i = 0; i < n ; i++ ) {
//         int j = 0 ;
//         mat[i][j] = vector<int>( 26 , 0 ) ;
//         for( char& ch : arr[i] ) {
//             vector<int> temp = mat[i][j] ;
//             temp[ch - 'a']++ ;
//             mat[i][j + 1] = temp ;
//             j++ ;
//         }
//     }

//     int q ;
//     cin >> q ;
//     for( int i = 0; i < q ; i++ ) {
//         string str ;
//         cin >> str ;
//         vector<int> temp( 26 , 0 ) ;
//         for( char& ch : str )
//             temp[ch - 'a']++ ;

//         int cnt = 0 ;        
//         int size = str.length() ;
//         for( int j = 0 ; j < n ; j++ ) {
//             if( size > arr[j].size() )
//                 break ;
                
//             vector<int> temp2 = mat[j][size] ;
//             bool found = true ;
//             for( int k = 0 ; k < 26 ; k++ ) {
//                 if( temp[k] != temp2[k] )  {
//                     found = false ;
//                     break ;
//                 }
//             }
            
//             if( found )
//                 cnt++ ;
//         }

//         if( cnt == 0 )
//             cout << -1 << '\n' ;
//         else
//             cout << cnt << '\n' ;
//     }
//     return 0 ;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    cin >> n ;
    // for( char ch = 'a' ; ch <= 'z' ; ch++ )
    //     cout << ch - 'a' << " " << ch << "\n";

    vector<string> arr( n ) ;
    for( int i = 0; i < n ; i++ )
        cin >> arr[i] ;

    vector<unordered_map<string, int>> hash( 21 ) ;
    for( int i = 0; i < n ; i++ ) {
        string str = "" ;
        for( char& ch : arr[i] ) {
            str += ch ;
            sort( str.begin(), str.end() ) ;
            hash[ str.size() ][str]++ ;
        }
    }

    int q ;
    cin >> q ;
    for( int i = 0; i < q ; i++ ) {
        string str ;
        cin >> str ;
        sort( str.begin(), str.end() ) ;
        int size = str.size() ;
        if( hash[ size ].find( str ) == hash[size].end() )
            cout << -1 << '\n' ;
        else
            cout << hash[size][str] << '\n' ;
    }
    return 0 ;
}

