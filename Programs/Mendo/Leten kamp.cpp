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
// typedefs
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
// other
#define endl '\n'
#define all(v) begin(v), end(v)
const double EPS = 1e-9;
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}








// idea:
// dijkstra to find all shortest path between important cities (at most 15)
// make graph with these shortest paths
// do traveling salesman on them

int V, E, K;

vii g[40001];

int vazni[20];
int dist[20][40001];
int dist2[20][20];
int dp[20][66000]; // k, 2^k ; kmax=1+15=16

void sssp(int i, int src) {
  dist[i][src] = 0;
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push(ii(0, src));
  while (!pq.empty()) {
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[i][u]) continue;
    for (ii v : g[u]) {
      int potential = dist[i][u] + v.second;
      if (potential < dist[i][v.first]) { //relax.takeiteasy
        dist[i][v.first] = potential;
        pq.push(ii(potential, v.first));
      }
    }
  }
}

int tsp(int pos, int mask) {
  if (mask == (1 << K) - 1) {
    return dist2[pos][0];
  }
  if (dp[pos][mask] != -1) return dp[pos][mask];
  int res = 1e9;
  for (int nxt = 0; nxt < K; ++nxt) {
    if (nxt != pos && ((mask & (1 << nxt)) == 0)) {
      res = min(res, dist2[pos][nxt] + tsp(nxt, mask | (1 << nxt)));
    }
  }
  return dp[pos][mask] = res;
}

void Solve() {
  cin >> V >> K >> E;
  ++K;
  
  vazni[0] = 0;
  for (int i = 1; i < K; ++i) {
    cin >> vazni[i];
  }
  
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(ii(v, w));
    g[v].push_back(ii(u, w));
  }
  
  for (int i = 0; i < K; ++i) {
    for (int u = 0; u < V; ++u) dist[i][u] = 1e9;
    sssp(i, vazni[i]);
  }
  
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      dist2[i][j] = dist[i][vazni[j]];
    }
  }

  for (int i = 0; i < K; ++i) {
    for (int mask = 0; mask < (1<<K); ++mask) {
      dp[i][mask] = -1;
    }
  }
  int ans = tsp(0, 1);
  cout << ans << endl;

  /*
  dbg(V, E, K);
  for (int i = 0; i < K; ++i) {
    for (int j = i+1; j < K; ++j) {
      cout << "(i=" << i << ",u=" << vazni[i] << ") -> (j=" << j << ",v=" << vazni[j] << ") direct:" << dist2[i][j] << " best:" << dp[i][j] << endl;
    }
  }
  
  dbg(dist[0][0], dist[0][1], dp[0][0], dp[0][1]);
  */
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
