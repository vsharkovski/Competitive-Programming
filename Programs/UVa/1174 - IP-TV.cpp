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
/*
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
#endif*/
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
 
 
 
 
 
 
 

unordered_map<string, int> strtoidx;
int curridx = 0;
int getidx(string &s) {
  if (strtoidx.count(s)) return strtoidx[s];
  strtoidx[s] = curridx++;
  return curridx-1;
}

int V, E;
vector<vii> G;

int prim() {
  bitset<2005> taken;
  priority_queue<ii> pq;
  int mst_cost = 0;
  
  taken[0] = 1;
  for (ii &v : G[0])
    if (!taken[v.first])
      pq.emplace(-v.second, -v.first);
      
  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int u = -front.second, w = -front.first;
    if (!taken[u]) {
      mst_cost += w;
      taken[u] = 1;
      for (ii &v : G[u])
        if (!taken[v.first])
          pq.emplace(-v.second, -v.first);
    }
  }
  return mst_cost;
}


void Solve() {
  int T;
  cin >> T;
  while (T--) {
    cin >> V >> E;
    strtoidx.clear();
    curridx = 0;
    G.assign(V, vii());
    for (int i = 0; i < E; ++i) {
      string a, b;
      int d;
      cin >> a >> b >> d;
      int x = getidx(a), y = getidx(b);
      G[x].emplace_back(y, d);
      G[y].emplace_back(x, d);
    }
    int ans = prim();
    cout << ans << endl;
    if (T > 0) cout << "\n";
  
  
  
  
  
  
  
  
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
