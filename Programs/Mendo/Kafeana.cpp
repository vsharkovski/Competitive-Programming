#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int n, m;
vector<vector<pii>> adj;
vector<bool> visited;
vector<int> match;

void doinput() {
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    int R, C;
    cin >> R >> C;
    char grid[55][55];
    int id[55][55];
    int lastvis[55][55];
    n = m = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> grid[r][c];
            if (grid[r][c] == 'P') {
                id[r][c] = n++;
            } else if (grid[r][c] == '#') {
                id[r][c] = -2;
            } else {
                id[r][c] = -1;
            }
            lastvis[r][c] = -1;
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] == 'M') {
                id[r][c] = n + m;
                m++;
            }
        }
    }
    adj.assign(n+m, vector<pii>());
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int x = id[r][c];
            if (x >= 0 && x < n) { //person
                queue<pair<pii, int>> q;
                q.emplace(make_pair(r, c), 0);
                lastvis[r][c] = x;
                while (!q.empty()) {
                    int r1 = q.front().first.first;
                    int c1 = q.front().first.second;
                    int dist = q.front().second;
                    q.pop();
                    int y = id[r1][c1];
                    if (y >= n) { //table
                        adj[x].emplace_back(y-n, dist);
                    }
                    for (int d = 0; d < 4; ++d) {
                        int r2 = r1 + dr[d], c2 = c1 + dc[d];
                        if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C) {
                            int y = id[r2][c2];
                            if (y != -2 && lastvis[r2][c2] != x) {
                                lastvis[r2][c2] = x;
                                q.emplace(make_pair(r2, c2), dist+1);
                            }
                        }
                    }
                }
            }
        }
    }
}

// augmented path algorithm for max cardinality bipartite matching
bool dfs(int L, int maxw) {
    if (visited[L]) return false;
    visited[L] = true;
    for (pii edge : adj[L]) {
        int R = edge.first, w = edge.second;
        if (w > maxw) break;
        if (match[R] == -1 || dfs(match[R], maxw)) {
            match[R] = L;
            return true;
        }
    }
    return false;
}

bool bipartite(int maxw) {
    match.assign(m, -1);
    int matches = 0;
    for (int i = 0; i < n; ++i) {
        visited.assign(n, false);
        if (dfs(i, maxw)) {
            ++matches;
        }
    }
    return matches == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    doinput();
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int low = 1, high = 2500, mid, ans = high;
    while (low <= high) {
        mid = (low + high) / 2;
        if (bipartite(mid)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << '\n';
}
