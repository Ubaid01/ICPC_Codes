#include<iostream>
#include<cmath>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;

int main() {
    long long T;
    cin >> T;

    vector<double> prob(10, 0);
    for(double i=1; i<=9; i++) {
        prob[i] = log10(i+1) - log10(i);
    }
    string line;
    double num;
    getline(cin, line);
    while(T--) {     
        double n=0;
        vector<double> digits;
        getline(cin, line);
        stringstream ss(line);
        while(ss >> num) {
            digits.push_back(num);
            n += num;
        }
        long double ans = 0;
        for(int i=1; i<=9; i++) {
            ans += fabs(prob[i] - (digits[i-1])/n);
        }
        cout << fixed << setprecision(5) << ans*100 << endl;
    }
}