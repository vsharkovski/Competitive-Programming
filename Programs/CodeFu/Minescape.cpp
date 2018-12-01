#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

//#include <iostream>



const int pow3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};

class Minescape {
public:

  int R, C;
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  int numbombs;

  bool in(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
  }

  struct State {
    int r, c, m;
    State(int R, int C, int M) : r(R), c(C), m(M) {}
    State() {}
    int status(int i) { //0=untaken, 1=taken, 2=used
      return (m / pow3[i]) % 3;
    }
    void setpos(int i, int x) {
      m -= status(i)*pow3[i];
      m += x*pow3[i];
    }
    bool operator < (const State& rhs) const {
      if (r != rhs.r) return r < rhs.r;
      if (c != rhs.c) return c < rhs.c;
      return m < rhs.m;
    }
  };

  int escape(vector<string> grid) {
    R = grid.size(), C = grid[0].size();
    int sr = 0, sc = 0, er = 0, ec = 0;

    queue<State> q;
    map<State, int> dist;
    int bombid[20][20];
    numbombs = 0;

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (grid[r][c] == '@') {
          bombid[r][c] = numbombs;
          ++numbombs;
        } else if (grid[r][c] == 'S') {
          sr = r, sc = c;
        } else if (grid[r][c] == 'E') {
          er = r, ec = c;
        }
      }
    }

    State ts(sr, sc, 0);
    State ns;
    dist[ts] = 0;
    q.push(ts);

    while (!q.empty()) {
      ts = q.front(); q.pop();
      int d0 = dist[ts];
      if (ts.r == er && ts.c == ec) {
        return d0;
      }
      if (grid[ts.r][ts.c] == '@' && ts.status(bombid[ts.r][ts.c]) == 0) {
        ts.setpos(bombid[ts.r][ts.c], 1);
        dist[ts] = d0;
      }
      ns.m = ts.m;
      for (int d = 0; d < 4; ++d) {
        ns.r = ts.r + dr[d], ns.c = ts.c + dc[d];
        if (!in(ns.r, ns.c)) continue;
        if (grid[ns.r][ns.c] == '#') {
          for (int i = 0; i < numbombs; ++i) {
            if (ts.status(i) == 1) {
              ns.setpos(i, 2);
              if (dist.count(ns) == 0) {
                dist[ns] = d0 + 1;
                q.push(ns);
              }
              ns.m = ts.m;
              break;
            }
          }
        } else if (dist.count(ns) == 0) {
          dist[ns] = d0 + 1;
          q.push(ns);
        }
      }
    }
    return -1;
  }
};
//
//#ifdef _DEBUG
//int main() {
//  Minescape e;
//  cout << e.escape({"###############","#@@@#S   ######","#@@##@   ####E#","###############"})<< endl;
//}
//#endif
