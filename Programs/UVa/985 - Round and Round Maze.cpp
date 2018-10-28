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






int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
bool cango[500][500][4][4];
int dist[500][500][4];

inline bool in(int r, int c) {return r >= 0 && r < R && c>=0 && c < C;}

void bfs() {
  memset(dist, -1, sizeof(dist));
  dist[0][0][0] = 0;
  queue<pair<ii, int>> q;
  q.emplace(ii(0, 0), 0);
  while (!q.empty()) {
    auto top = q.front(); q.pop();
    int r = top.first.first, c = top.first.second, t = top.second;
    int t1 = (t+1) % 4;
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (in(r1, c1) && cango[r][c][t][d] && dist[r1][c1][t1] == -1) {
        dist[r1][c1][t1] = dist[r][c][t] + 1;
        q.emplace(ii(r1, c1), t1);
      }
    }
  }
}

void Solve() {
  while (cin >> R >> C) {
    memset(cango, 0, sizeof(cango));
    string dirs;
    getline(cin, dirs);
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C-(r==R-1); ++c) {
        getline(cin, dirs);
        for (char ch : dirs) {
          switch (ch) {
            case 'N': cango[r][c][0][0] = 1; break;
            case 'E': cango[r][c][0][1] = 1; break;
            case 'S': cango[r][c][0][2] = 1; break;
            case 'W': cango[r][c][0][3] = 1; break;
          }
        }
        for (int t = 1; t < 4; ++t) {
          for (int d = 0; d < 4; ++d) {
            cango[r][c][t][d] = cango[r][c][t-1][(d-1+4)%4];
          }
        }
      }
    }
    bfs();
    int mint = 1e9;
    for (int t = 0; t < 4; ++t)
      if (dist[R-1][C-1][t] != -1)
        mint = min(mint, dist[R-1][C-1][t]);
    if (mint == 1e9) cout << "no path to exit\n";
    else cout << mint << "\n";



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
