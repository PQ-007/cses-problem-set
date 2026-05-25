#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solve(int idx, const vector<long long>& weights, long long sum1, long long sum2) {
    
    if (idx == weights.size()) {
        return abs(sum1 - sum2);
    }
    
    
    long long choice1 = solve(idx + 1, weights, sum1 + weights[idx], sum2);
    
    
    long long choice2 = solve(idx + 1, weights, sum1, sum2 + weights[idx]);
    
    return min(choice1, choice2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    cout << solve(0, weights, 0, 0) << "\n";
    
    return 0;
}