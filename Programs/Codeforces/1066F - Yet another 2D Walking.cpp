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
const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






inline int dist(ii &a, ii &b) {
  return abs(a.first-b.first) + abs(a.second-b.second);
}

void Solve() {
  int n;
  cin >> n;

  map<int, vii> pts;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    pts[max(x, y)].emplace_back(x, y);
  }

  for (auto &kv : pts) {
    sort(kv.second.begin(), kv.second.end(), [&](ii &a, ii &b) {
      if (a.first != b.first) return a.first < b.first;
      return a.second > b.second;
    });
  }

  vector<vector<ll>> dp(pts.size()+5, vector<ll>(2));
  dp[0][0] = dp[0][1] = 0;

  int i = 1;
  ii p0 = {0, 0}, p1 = {0, 0};
  ii c0, c1;

  for (auto &kv : pts) {
    c0 = kv.second[0];
    c1 = kv.second.back();

    dp[i][0] = min(dp[i-1][0] + dist(p0, c1),
                   dp[i-1][1] + dist(p1, c1))
               + dist(c1, c0);
    dp[i][1] = min(dp[i-1][0] + dist(p0, c0),
                   dp[i-1][1] + dist(p1, c0))
               + dist(c0, c1);

    p0 = c0;
    p1 = c1;
    ++i;
  }

  cout << min(dp[pts.size()][0], dp[pts.size()][1]) << endl;
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
