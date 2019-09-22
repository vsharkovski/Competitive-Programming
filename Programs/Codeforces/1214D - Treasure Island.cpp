#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid, vis, canwin, tr, bl;
 
int dr[2] = {0, 1};
int dc[2] = {1, 0};
 
inline bool in(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    n, m;
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = ch == '#';
        }
    }
    vis.assign(n, vector<int>(m));
    vis[0][0] = 1;
    queue<pii> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        int r = top.first, c = top.second;
        for (int d = 0; d < 2; ++d) {
            int r1 = r + dr[d];
            int c1 = c + dc[d];
            if (in(r1, c1) && !vis[r1][c1] && !grid[r1][c1]) {
                vis[r1][c1] = 1;
                q.emplace(r1, c1);
            }
        }
    }
    if (!vis[n-1][m-1]) {
        cout << 0 << endl;
        return 0;
    }
    if (n >= 2 && vis[n-2][m-1] && (m == 1 || !vis[n-1][m-2])) {
        cout << 1 << endl;
        return 0;
    }
    if (m >= 2 && vis[n-1][m-2] && (n == 1 || !vis[n-2][m-1])) {
        cout << 1 << endl;
        return 0;
    }
    canwin.assign(n, vector<int>(m));
    canwin[n-1][m-1] = true;
    for (int i = n-1; i >= 0; --i) {
        for (int j = m-1; j >= 0; --j) {
            if (!vis[i][j]) continue;
            if (i+1 < n && !grid[i+1][j]) canwin[i][j] |= canwin[i+1][j];
            if (j+1 < m && !grid[i][j+1]) canwin[i][j] |= canwin[i][j+1];
        }
    }
    tr.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = m-1; j >= 0; --j) {
            tr[i][j] = canwin[i][j];
            if (i > 0) tr[i][j] |= tr[i-1][j];
            if (j+1 < m) tr[i][j] |= tr[i][j+1];
        }
    }
    bl.assign(n, vector<int>(m));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            bl[i][j] = canwin[i][j];
            if (i+1 < n) bl[i][j] |= bl[i+1][j];
            if (j > 0) bl[i][j] |= bl[i][j-1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == n-1 && j == m-1) continue;
            if (!vis[i][j] || !canwin[i][j]) continue;
            int choke = 1;
            if (i > 0 && j+1 < m) choke &= ~tr[i-1][j+1];
            if (i+1 < n && j > 0) choke &= ~bl[i+1][j-1];
            if (choke) {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 2 << endl;
}
