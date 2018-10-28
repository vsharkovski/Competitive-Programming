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








int N;
int G[101][101];

int bfs(int s1, int s2, int target) {
  int dist[101][101];
  memset(dist, -1, sizeof(dist));
  dist[s1][s2] = 0;
  queue<ii> q;
  q.emplace(s1, s2);
  while (!q.empty()) {
    s1 = q.front().first, s2 = q.front().second;
    q.pop();
    if (s1 == target || s2 == target)
      return dist[s1][s2];
    for (int c = 1; c <= N; ++c) {
      int i = G[s1][c];
      if (i != 0 && c == s2 && dist[i][s2] == -1) {
        dist[i][s2] = dist[s1][s2] + 1;
        q.emplace(i, s2);
      }
      i = G[s2][c];
      if (i != 0 && c == s1 && dist[s1][i] == -1) {
        dist[s1][i] = dist[s1][s2] + 1;
        q.emplace(s1, i);
      }
    }
  }
  return -1;
}

void Solve() {
  int CT = 1;
  while (cin >> N, N != 0) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        cin >> G[i][j];
      }
    }
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int res = bfs(n1, n2, n3);

    cout << "Game #" << CT++ << "\n";
    if (res == -1) cout << "Destination is Not Reachable !\n\n";
    else cout << "Minimum Number of Moves = " << res << "\n\n";
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
