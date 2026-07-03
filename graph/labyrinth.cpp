#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char lab[N][N];
bool visited[N][N];
char dirmat[N][N];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

int main() {
    int n, m, si, sj, ei, ej;

    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 'A') { si = i; sj = j; }
            if (lab[i][j] == 'B') { ei = i; ej = j; }
        }
    }

    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    bool found = false;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == ei && cur.second == ej) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ni = cur.first + dr[i];
            int nj = cur.second + dc[i];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && lab[ni][nj] != '#' && !visited[ni][nj]) {
                visited[ni][nj] = true;
                dirmat[ni][nj] = dir[i];
                q.push({ni, nj});
            }
        }
    }

    if (found) {
        string path = "";
        int curri = ei, currj = ej;
        
        while (curri != si || currj != sj) {
            char d = dirmat[curri][currj];
            path += d;
            if (d == 'L') currj++;
            else if (d == 'R') currj--;
            else if (d == 'U') curri++;
            else if (d == 'D') curri--;
        }
        
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}