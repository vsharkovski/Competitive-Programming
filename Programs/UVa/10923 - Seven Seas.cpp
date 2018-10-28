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







const int R = 9, C = 8;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct State {
  int r, c, steps;
  vii obs, enm;
  State(int rr, int cc, int ss, vii &obs1, vii &enm1) {
    r = rr, c = cc, steps = ss, obs = obs1, enm = enm1;
  }
  State() {}
  bool operator < (const State &rhs) const {
    if (r != rhs.r) return r < rhs.r;
    if (c != rhs.c) return c < rhs.c;
    if (steps != rhs.steps) return steps < rhs.steps;
    if (obs != rhs.obs) return obs < rhs.obs;
    return enm < rhs.enm;
  }
};

bool bfs(State start) {
  set<State> had;
  had.insert(start);
  queue<State> q;
  q.push(start);
  State ts;
  while (!q.empty()) {
    ts = q.front(); q.pop();
    if (ts.steps == 10) continue;
    if (ts.enm.empty()) return true;

    State s;
    s.steps = ts.steps+1;
    for (int d = 0; d < 8; ++d) {
      s.r = ts.r + dr[d], s.c = ts.c + dc[d];
      if (s.r < 1 || s.r > R || s.c < 1 || s.c > C) continue;
      s.obs = ts.obs;
      s.enm.clear();
      bool stop = 0;
      for (ii e : ts.enm) {
        if (e.first == s.r && e.second == s.c) { stop = 1; break; }
        if (e.first < s.r) ++e.first;
        else if (e.first > s.r) --e.first;
        if (e.second < s.c) ++e.second;
        else if (e.second > s.c) --e.second;
        if (e.first == s.r && e.second == s.c) { stop = 1; break; }
        bool destroyed = 0;
        for (ii &o : s.obs) {
          if (e != o) continue;
          destroyed = 1;
          break;
        }
        for (auto it = s.enm.begin(); !destroyed && it != s.enm.end(); ++it) {
          if (e != *it) continue;
          destroyed = 1;
          s.obs.push_back(e);
          s.enm.erase(it);
          break;
        }
        if (!destroyed) s.enm.push_back(e);
      }
      if (!stop) {
        if (had.count(s) == 0) {
          had.insert(s);
          q.push(s);
        }
      }
    }
  }
  return false;
}

void Solve() {
  int T;
  cin >> T;
  while (T--) {
    State start;
    start.steps = 0;
    for (int r = 1; r <= R; ++r) {
      for (int c = 1; c <= C; ++c) {
        char ch;
        cin >> ch;
        if (ch == 'S') {
          start.r = r, start.c = c;
        } else if (ch == '#') {
          start.obs.emplace_back(r, c);
        } else if (ch == 'E') {
          start.enm.emplace_back(r, c);
        }
      }
    }
    bool win = bfs(start);
    if (win) cout << "I'm the king of the Seven Seas!\n";
    else cout << "Oh no! I'm a dead man!\n";
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
