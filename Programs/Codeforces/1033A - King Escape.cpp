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
const int mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}


















void Solve() {

  int n, ax, ay, bx, by, cx, cy;
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  --ax, --ay, --bx, --by, --cx, --cy;

  int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
  
  bool visited[1001][1001] = {};
  
  for (int x = ax; x >= 0; --x) visited[x][ay] = 1;
  for (int x = ax; x <  n; ++x) visited[x][ay] = 1;
  for (int y = ay; y >= 0; --y) visited[ax][y] = 1;
  for (int y = ay; y <  n; ++y) visited[ax][y] = 1;
  for (int x = ax, y = ay; x >= 0 && y >= 0; --x, --y) visited[x][y] = 1;
  for (int x = ax, y = ay; x  < n && y  < n; ++x, ++y) visited[x][y] = 1;
  for (int x = ax, y = ay; x >= 0 && y  < n; --x, ++y) visited[x][y] = 1;
  for (int x = ax, y = ay; x  < n && y >= 0; ++x, --y) visited[x][y] = 1;
  
  queue<ii> q;
  q.emplace(bx, by);
  visited[bx][by] = 1;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int d = 0; d < 8; ++d) {
      int x1 = x + dx[d], y1 = y + dy[d];
      if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && !visited[x1][y1]) {
        visited[x1][y1] = 1;
        q.emplace(x1, y1);
      }
    }
  }

  if (visited[cx][cy]) cout << "YES";
  else cout << "NO";










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
