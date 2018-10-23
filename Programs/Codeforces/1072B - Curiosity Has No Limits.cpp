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









void Solve() {

  int n;
  cin >> n;

  vi a(n+5), b(n+5);
  vector<vi> dp(n+5, vi(5));

  for (int i = 1; i <= n-1; ++i)
    cin >> a[i];
  for (int i = 1; i <= n-1; ++i)
    cin >> b[i];

  for (int p = 0; p <= 3; ++p)
    dp[n+1][p] = 69;
  for (int i = n; i >= 2; --i) {
    for (int p = 0; p <= 3; ++p) {
      dp[i][p] = -1;
      for (int m = 0; m <= 3; ++m) {
        if (a[i-1] == (p|m) && b[i-1] == (p&m) && dp[i+1][m] != -1) {
          dp[i][p] = m;
          break;
        }
      }
    }
  }

  int m;
  for (m = 0; m <= 3; ++m)
    if (dp[2][m] != -1)
      break;

  if (m == 4) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << m << " ";
    for (int i = 2; i <= n; ++i) {
      m = dp[i][m];
      cout << m << " ";
    }
  }









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
