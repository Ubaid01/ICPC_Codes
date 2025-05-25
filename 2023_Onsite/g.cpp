#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main(){
    int n , t ;
    cin >> n >> t ;
    vector<pair<int,int>> arr( n ) ;
    for( int i = 0 ; i < n ; i++ )
        cin >> arr[i].first >> arr[i].second ;
    
    auto comp = []( const pair<int,int>& a, const pair<int,int>& b ) {
        if( a.first == b.first )
            return a.second < b.second ;
        
        return a.first > b.first ;
    } ;
    sort( arr.begin(), arr.end() , comp ) ;
    int score = 0 ;
    for( int i = 0 ; i < n ; i++ ) {
        // cout << arr[i].first << " " << arr[i].second << endl ;
        if( t - arr[i].second >= 0 ) {
            score += arr[i].first ;
            t -= arr[i].second ;
        }
    }
    cout << score << '\n' ;
    return 0;
}