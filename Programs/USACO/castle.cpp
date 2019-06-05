#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: castle
*/

const int maxn = 55;
const int maxm = 55;

int di[4] = {0, -1, 0, 1};
int dj[4] = {-1, 0, 1, 0};
char label[4] = {'W', 'N', 'E', 'S'};

int n, m;
int rooms, maxsize, maxcombined;
int bestwalli, bestwallj, bestwalld;
int adj[maxn][maxm];
int id[maxn][maxm];
int size[maxn*maxm];

inline bool in(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

inline bool has_wall(int i, int j, int d) {
    return adj[i][j] & (1 << d);
}

inline bool better_wall(int i1, int j1, int i2, int j2) {
    if (j1 != j2) return j1 < j2;
    return i1 > i2;
}


int dfs(int i, int j, int x) {
    id[i][j] = x;
    int size = 1;
    for (int d = 0; d < 4; ++d) {
        int i1 = i + di[d];
        int j1 = j + dj[d];
        if (in(i1, j1) && !has_wall(i, j, d) && id[i1][j1] == -1) {
            size += dfs(i1, j1, x);
        }
    }
    return size;
}

int main() {
    #ifndef _DEBUG
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            id[i][j] = -1;
        }
    }

    rooms = 0;
    maxsize = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (id[i][j] == -1) {
                size[rooms] = dfs(i, j, rooms);
                ++rooms;
                maxsize = max(maxsize, size[id[i][j]]);
            }
        }
    }

    maxcombined = 0;
    bestwalli = bestwallj = bestwalld = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d = 1; d <= 2; ++d) {
                int i1 = i + di[d];
                int j1 = j + dj[d];
                if (in(i1, j1) && has_wall(i, j, d) && id[i1][j1] != id[i][j]) {
                    int combined = size[id[i][j]] + size[id[i1][j1]];
                    if ((combined > maxcombined) ||
                        (combined == maxcombined && better_wall(i, j, bestwalli, bestwallj))) {
                        maxcombined = combined;
                        bestwalli = i, bestwallj = j, bestwalld = d;
                    }
                }
            }
        }
    }

    cout << rooms << '\n';
    cout << maxsize << '\n';
    cout << maxcombined << '\n';
    cout << bestwalli+1 << ' ' << bestwallj+1 << ' ' << label[bestwalld] << '\n';

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << id[i][j] << ' ';
//        }
//        cout << '\n';
//    }

}
