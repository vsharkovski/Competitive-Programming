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



int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
vector<vector<char>> grid;
vector<vector<int>> cnts;
int W;

void bfs(ii src) {
  vector<vector<int>> pwr(1001, vector<int>(1001, -1));
  queue<ii> q;
  q.emplace(src);
  pwr[src.first][src.second] = W+1;
  while (!q.empty()) {
    ii top = q.front(); q.pop();
    int r = top.first, c = top.second;
    if (pwr[r][c] == 0) continue;
    ++cnts[r][c];
    for (int d = 0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (r1 >= 1 && r1 <= R && c1 >= 1 && c1 <= C) {
        if (pwr[r1][c1] == -1 && grid[r1][c1] != '#') {
          pwr[r1][c1] = pwr[r][c] - 1;
          q.emplace(r1, c1);
        }
      }
    }
  }
}

void Solve() {
  cin >> R >> C >> W;
  grid.assign(1001, vector<char>(1001));
  cnts.assign(1001, vector<int>(1001, 0));
  vii flowers;
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cin >> grid[r][c];
      if (grid[r][c] == 'C') {
        flowers.emplace_back(r, c);
      }
    }
  }
  for (ii &p : flowers) {
    bfs(p);
  }
  int ans = -1, fr = 1, fc = 1;
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      if (grid[r][c] == '.' && cnts[r][c] > ans) {
        ans = cnts[r][c];
        fr = r;
        fc = c;
      }
    }
  }
  cout << fr << " " << fc << endl;


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
