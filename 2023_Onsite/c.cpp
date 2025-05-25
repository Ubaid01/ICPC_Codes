#include<iostream>
#include<vector>
#include<sstream>
#include<iomanip>
#include<cmath>
using namespace std ;

void updateArray( vector<double>& arr , int num , char op ) {
    if( op == '+' ) {
        for( double& n : arr )
            n -= num ;
    }
    else if( op == '-' ) {
        for( double& n : arr )
            n += num ;
    }
    else if( op == '*' ) {
        for( double& n : arr )
            n /= num ;
    }
    else if( op == '/' ) {
        for( double& n : arr )
            n *= num ;
    }
    else if( op == '>' ) {
        for( double& n : arr )
            n = ( n < num ) ;
    }
    else {
        for( double& n : arr )
            n = ( n > num ) ;
    }
}

int main(){
    int t ;
    cin >> t ;
    // string dummy ;
    // getline(cin, dummy);
    while( t-- ) {
        cin.ignore() ;
        string line ;
        getline(cin, line) ;
        istringstream iss( line ) ;
        vector<double> arr ;
        int num ;
        while( iss >> num )
            arr.push_back( num ) ;

        int times ;
        cin >> times ;
        while( times-- ) {
            int num ;
            char op ;
            cin >> num >> op ;
            updateArray( arr , num , op ) ;
        }

        for( double& n : arr ) {
            if ( signbit(n) && n == 0.0 ) // As it was showing n = -0.00.
                cout << 0.00 << " " ;
            else
                cout << fixed << setprecision(2) << n << " " ;
        }
        cout << '\n' ;
    }
    return 0;
}