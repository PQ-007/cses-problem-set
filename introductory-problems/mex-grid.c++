#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a[100][100]; 
  cin >> n;
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        if(i == 0) a[i][j] = j;
        else if(j == 0) a[i][j] = i;
        else a[i][j] = (a[i][j-1] ^ a[i-1][j-1] ^ a[i-1][j]);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}