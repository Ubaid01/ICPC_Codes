#include<bits/stdc++.h>
using namespace std ;

int r , c , tokens ;
pair<int, vector<int>> memo( int i , int j , vector<vector<int>>& grid ,  vector<vector<pair<int, vector<int>>>>& dp ) {
    if( i == 0 && j == c - 1 ) {
        return { grid[i][j] , { grid[i][j] } } ;
    }
    else if( i < 0 || i >= r || j < 0 || j >= c )
        return { 0 , {} } ;

    if( dp[i][j].first != -1 )
        return dp[i][j] ;

    pair<int, vector<int>> up = memo( i - 1 , j , grid , dp ) ;
    pair<int, vector<int>> right = memo( i , j + 1 , grid , dp ) ;
    if( up.first > right.first ) {
        if( grid[i][j] > 0 ) {
            up.first += grid[i][j] ;
            up.second.push_back( grid[i][j] ) ;
        }
        return dp[i][j] = up ;
    }

    if( grid[i][j] > 0 ) {
        right.first += grid[i][j] ;
        right.second.push_back( grid[i][j] ) ;
    }
    return dp[i][j] = right ;
}

int main(){
    int t;
    cin >> t;
    for( int i = 1 ; i <= t ; i++ ) {
        cin >> r >> c >> tokens ;
        vector<vector<int>> grid( r , vector<int>( c ) ) ;
        for( int i = 0 ; i < r ; i++ ) {
            for( int j = 0 ; j < c ; j++ )
                cin >> grid[i][j] ;
        }

        vector<vector<pair<int, vector<int>>>> dp( r , vector<pair<int,vector<int>>>( c , {-1 , {} } ) ) ;
        pair<int , vector<int>> res = memo( r - 1 , 0 , grid , dp ) ;
        sort( res.second.begin() , res.second.end() ) ;
        for( int j = res.second.size() - 1 ; j >= 0 && tokens > 0 ; j-- , tokens-- )
            res.first += res.second[j] ;
        
        cout << "Case" << i << ":" << res.first << '\n' ;
    }
    return 0;
}