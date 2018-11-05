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
  Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
  Edge();
  bool operator > (const Edge &rhs) const {
    return w > rhs.w;
  }
};

int V;
vector<vector<ii>> G;

vector<int> taken;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
vector<vector<int>> H;


void process(int u) {
  taken[u] = 1;
  for (ii &to : G[u]) {
    int v = to.first, w = to.second;
    if (taken[v] == 0) {
      pq.emplace(v, u, w);
    }
  }
}

void prim() {
  taken.assign(V+1, 0);
  process(1);
  while (!pq.empty()) {
    Edge e = pq.top(); pq.pop();
    if (taken[e.u] == 0) {
      H[e.u].push_back(e.v);
      H[e.v].push_back(e.u);
      process(e.u);
    }
  }
}

void Solve() {
  cin >> V;
  G.assign(V+1, vector<ii>());
  H.assign(V+1, vector<int>());
  for (int u = 1; u <= V; ++u) {
    for (int v = u+1; v <= V; ++v) {
      int w;
      cin >> w;
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
  }
  prim();
  for (int u = 1; u <= V; ++u) {
    sort(H[u].begin(), H[u].end());
    cout << H[u].size() << " ";
    for (int v : H[u]) cout << v << " ";
    cout << "\n";
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
