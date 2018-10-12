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
 
 
 
 
 
 
 




inline double eucliddistance(double x1, double y1, double x2, double y2) {
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int V;
vector<pair<double, double>> freckles;
vector<vector<pair<int, double>>> G;

vi taken;
priority_queue<pair<double, int>,
               vector<pair<double, int>>,
               greater<pair<double, int>>>
               pq;

void process(int u) {
  taken[u] = 1;
  for (pair<int, double> &v : G[u]) {
    if (!taken[v.first]) {
      pq.emplace(v.second, v.first);
    }
  }
}

double prim() {
  taken.assign(V, 0);
  double mst_cost = 0;
  process(0);
  while (!pq.empty()) {
    pair<double, int> front = pq.top(); pq.pop();
    int u = front.second;
    double w = front.first;
    if (!taken[u]) {
      mst_cost += w;
      process(u);
    }
  }
  return mst_cost;
}

void Solve() {
  int T;
  cin >> T;
  while (T--) {
    
    cin >> V;
    freckles.resize(V);
    G.assign(V, vector<pair<int, double>>());
    
    for (int i = 0; i < V; ++i) {
      double x, y;
      cin >> x >> y;
      freckles[i].first = x;
      freckles[i].second = y;
      for (int j = 0; j < i; ++j) {
        double dist = eucliddistance(x, y, freckles[j].first, freckles[j].second);
        G[j].emplace_back(i, dist);
        G[i].emplace_back(j, dist);
      }
    }
  
    double ans = prim();
    cout << fixed << setprecision(2) << ans << endl;
  
    if (T > 0) cout << endl;
  
  
  
  
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
