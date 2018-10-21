#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <functional>
#include <iterator>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
// printing
#ifdef _DEBUG
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _dbg(_it, args); }
void _dbg(istream_iterator<string> it){++it;}
template<typename T, typename... Args>
void _dbg(istream_iterator<string> it, T a, Args... args){
  if (*it=="'\\n'" || *it=="\"\\n\"" || *it=="endl") { cout << "\n"; }
  else { cout << setw(8) << std::left << *it << " = " << setw(4) << std::right << a << "\n"; }
  _dbg(++it, args...); }
template<typename T>
std::ostream& _containerprint(std::ostream &out, T const &val) { return (out << setw(4) << val << " "); }
template<typename T1, typename T2>
std::ostream& _containerprint(std::ostream &out, std::pair<T1, T2> const &val) { return (out << "{" << setw(4) << val.first << " " << setw(4) << val.second << "} "); }
template<template<typename, typename...> class TT, typename... Args>
std::ostream& operator<<(std::ostream &out, const TT<Args...> &cont) { for(auto&& elem : cont) { _containerprint(out, elem); } return out; }
std::ostream& operator<<(std::ostream &out, const std::string &s) { return operator << <char>(out, s); }
#endif
// other
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const double EPS = 1e-9;
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}










const int WALL = -2, UNVISITED = -1;
int df[2] = {1, -1};
int dx[2] = {0, -1};
int dy[2] = {-1, 0};

int R, C;
int grid[2002][2002];

bool in(int r, int c) { return r >= 0 && r < R && c >= 0 && c < C; }

struct State {
  int r, c, x, y;
  bool first;
  State(int rr, int cc, int xx, int yy) : r(rr), c(cc), x(xx), y(yy) {}
  State() {}
};

void Solve() {

  int sr, sc, sx, sy;
  cin >> R >> C >> sr >> sc >> sx >> sy;
  --sr, --sc;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      char ch;
      cin >> ch;
      grid[r][c] = ch == '.' ? UNVISITED : WALL;
    }
  }

  int ans = 0;

  queue<State> q1, q2;
  q1.emplace(sr, sc, sx, sy);
  grid[sr][sc] = 0;

  State ts;
  while (!q1.empty() || !q2.empty()) {
    ++ans;
    if (!q1.empty()) {
      ts = q1.front(); q1.pop();
    } else {
      ts = q2.front(); q2.pop();
    }
    for (int d = 0; d < 2; ++d) {
      int r = ts.r + df[d];
      if (in(r, ts.c) && grid[r][ts.c] == UNVISITED) {
        grid[r][ts.c] = grid[ts.r][ts.c] + 1;
        q1.emplace(r, ts.c, ts.x, ts.y);
      }
    }
    for (int d=  0; d < 2; ++d) {
      int c = ts.c + df[d];
      int x1 = ts.x + dx[d], y1 = ts.y + dy[d];
      if (in(ts.r, c) && grid[ts.r][c] == UNVISITED && x1 >= 0 && y1 >= 0) {
        grid[ts.r][c] = grid[ts.r][ts.c] + 1;
        q2.emplace(ts.r, c, x1, y1);
      }
    }
  }

  cout << ans << endl;

//  cout << "\ngrid:\n";
//  for (int r = 0; r < R; ++r) {
//    for (int c = 0; c < C; ++c) {
//      cout << setw(2) << right;
//      if (grid[r][c] == WALL) cout << '#' << ' ';
//      else if (grid[r][c] == UNVISITED) cout << '.' << ' ';
//      else cout << grid[r][c] << ' ';
//    }
//    cout << endl;
//  }













}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
//  std::freopen("in.txt", "r", stdin);
//  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
