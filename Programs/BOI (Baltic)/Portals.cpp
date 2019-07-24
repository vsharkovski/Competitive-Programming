#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int MAXN = 1010;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char DCH[4] = {'N', 'E', 'S', 'W'};

struct State {
    int d, r, c;
    State(int dd, int rr, int cc) {
        d = dd, r = rr, c = cc;
    }
    State() {}
    bool operator < (const State &rhs) const {
        return d > rhs.d;
    }
};

int R, C, sr, sc, er, ec;
bool blocked[MAXN][MAXN];
int closest[MAXN][MAXN]; // distance to closest wall
pii wallpos[4][MAXN][MAXN]; // position of wall N/E/S/W of here
int dist[MAXN][MAXN]; // dijkstra
priority_queue<State, vector<State>> pq;

inline bool inside(int r, int c) {
    return r >= 0 && r <= R+1 && c >= 0 && c <= C+1;
}

void getClosest() {
    queue<pii> q;
    for (int r = 0; r <= R+1; ++r) {
        for (int c = 0; c <= C+1; ++c) {
            if (blocked[r][c]) {
                q.emplace(r, c);
                closest[r][c] = 0;
            } else {
                closest[r][c] = -1;
            }
        }
    }
    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        int r = top.first, c = top.second;
        for (int d = 0; d < 4; ++d) {
            int r1 = r + dr[d], c1 = c + dc[d];
            if (closest[r1][c1] == -1) {
                closest[r1][c1] = closest[r][c] + 1;
                q.emplace(r1, c1);
            }
        }
    }
}

void getWallPos() {
    for (int d = 0; d < 4; ++d) {
        int rstart, cstart, rchange, cchange;
        if (dr[d] >= 0) {
            rstart = R, rchange = -1;
        } else { // -1
            rstart = 0, rchange = 1;
        }
        if (dc[d] >= 0) {
            cstart = C, cchange = -1;
        } else {
            cstart = 0, cchange = 1;
        }
        for (int r = rstart; inside(r, 0); r += rchange) {
            for (int c = cstart; inside(0, c); c += cchange) {
                if (!blocked[r][c]) {
                    int r1 = r + dr[d], c1 = c + dc[d];
                    if (blocked[r1][c1]) {
                        wallpos[d][r][c] = {r, c};
                    } else {
                        wallpos[d][r][c] = wallpos[d][r1][c1];
                    }
                }
            }
        }
    }
}

void getDistance() {
    for (int r = 0; r <= R+1; ++r) {
        for (int c = 0; c <= C+1; ++c) {
            dist[r][c] = inf;
        }
    }
    dist[sr][sc] = 0;
    pq.emplace(0, sr, sc);
    while (!pq.empty()) {
        State top = pq.top();
        pq.pop();
        if (top.d > dist[top.r][top.c]) {
            continue;
        }
        // adjacent cells
        for (int d = 0; d < 4; ++d) {
            int r1 = top.r + dr[d], c1 = top.c + dc[d];
            if (inside(r1, c1) && !blocked[r1][c1] && top.d + 1 < dist[r1][c1]) {
                dist[r1][c1] = top.d + 1;
                pq.emplace(top.d + 1, r1, c1);
            }
        }
        // teleport to walls in orthogonal directions
        for (int d = 0; d < 4; ++d) {
            pii target = wallpos[d][top.r][top.c];
            int tr = target.first, tc = target.second;
            int newdist = top.d + closest[top.r][top.c];
            if (newdist < dist[tr][tc]) {
                dist[tr][tc] = newdist;
                pq.emplace(newdist, tr, tc);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> R >> C;
    for (int r = 0; r <= R+1; ++r) {
        blocked[r][0] = blocked[r][C+1] = 1;
    }
    for (int c = 0; c <= C+1; ++c) {
        blocked[0][c] = blocked[R+1][c] = 1;
    }
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            char ch;
            cin >> ch;
            if (ch == 'S') {
                sr = r, sc = c;
            } else if (ch == 'C') {
                er = r, ec = c;
            }
            blocked[r][c] = (ch == '#');
        }
    }
    getClosest();
    getWallPos();
    getDistance();
    cout << dist[er][ec] << '\n';
}
