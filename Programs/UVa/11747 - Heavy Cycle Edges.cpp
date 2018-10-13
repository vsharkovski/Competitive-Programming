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
 
 
 
 
 
 
 



struct Edge {
  int u, v, w;
  Edge(int U, int V, int W) : u(U), v(V), w(W) {}
  Edge() {}
  bool operator < (const Edge &rhs) const {
    return w < rhs.w;
  }
};

int V, E;
vector<vii> G;
vector<Edge> edges;

bool inmst[1001][1001];
vi taken;
priority_queue<Edge, vector<Edge>> pq;

void process(int u) {
  taken[u] = 1;
  for (ii &v : G[u]) {
    if (!taken[v.first]) {
      pq.emplace(u, v.first, -v.second);
    }
  }
}

void prim(int src) {
  process(src);
  Edge te;
  while (!pq.empty()) {
    te = pq.top(); pq.pop();
    if (!taken[te.v]) {
      inmst[te.u][te.v] = inmst[te.v][te.u] = 1;
      process(te.v);
    }
  }
}


void Solve() {
  while (cin >> V >> E, V != 0 || E != 0) {
    
    G.assign(V, vii());
    edges.clear();
    memset(inmst, 0, sizeof(inmst));
    taken.assign(V, 0);
    
    for (int i = 0; i < E; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.emplace_back(u, v, w);
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
  
    for (int u = 0; u < V; ++u) {
      if (!taken[u]) {
        prim(u);
      }
    }
    
    sort(all(edges));
    bool printed = 0;
    
    for (Edge &e : edges) {
      if (!inmst[e.u][e.v]) {
        if (printed) cout << ' ';
        printed = 1;
        cout << e.w;
      }
    }
    if (!printed) cout << "forest";
    cout << endl;
    
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
