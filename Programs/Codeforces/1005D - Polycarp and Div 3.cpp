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





int n;
int a[200010];

int dp[200010][3][2];
//bool nxt[200010][3][2];

int F(int i, int m, bool nov) {
  if (i == n) return m == 0;
  if (dp[i][m][nov] != -1) return dp[i][m][nov];
  if (a[i] == 0 && nov) {
//    nxt[i][m][nov] = 1;
    return dp[i][m][nov] = (m % 3 == 0) + F(i+1, 0, true);
  } else {
    int o1 = F(i+1, (m+a[i]) % 3, false);
    int o2 = (m % 3 == 0) + F(i+1, a[i], true);
//    nxt[i][m][nov] = !(o1 > o2);
    return dp[i][m][nov] = max(o1, o2);
  }
}

void Solve() {
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; ++i) {
    a[i] = (s[i]-'0') % 3;
  }
  memset(dp, -1, sizeof(dp));
  int ans = F(1, a[0], false);
  cout << ans << endl;
//
//  cout << endl;
//  bool nov = 0, m = a[0];
//  cout << a[0];
//  for (int i = 1; i < n; ++i) {
//    if (nxt[i][m][nov]) {
//      cout << "|";
//      m = a[i];
//    } else {
//      m = (m + a[i]) % 3;
//    }
//    cout << a[i];
//  }
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
