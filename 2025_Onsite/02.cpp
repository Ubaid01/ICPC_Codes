#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t ;
    cin >> t ;
    while( t-- ) {
        long long n ;
        cin >> n ;
        long long s1 , s2 ;
        cin >> s1 >> s2 ;
        vector<pair<long long,long long>> arr1( n ) , arr2( n ) ;
        for( long long i = 0 ; i < n ; i++ )
            cin >> arr1[i].first ;
        
        for( long long i = 0 ; i < n ; i++ )
            cin >> arr2[i].first ;
        
        for( long long i = 0 ; i < n - 1 ; i++ )
            cin >> arr1[i].second ;
        
        for( long long i = 0 ; i < n - 1 ; i++ )
            cin >> arr2[i].second ;
        
        long long e1 , e2 ;
        cin >> e1 >> e2 ;

        arr1[n - 1].first += e1 ;
        arr2[n - 1].first += e2 ;

        for( long long j = n - 2 ; j >= 0 ; j-- ) {
            arr1[j].first += min( arr1[j + 1].first, arr1[j].second + arr2[j + 1].first ) ;
            arr2[j].first += min( arr2[j + 1].first, arr2[j].second + arr1[j + 1].first ) ;
            // cout<<arr1[j].first<<" "<<arr2[j].first<<endl;
        }
        cout<<min(arr1[0].first + s1,arr2[0].first + s2)<<endl;
    }
    return 0 ;
}

// team_233
// tgddwxr3eucp