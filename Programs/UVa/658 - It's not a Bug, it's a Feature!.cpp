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








int n, m;
int t[101];  // time to apply
int bp[101]; // bugs needed to be present to apply
int bm[101]; // bugs needed to be absent to apply
int fp[101]; // new bugs introduced
int fm[101]; // bugs removed

int dist[1<<20];
priority_queue<ii, vii, less<ii>> pq;

void dijkstra() {
  for (int msk = 0; msk < (1 << n); ++msk) dist[msk] = 1e9;
  dist[(1<<n) - 1] = 0;
  pq.emplace(0, (1<<n) - 1);
  while (!pq.empty()) {
    ii ts = pq.top(); pq.pop();
    int d = ts.first, msk = ts.second;
    if (d > dist[msk]) continue;
    for (int i = 0; i < m; ++i) {
      if ((msk & bp[i]) == bp[i] && (msk & bm[i]) == 0) {
        int msk1 = (msk | fp[i]) & ~fm[i];
        if (d + t[i] < dist[msk1]) {
          dist[msk1] = d + t[i];
          pq.emplace(dist[msk1], msk1);
        }
      }
    }
  }
}

void Solve() {
  int TC = 1;
  while (cin >> n >> m, n != 0 && m != 0) {
    for (int i = 0; i < m; ++i) {
      cin >> t[i];
      string a, b;
      cin >> a >> b;
      bp[i] = bm[i] = fp[i] = fm[i] = 0;
      for (int j = 0; j < n; ++j)
        if (a[j] == '+')
          bp[i] |= (1 << (n-j-1));
        else if (a[j] == '-')
          bm[i] |= (1 << (n-j-1));
      for (int j = 0; j < n; ++j)
        if (b[j] == '+')
          fp[i] |= (1 << (n-j-1));
        else if (b[j] == '-')
          fm[i] |= (1 << (n-j-1));
    }
    dijkstra();
    cout << "Product " << TC++ << "\n";
    if (dist[0] != 1e9) {
      cout << "Fastest sequence takes " << dist[0] << " seconds.\n";
    } else {
      cout << "Bugs cannot be fixed.\n";
    }
    cout << "\n";
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
