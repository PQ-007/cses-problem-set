#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7; 

long long power(long long base, long long exp) {
    long long res = 1;
    base = base % MOD; 
    
    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        // exp must be even now
        exp = exp / 2;
        base = (base * base) % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      int a, b;
      cin >> a >> b;
      cout << power(a, b) << '\n';
    }

    return 0;
}