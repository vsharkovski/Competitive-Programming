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
const int mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






// gets correct answer on UVa Online Judge's input on uDebug
// however gets WA on the site??
// if you can prove the solution is incorrect feel free to tell me

int R, C;
char grid[80][80];
int dist[80][80][5];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
inline bool in(int r, int c) {
  return r >= 0 && r <= R+1 && c >= 0 && c <= C+1;
}

struct State {
  int r, c, d;
  State(int q, int w, int e) : r(q), c(w), d(e) {}
  State() {}
};

void bfs(int sr, int sc) {
  memset(dist, -1, sizeof(dist));
  queue<State> q;
  dist[sr][sc][0] = dist[sr][sc][1] = dist[sr][sc][2] = dist[sr][sc][3] = 0;
  q.emplace(sr, sc, 4);
  State top;
  while (!q.empty()) {
    top = q.front(); q.pop();
    int r = top.r, c = top.c, d = top.d;
    for (int d1 = 0; d1 < 4; ++d1) {
      int r1 = r + dr[d1], c1 = c + dc[d1];
      if (in(r1, c1) && grid[r1][c1] == ' ' && dist[r1][c1][d1] == -1) {
        dist[r1][c1][d1] = dist[r][c][d] + (d != d1);
        q.emplace(r1, c1, d1);
      }
    }
  }
}

void Solve() {
  int BN = 1;
  while (cin >> C >> R, R != 0) {
    for (int r = 0; r <= R+1; ++r) grid[r][0] = grid[r][C+1] = ' ';
    for (int c = 0; c <= C+1; ++c) grid[0][c] = grid[R+1][c] = ' ';
    string str;
    getline(cin, str);
    for (int r = 1; r <= R; ++r) {
      getline(cin, str);
      for (int c = 1; c <= C; ++c)
        grid[r][c] = str[c-1];
    }
    cout << "Board #" << BN++ << ":\n";
    int PN = 1;
    int r1, c1, r2, c2;
    while (cin >> c1 >> r1, c1 + r1 > 0) {
      cin >> c2 >> r2;
      char t1 = grid[r1][c1], t2 = grid[r2][c2];
      grid[r1][c1] = grid[r2][c2] = ' ';
      bfs(r1, c1);
      grid[r1][c1] = t1, grid[r2][c2] = t2;
      int val = 1e9;
      for (int d = 0; d < 4; ++d)
        if (dist[r2][c2][d] != -1)
          val = min(val, dist[r2][c2][d]);
      cout << "Pair " << PN++ << ": ";
      if (val == 1e9) {
        cout << "impossible.\n";
      } else {
        cout << val+1 << " segments.\n";
      }
    }
    cout << endl;
  }















}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
