#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main(){
    int n , d, a , b ;
    cin >> n >> d >> a >> b ;
    vector<pair<int,pair<int,int>>> customers( n ) ;
    for( int i = 0 ; i < n ; i++ ) {
        cin >> customers[i].first >> customers[i].second.first ;
        customers[i].second.second = i + 1 ;
    }
    
    auto comp = [&]( const pair<int,pair<int,int>>& a , const pair<int,pair<int,int>>& b ) {
        return ( a.first + a.second.first ) < ( b.first + b.second.first ) ;
    } ;

    sort( customers.begin(), customers.end() , comp ) ;
    vector<int> indices ;
    for( int i = 0 ; i < n ; i++ ) {
        int curTotal = customers[i].first + customers[i].second.first ;
        if( d - curTotal >= 0  ) {
            d -= curTotal ;
            indices.push_back( customers[i].second.second ) ;
        }
    }

    cout << indices.size() << '\n' ;
    for( int i = 0 ; i < indices.size() ; i++ )
        cout << indices[i] << " " ;
    return 0;
}