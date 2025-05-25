#include<iostream>
#include<vector>
using namespace std ;

struct Items {
    char name ;
    int bottling_size ;
    int lebon ;
    int sticker_cost ;
    int fruits ;
} ;

int main(){
    int n ;
    cin >> n ;
    vector<Items> arr( n ) ;
    for( int i = 0 ; i < n ; i++ )
        cin >> arr[i].name >> arr[i].bottling_size >> arr[i].lebon >> arr[i].sticker_cost >> arr[i].fruits ;
    
    vector<int> indices ;
    int maxLen = 0 ;
    for( int i = 0 ; i < n ; i++ ) {
        Items prevItem = arr[i] ;
        int len = 1 ;
        vector<int> curSeq ;
        curSeq.push_back( i ) ;

        for( int j = i + 1 ; j != i ; j = ( j + 1 ) % n ) {
            double ratio = prevItem.bottling_size / ( prevItem.lebon * 1.0 ) ;
            double curRatio = arr[j].bottling_size / ( arr[j].lebon * 1.0 ) ;
            if( curRatio < ratio || arr[j].bottling_size <= prevItem.bottling_size ) // As bottling size must be strictly increasing.
                continue; 
            else if( curRatio == ratio ) {
                if( arr[j].sticker_cost > prevItem.sticker_cost )
                    continue; 
                else if( arr[j].sticker_cost == prevItem.sticker_cost ) {
                    if( arr[j].fruits > prevItem.fruits )
                        continue;
                    else {
                        len++ ;
                        curSeq.push_back(j) ;
                        prevItem = arr[j] ;
                    }
                }
                else {
                    len++ ;
                    curSeq.push_back(j) ;
                    prevItem = arr[j] ;
                }
            }
            else {
                len++ ;
                curSeq.push_back(j) ;
                prevItem = arr[j] ;
            }
        }

        // cout << len << " " << maxLen << endl ;
        if( len > maxLen ) {
            maxLen = len ;
            indices = curSeq ;
        }
    }

    cout << maxLen << '\n' ;
    for( int i = 0 ; i < maxLen ; i++ )
        cout << arr[ indices[i] ].name << '\n' ;

    return 0;
}