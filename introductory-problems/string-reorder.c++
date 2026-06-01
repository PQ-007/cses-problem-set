#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    string s, rs;
    cin >> s;
    map<char, int> map;
    char arr[28];
    bool t = true;
    for (int i = 0; i < s.length(); i++) {
      if (map[s[i]] == 0)
        arr[i] = s[i]; 
      map[s[i]]++;
         
    }

    for (auto a : map) {
      cout << a.first << a.second << " ";
    }
    pair<const char, int>  it = map.begin();

    while(map.end() != it && it.second != 0){
      if (t){
        cout << it.first;
        it++;
      }
      else{
        cout << it.first;
        it--;
      }
      t = !t;
      if(it.second == 0){
        it++;
      }
    }
    return 0;
}