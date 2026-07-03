#include <iostream>
#include <vector>
using namespace std;
vector<string> rooms;

void fill(int i, int j) {
    if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size()) return;
    if (rooms[i][j] != '.') return;
    rooms[i][j] = '#';
    fill(i, j - 1); // Zuun
    fill(i - 1, j); // Deesh
    fill(i, j + 1); // Baruun
    fill(i + 1, j); // Doosh
}
int main(){
  int rows, cols, room = 0;
  cin >> rows >> cols;
  rooms.resize(rows);
  for (int i = 0; i < rows; i++){
    cin >> rooms[i];
  }
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      if (rooms[i][j] == '.'){
        fill(i, j);
        room++;
      }
    }
  } 
  cout << room;


  return 0;
}

