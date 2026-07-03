// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//   int x, n;
//   cin >> x >> n;
//   vector<int> street(n);
//   street[n] = 1;
//   for(int i = 1; i <= n; i++){
//     int t;
//     cin >> t;
//     street[t] = 1;
//     int res = 0, mx = 0;
//     for(int j = 1; j <= n; j++){
//       if(street[j] == 1 || n == j){
//         mx += 1;
//         res = max(res, mx);
//         mx = 0;
//       }
//       mx += 1;
//     }
//     cout << res << " ";
//   }



//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    int n;
    cin >> x >> n;

    set<long long> lights = {0, x};          // sorted positions of lights
    multiset<long long> gaps = {x};          // current gap lengths

    string out;
    out.reserve(n * 7);

    for (int i = 0; i < n; i++){
        long long p;
        cin >> p;

        auto it = lights.insert(p).first;
        auto nxt = next(it);
        auto prv = prev(it);

        long long next_val = *nxt;
        long long prev_val = *prv;

        // remove the old gap (prev_val, next_val)
        gaps.erase(gaps.find(next_val - prev_val));

        // add the two new gaps
        gaps.insert(p - prev_val);
        gaps.insert(next_val - p);

        out += to_string(*gaps.rbegin());
        out += ' ';
    }

    cout << out << "\n";
    return 0;
}