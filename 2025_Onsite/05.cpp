#include <iostream>
#include <vector>
using namespace std;

long long factorial(long long n) {
    long long result = 1;
    for (long long i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long combination(long long n, long long r) {
    if (r > n) 
        return 0;
    if (r == 0 || r == n) 
        return 1;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

long long countWays(int N, int T, int M) {
    int remainingInsects = T - N * M;
    if ( remainingInsects < 0 )
        return 0;

    return combination(remainingInsects + N - 1, N - 1);
}

int main() {
    int K;
    cin >> K;
    
    while (K--) {
        int N, T, M;
        cin >> N >> T >> M;
        cout << countWays(N, T, M) << '\n' ;
    }

    return 0;
}
