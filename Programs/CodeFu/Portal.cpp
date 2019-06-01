#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <sstream>
using namespace std;

//#include <iostream>

typedef pair<int, int> pii;
typedef long long ll;



const int MAXN = 15;
const int unset = 0;

const int inf = 1e9;
const int impossible = -1;

static int dist[MAXN][MAXN][MAXN][MAXN][MAXN][MAXN];

class Portal
{
    public:

    struct State {
        int r, c, p1r, p1c, p2r, p2c, dist;
        State(int dist, int r, int c, int p1r, int p1c, int p2r, int p2c)
        : r(r), c(c), p1r(p1r), p1c(p1c), p2r(p2r), p2c(p2c), dist(dist) {}
        State() {}
    };

    struct Compare {
        bool operator () (const State& lhs, const State& rhs) const {
            return lhs.dist > rhs.dist;
        }
    };

    int R, C;
    int sr, sc, er, ec;
    char grid[MAXN][MAXN];

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    inline bool inside(int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }

    int nextwallr[4][MAXN][MAXN];
    int nextwallc[4][MAXN][MAXN];

    priority_queue<State, vector<State>, Compare> pq;

    inline void add_if_ok(int dst, int r, int c, int p1r, int p1c, int p2r, int p2c) {
        int& distref = dist[r][c][p1r][p1c][p2r][p2c];
        if (dst < distref) {
            distref = dst;
            pq.push(State(dst, r, c, p1r, p1c, p2r, p2c));
        }
    }

    int sssp() {
        int ans = inf;
        dist[sr][sc][unset][unset][unset][unset] = 0;
        pq.push(State(0, sr, sc, unset, unset, unset, unset));
        State s;
        while (!pq.empty()) {
            s = pq.top();
            pq.pop();
            if (s.dist >= ans) {
                continue;
            }
            if (s.r == er && s.c == ec) {
                ans = min(ans, s.dist);
                continue;
            }
            if (s.dist > dist[s.r][s.c][s.p1r][s.p1c][s.p2r][s.p2c]) {
                continue;
            }
            for (int d = 0; d < 4; ++d) {
                int r1 = s.r + dr[d], c1 = s.c + dc[d];
                if (inside(r1, c1)) {
                    bool ok = false;
                    if (grid[r1][c1] == ' ') {
                        ok = true;
                    } else if (r1 == s.p1r && c1 == s.p1c && (s.p2r != unset || s.p2c != unset)) {
                        r1 = s.p2r;
                        c1 = s.p2c;
                        ok = true;
                    } else if (r1 == s.p2r && c1 == s.p2c && (s.p1r != unset || s.p1c != unset)) {
                        r1 = s.p1r;
                        c1 = s.p1c;
                        ok = true;
                    }
                    if (ok) {
                        add_if_ok(s.dist+1, r1, c1, s.p1r, s.p1c, s.p2r, s.p2c);
                    }
                }
            }
            if (grid[s.r][s.c] == ' ') {
                for (int d = 0; d < 4; ++d) {
                    int pr = nextwallr[d][s.r][s.c];
                    int pc = nextwallc[d][s.r][s.c];
                    if (pr != unset || pc != unset) {
                        if (s.p1r != pr && s.p1c != pc) {
                            add_if_ok(s.dist, s.r, s.c, pr, pc, s.p2r, s.p2c);
                        }
                        if (s.p2r != pr && s.p2c != pc) {
                            add_if_ok(s.dist, s.r, s.c, s.p1r, s.p1c, pr, pc);
                        }
                    }
                }
            }
        }
        if (ans == inf) {
            ans = impossible;
        }
        return ans;
    }

    int mimimumTime(vector<string> maze) {
        R = maze.size();
        C = maze[0].size();
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                grid[r][c] = maze[r][c];
                if (grid[r][c] == 'S') {
                    sr = r, sc = c;
                    grid[r][c] = ' ';
                } else if (grid[r][c] == 'E') {
                    er = r, ec = c;
                    grid[r][c] = ' ';
                }
            }
        }
        for (int d = 0; d < 4; ++d) {
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    int r1, c1, r2, c2;
                    r1 = r + dr[d];
                    c1 = c + dc[d];
                    while (true) {
                        if (inside(r1, c1) == false) {
                            break;
                        }
                        if (grid[r1][c1] == '#') {
                            break;
                        }
                        r2 = r1 + dr[d];
                        c2 = c1 + dc[d];
                        if (inside(r2, c2) == false) {
                            break;
                        }
                        r1 = r2;
                        c1 = c2;
                    }
                    if (inside(r1, c1) == false) {
                        nextwallr[d][r][c] = unset;
                        nextwallc[d][r][c] = unset;
                    } else {
                        nextwallr[d][r][c] = r1;
                        nextwallc[d][r][c] = c1;
                    }
                }
            }
        }
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                for (int p1r = 0; p1r < R; ++p1r) {
                    for (int p1c = 0; p1c < C; ++p1c) {
                        for (int p2r = 0; p2r < R; ++p2r) {
                            for (int p2c = 0; p2c < C; ++p2c) {
                                dist[r][c][p1r][p1c][p2r][p2c] = inf;
                            }
                        }
                    }
                }
            }
        }
//        for (int r = 0; r < R; ++r) {
//            for (int c = 0; c < C; ++c) {
//                cout << maze[r][c];
//            }
//            cout << '\n';
//        }
        int ans = sssp();
        return ans;
    }
};

//
//int main() {
//    Portal a;
//    cout << a.mimimumTime({"######","#@ #E#","#   @#","# # S#","#   @#","######"})<< '\n';
//}
