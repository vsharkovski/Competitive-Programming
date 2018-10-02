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











/*
1) root at x, get sy = size of subtree of y
2) root at y, get sx = size of subtree of x
3) the answer is sx*(n-1-sy) + (n-sx)*(n-1)  (i simplified it below)
i dont know the proof, but if you draw a graph like the following you can try to understand it:
n=6 x=1 y=3
1-6, 1-2, 2-3, 3-4, 3-5
(draw it 2 times, rooted at x and then rooted at y)
*/



int n, x, y;
vector<vi> G;
vi visited;
vi sbtrsz;
int xsz = 0;

int dfs1(int u) {
  visited[u] = 1;
  int sz = 1;
  for (int v : G[u]) {
    if (visited[v] == 0) {
      sz += dfs1(v);
    }
  }
  return sbtrsz[u] = sz;
}

void dfs2(int u, bool underx) {
  visited[u] = 1;
  if (underx) ++xsz;
  for (int v : G[u]) {
    if (visited[v] == 0) {
      dfs2(v, underx || v == x);
    }
  }
}

void Solve() {
  cin >> n >> x >> y;
  G.assign(n+1, vi());
  sbtrsz.assign(n+1, -1);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  visited.assign(n+1, 0);
  dfs1(x);
  visited.assign(n+1, 0);
  dfs2(y, 0);
  ll ans = (ll)n*(ll)n - (ll)n - (ll)xsz*(ll)sbtrsz[y];
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
