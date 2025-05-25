#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Stack {
    int S, F, H;
};

int calculateMoves( vector<Stack>& stacks, string& order) {
    int moves = 0;

    for (int i = 0; i < 3; i++) {
        if (order[i] == 'S') 
            moves += stacks[i].F + stacks[i].H; 
        
        else if (order[i] == 'F')
            moves += stacks[i].S + stacks[i].H;  
        
        else if (order[i] == 'H')
            moves += stacks[i].S + stacks[i].F;  
        
    }
    return moves;
}

// enum Books { Science , Fiction , History } ;

// pair<string,int> calculateMoves( vector<int>& arr ) {
//     int moves = 0;
//     unordered_set<int> taken ;

//     vector< pair<int,int> > genres(3) ;

//     for (int i = 1; i <= 3; i++) {

//         int k = 0 ;
//         for( int j = 0 ; j < 9 ; j++) {
//             if( taken.find( j % 3 ) != taken.end() )
//                 continue;

//             if( arr[j] > arr[k] )
//                 k = j ;
//         }

//         genres.push_back( { k , k % 3 } ) ;
//         taken.insert( k % 3 ) ;
//         moves += arr[ ( k + 3 ) % 3 ] + arr[ ( k + 6 ) % 3 ] ; // Select others of same genres.
//         // cout << arr[k] << " " << arr[ ( k + 3 ) % 3 ] << " " << arr[ ( k + 6 ) % 3 ] << endl ;
//     }

//     string res( 3 , 'a' ) ;

//     for( int i = 0 ; i < 3 ; i++ ) {
//         int j = genres[i].second ;

//         if( j == Science )
//             res[ j ] = 'B' ;
//         else if( j == Fiction )
//             res[j] = 'F' ;
//         else
//             res[j] = 'S' ;
//     }

//     return { res , moves } ;
// }

int main() {
    Fast_IO

    int t;
    cin >> t;
    
    while (t--) {
        vector<Stack> stacks(3);

        for (int i = 0; i < 3; i++)
            cin >> stacks[i].S >> stacks[i].F >> stacks[i].H;
        vector<string> orders = {"HSF", "HFS", "SHF", "SFH", "FHS", "FSH"};
        int minMoves = INT_MAX;
        string bestOrder;
        
        for ( string& order : orders ) {
            int moves = calculateMoves(stacks, order);
            if (moves < minMoves) {
                minMoves = moves;
                bestOrder = order;
            }
        }

        cout << bestOrder << " " << minMoves << endl;

        // vector<int> arr(9) ;
        // for( int i = 0; i < 9; i++ )
        //     cin >> arr[i] ;
        
        // pair<string,int> ans = calculateMoves( arr ) ;
        // cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
