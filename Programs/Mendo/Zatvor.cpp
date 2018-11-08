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





int R, C;
char grid[1002][1002];
vector<ii> guards;
int dist[1002][1002];
bool visited[1002][1002];
int sr, sc, er, ec;
int lo = 1e6-1, hi = 0;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
inline bool in(int r, int c) {
  return r >= 1 && r <= R && c >= 1 && c <= C;
}

void bfs1() {
  memset(dist, -1, sizeof(dist));
  queue<ii> q;
  for (ii &p : guards) {
    dist[p.first][p.second] = 0;
    q.push(p);
  }
  while (!q.empty()) {
    ii p = q.front(); q.pop();
    int r = p.first, c = p.second;
    lo = min(lo, dist[r][c]);
    hi = max(hi, dist[r][c]);
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (in(r1, c1) && grid[r1][c1] != '*' && dist[r1][c1] == -1) {
        dist[r1][c1] = dist[r][c] + 1;
        q.emplace(r1, c1);
      }
    }
  }
}

bool possible(int mini) {
  if (dist[sr][sc] < mini) return false;
  memset(visited, 0, sizeof(visited));
  queue<ii> q;
  visited[sr][sc] = true;
  q.emplace(sr, sc);
  while (!q.empty()) {
    ii top = q.front(); q.pop();
    int r = top.first, c = top.second;
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (in(r1, c1) && visited[r1][c1] == 0 && dist[r1][c1] >= mini) {
        visited[r1][c1] = true;
        q.emplace(r1, c1);
      }
    }
  }
  return visited[er][ec];
}

void Solve() {
  cin >> R >> C;
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cin >> grid[r][c];
      if (grid[r][c] == 'R') {
        sr = r, sc = c;
      } else if (grid[r][c] == 'Z') {
        er = r, ec = c;
      } else if (grid[r][c] == 'G') {
        guards.emplace_back(r, c);
      }
    }
  }
  bfs1();
  int mid, ans;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (possible(mid)) {
      ans = mid;
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }
  cout << ans << endl;
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
