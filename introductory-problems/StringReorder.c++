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
    for (int i = 0; i < s.length(); i++) {
      if (map[s[i]] == 0)
        arr[i] = s[i]; 
      map[s[i]]++;
         
    }

    sort(arr, arr + 28);

    for (int i = 0; i < 28; i++) {
      cout << arr[i] << " ";
    }

    cout << endl;

    for (const auto& pair : map) {
        cout << pair.first << " " << pair.second << endl;
    }

    int n = 0;
    while (n < s.length()) {  
      if (map[arr[n]] > 1) {
        rs += arr[n];
        map[arr[n]]--;
      } else {
        rs += arr[n+1];
        map[arr[n+1]]--; 
      }
      n++;
    }
    cout << rs << endl;
    return 0;
}