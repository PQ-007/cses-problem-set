#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  char chr[] = {'A', 'B', 'C', 'D'};
  char grid[n][m];
  cin >> n >> m;
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
        cin >> grid[i][j];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << grid[i][j];
    }
    cout << "\n";
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << grid[i][j];
    }
    cout << "\n";
  }
  return 0;
}