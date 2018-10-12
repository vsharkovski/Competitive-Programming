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
 
 
 
 
 
 
 


int dist(int x, int y) {
  int res = 0;
//  cout << "{dist( " << x << ", " << y << " ) = ";
  for (int i = 0; i < 4; ++i) {
    int a = x % 10, b = y % 10;
    res += min({abs(a - b), abs(a+10 - b), abs(a - (b+10))});
    x /= 10, y /= 10;
  }
//  cout << res << "}\n";
  return res;
}

int V = 10000;
vector<vii> G;

vi taken;
priority_queue<ii, vii> pq;

void process(int u) {
  taken[u] = 1;
  for (ii &v : G[u])
    if (!taken[v.first])
      pq.emplace(-v.second, -v.first);
}

int prim(int src) {
  taken.assign(V, 0);
  int mst_cost = dist(0, src); // initially going from 0 to src, but 0 is not part of MST (see below)
  process(src);
  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int u = -front.second, w = -front.first;
    if (!taken[u]) {
      mst_cost += w;
//      cout << " took " << u << " with cost=" << w << endl;
      process(u);
    }
  }
  return mst_cost;
}

void Solve() {
  int T;
  cin >> T;
  
  while (T--) {
    G.assign(10000, vii());
    
    int N;
    cin >> N;
    
    vi keys(N);
    
    // because 0 is not part of MST, but we "start" from 0,
    // we need to find node u such that weight of edge (0, u) is minimal
    // and start MST from there
    int minw = 1e9, src = -1;
    
    for (int i = 0; i < N; ++i) {
      cin >> keys[i];
      for (int j = 0; j < i; ++j) {
        int d = dist(keys[i], keys[j]);
        G[keys[j]].emplace_back(keys[i], d);
        G[keys[i]].emplace_back(keys[j], d);
      }
      int d0 = dist(0, keys[i]);
      if (d0 < minw) {
        minw = d0;
        src = keys[i];
      }
    }
    
    int ans = prim(src);
    cout << ans << endl;
  
  
  
  
  
  
  
  
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
