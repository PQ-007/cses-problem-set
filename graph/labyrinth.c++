#include <bits/stdc++.h>
using namespace std;
string path = "";
bool found = false;
vector<string> lab;
queue<pair<char, pair<int, int>>> q;

void bfs(int i, int j){
  if (i < 0 || i >= lab.size() || j < 0 || j >= lab[0].size()) return;
  if(lab[i][j] == 'B'){
    found = true;
    return;
  }
  if(lab[i][j-1] != '#') q.push({'L', {i, j-1}});
  if(lab[i-1][j] != '#') q.push({'U', {i-1, j}});
  if(lab[i][j+1] != '#') q.push({'R', {i, j+1}});
  if(lab[i+1][j] != '#') q.push({'D', {i+1, j}});


  pair<char, pair<int, int>> t = q.front();
  pair<int, int> cor = t.second;
  bfs(cor.first, cor.second);
  q.pop();
  path += t.first;
  return;
}

int main(){
  int n, m;

  cin >> n >> m;
  lab.resize(n);
  for (int i = 0; i < n; i++){
    cin >> lab[i];
  }

  for (int i = 1; i < n-1; i++){
    for (int j = 1; j < m-1; j++){
      if(lab[i][j] == 'A'){
        bfs(i, j);
      }      
    }
  }

  reverse(path.begin(), path.end());
  
  found ? cout << "YES" : cout << "NO"; 
  cout << endl << path;



  return 0;
}