#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }

    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int current_sum = a[left].first + a[right].first;

        if (current_sum == x) {
            cout << a[left].second << " " << a[right].second << "\n";
            return 0;
        } else if (current_sum < x) {
            left++;  
        } else {
            right--; 
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}