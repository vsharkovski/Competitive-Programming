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
int grid[55][55];
int dp[55][55];
bool pr[55][55]; // r+1 ?

void Solve() {
  cin >> R >> C;
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      cin >> grid[r][c];
    }
  }
  dp[1][1] = grid[1][1];
  for (int r = 2; r <= R; ++r) {
    dp[r][1] = dp[r-1][1] + grid[r][1];
    pr[r][1] = 1;
  }
  for (int c = 2; c <= C; ++c) {
    dp[1][c] = dp[1][c-1] + grid[1][c];
    pr[1][c] = 0;
  }
  for (int r = 2; r <= R; ++r) {
    for (int c = 2; c <= C; ++c) {
      dp[r][c] = max(dp[r-1][c], dp[r][c-1]) + grid[r][c];
      pr[r][c] = dp[r-1][c] > dp[r][c-1];
    }
  }
  cout << dp[R][C] << endl;
  vii ans;
  int r = R, c = C;
  while (r != 1 || c != 1) {
    ans.emplace_back(r, c);
    if (pr[r][c]) --r; else --c;
  }
  ans.emplace_back(1, 1);
  reverse(all(ans));
  for (auto &p : ans) {
    cout << p.first << " " << p.second << endl;
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
