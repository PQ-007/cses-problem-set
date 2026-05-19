#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);   

    for(int i = 0; i < n; i++){
      cin >> a[i];
    }

    int l = 0;
    set<int> uniq_songs;
    int max_len = 0;

    for(int r = 0; r < n; r++){
      while(uniq_songs.contains(a[r])){
        uniq_songs.erase(a[l]);
        l++;
      }
      uniq_songs.insert(a[r]);
      max_len = max(max_len, r-l+1);
    }

    cout << max_len << '\n';
    
    
    

    
    
    

    return 0;
}