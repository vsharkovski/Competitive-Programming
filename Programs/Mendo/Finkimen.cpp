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
// other
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const double EPS = 1e-9;
const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}


















int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
bool visited[52][52];
int grid[52][52];
vii coords[32];

inline bool in(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C;
}

void dfs(int r, int c) {
  visited[r][c] = 1;
  for (int d = 0; d < 4; ++d) {
    int r1 = r + dr[d], c1 = c + dc[d];
    if (in(r1, c1) && !visited[r1][c1] && grid[r1][c1] >= grid[r][c]) {
      dfs(r1, c1);
    }
  }
}

void Solve() {
  cin >> R >> C;

  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cin >> grid[r][c];
      visited[r][c] = 0;
      coords[grid[r][c]].push_back(ii(r, c));
    }
  }

  int ans = 0;
  
  for (int lvl = 1; lvl <= 30; ++lvl) {
    for (auto &p : coords[lvl]) {
      int r = p.first, c = p.second;
      if (visited[r][c] == 0) {
        ++ans;
        dfs(r, c);
      }
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
