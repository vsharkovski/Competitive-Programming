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








int tiles[12][4];
int grid[4][3][4];

int ways;
int cnt1[1<<12][2<<6]; // tiles taken (6 total always), bottom sides of 2nd row

void dfs1(int r, int c, int done) {
  if (c == 3) ++r, c = 0;
  if (r == 2) {
    int middle = grid[1][0][2]*4*4 + grid[1][1][2]*4 + grid[1][2][2];
    ++cnt1[done][middle];
    return;
  }
  for (int i = 0; i < 12; ++i) {
    if (done & (1 << i)) continue;
    if (r > 0 && grid[r-1][c][2] != tiles[i][0]) continue;
    if (c > 0 && grid[r][c-1][1] != tiles[i][3]) continue;
    for (int j = 0; j < 4; ++j)
      grid[r][c][j] = tiles[i][j];
    dfs1(r, c+1, done | (1 << i));
  }
}
void dfs2(int r, int c, int done) {
  if (c == -1) --r, c = 2;
  if (r == 1) {
    int middle = grid[2][0][0]*4*4 + grid[2][1][0]*4 + grid[2][2][0];
    int others = done ^ ((1 << 12)-1);
    ways += cnt1[others][middle];
    return;
  }
  for (int i = 0; i < 12; ++i) {
    if (done & (1 << i)) continue;
    if (r < 3 && grid[r+1][c][0] != tiles[i][2]) continue;
    if (c < 2 && grid[r][c+1][3] != tiles[i][1]) continue;
    for (int j = 0; j < 4; ++j)
      grid[r][c][j] = tiles[i][j];
    dfs2(r, c-1, done | (1 << i));
  }
}

void Solve() {
  int T;
  cin >> T;
  for (int CT = 1; CT <= T; ++CT) {
    for (int i = 0; i < 12; ++i) {
      string str;
      cin >> str;
      for (int j = 0; j < 4; ++j) {
        if (str[j] == 'R') tiles[i][j] = 0;
        else if (str[j] == 'G') tiles[i][j] = 1;
        else if (str[j] == 'B') tiles[i][j] = 2;
        else tiles[i][j] = 3;
      }
    }
    ways = 0;
    memset(cnt1, 0, sizeof(cnt1));
    dfs1(0, 0, 0);
    dfs2(3, 2, 0);
    cout << "Case " << CT << ": " << ways << endl;
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
