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
















int a, m;
bool raining[2002];
ll umbw[2002];
vi umbi[2002]; // site cadori na ova x (indeksi); 0=niedno

ll dp[2002][2002];

ll f(int x, int u) {
  if (raining[x] && u == 0) return 1e13;
  if (x == a) return 0;
  if (dp[x][u] != -1) return dp[x][u];
  
  ll res = f(x+1, 0);
  res = min(res, umbw[u] + f(x+1, u));
  for (int v : umbi[x]) {
    res = min(res, umbw[v] + f(x+1, v));
  }
  return dp[x][u] = res;
}

void Solve() {
  memset(raining, 0, sizeof(raining));  
  int n;
  cin >> a >> n >> m;
  while (n--) {
    int l, r;
    cin >> l >> r;
    ++l; //////////
    while (l <= r) raining[l++] = 1;
  }
  umbw[0] = 0;
  for (int i = 1; i <= m; ++i) {
    int x, p;
    cin >> x >> p;
    umbw[i] = p;
    umbi[x].push_back(i);
  }
  memset(dp, -1LL, sizeof(dp));
  ll ans = f(0, 0);
  if (ans >= 1e13) ans = -1;
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
