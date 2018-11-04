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







const int MINW = 30, MAXW = 90;

void Solve() {

  int n, m, k, r;
  int males[100] = {}, females[100] = {};
  int msum[100] = {}, fsum[100] = {};

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++males[x];
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    ++females[x];
  }
  cin >> r >> k;

  for (int w = MINW; w <= MAXW; ++w) {
    msum[w] = msum[w-1] + males[w];
    fsum[w] = fsum[w-1] + females[w];
  }

  int ans = 0;

  for (int f1 = MINW; f1 <= MAXW; ++f1) {
    if (females[f1] == 0) continue;
    for (int f2 = f1; f2 <= MAXW; ++f2) {
      if (females[f2] == 0) continue;
      int numf = fsum[f2] - fsum[f1-1];
      if (numf < k) continue;
      int numm = msum[min(f1+r, MAXW)] - msum[max(f2-r, MINW)-1];
      ans = max(ans, numm);
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
