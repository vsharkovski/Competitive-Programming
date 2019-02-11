#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;



int dr[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[8] = {0, 1, 0, -1, -1, 1, 1, -1};

int R, C;
int numislands;
char grid[55][55];
int islandid[55][55];
bool visited[55][55];
set<int> G[2505];
int maxdist;
int dist[2505];
int parent[2505];
set<int> bydist[2505];
int level[2505];
int maxlevel;
int cnt[2505];

void dfs1(int n, int r, int c) { // set island id
    if (visited[r][c] || grid[r][c] != 'x' || islandid[r][c] != -1) return;
    visited[r][c] = 1;
    islandid[r][c] = n;
    for (int d = 0; d < 8; ++d) {
        dfs1(n, r + dr[d], c + dc[d]);
    }
}

void dfs2(int n, int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = 1;
    if (grid[r][c] == '.') {
        for (int d = 0; d < 4; ++d) {
            dfs2(n, r + dr[d], c + dc[d]);
        }
    } else if (islandid[r][c] != n) {
        G[n].insert(islandid[r][c]);
        G[islandid[r][c]].insert(n);
    }
}

//template<class T>
//void print(string s, T arr[55][55]) {
//    cout << s << ":\n";
//    for (int r = 0; r <= R+1; ++r) {
//        for (int c = 0; c <= C+1; ++c) {
//            if (sizeof(int) == sizeof(T) && arr[r][c] == -1) {
//                cout << setw(2) << right << '.' << ' ';
//                continue;
//            }
//            cout << setw(2) << right << arr[r][c] << ' ';
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> R >> C;
    memset(islandid, -1, sizeof(islandid));
    for (int r = 0; r <= R+1; ++r) {
        grid[r][0] = grid[r][C+1] = 'e';
        islandid[r][0] = islandid[r][C+1] = 0;
    }
    for (int c = 0; c <= C+1; ++c) {
        grid[0][c] = grid[R+1][c] = 'e';
        islandid[0][c] = islandid[R+1][c] = 0;
    }
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            cin >> grid[r][c];
        }
    }
    numislands = 0;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            if (grid[r][c] == 'x' && islandid[r][c] == -1) {
                ++numislands;
                memset(visited, 0, sizeof(visited));
                dfs1(numislands, r, c);
            }
        }
    }
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            if (grid[r][c] == 'x') {
                for (int d = 0; d < 8; ++d) {
                    int r1 = r + dr[d], c1 = c + dc[d];
                    if (grid[r1][c1] != 'x') {
                        memset(visited, 0, sizeof(visited));
                        dfs2(islandid[r][c], r1, c1);
                    }
                }
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    maxdist = -1;
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        maxdist = max(maxdist, dist[u]);
        bydist[dist[u]].insert(u);
        for (int v : G[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    memset(level, 0, sizeof(level));
    maxlevel = -1;
    for (int d = maxdist; d >= 1; --d) {
        for (int i : bydist[d]) {
            maxlevel = max(maxlevel, level[i]);
            level[parent[i]] = max(level[parent[i]], level[i] + 1);
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= numislands; ++i) {
        ++cnt[level[i]];
    }
    for (int i = 0; i <= maxlevel; ++i) {
        cout << cnt[i] << '\n';
    }
//    print("grid", grid);
//    print("island id", islandid);
//    for (int i = 0; i <= numislands; ++i) {
//        cout << "id=" << i << "  dist=" << dist[i] << "  neighbours: ";
//        for (int j : G[i]) {
//            cout << j << ' ';
//        }
//        cout << "\n";
//    }
//    cout << "\n";
}
