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
const int mod = 1000000007;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}











int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int R, C;
char grid[1001][1001];
int dist[1001][1001];

inline bool in(int r, int c) {
  return r >= 0 && r <R && c>=0 && c <C;
}

void Solve() {
  int T;
  cin >> T;
  while (T--) {
  
    cin >> R >> C;
    int sr=0, sc=0, er=0, ec=0;
    
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        cin >> grid[r][c];
        if (grid[r][c] == 'S') {
          sr = r, sc = c;
        } else if (grid[r][c] == 'E') {
          er = r, ec = c;
        }
      }
    }
    
    for (int r = 0; r < R; ++r)
      for (int c = 0; c < C; ++c)
        dist[r][c] = 1e9;
        
    dist[er][ec] = 0;
    queue<ii> q;
    q.push(ii(er, ec));
    while (!q.empty()) {
      int r = q.front().first, c = q.front().second;
      q.pop();
      for (int d = 0; d < 4; ++d) {
        int r1 = r + dr[d], c1 = c + dc[d];
        if (in(r1, c1) && dist[r1][c1] == 1e9 && grid[r1][c1] != 'T') {
          dist[r1][c1] = dist[r][c] + 1;
          q.push(ii(r1, c1));
        }
      }
    }
  
    int hp = 100;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        char ch = grid[r][c];
        if ('0' <= ch && ch <= '9' && dist[r][c] <= dist[sr][sc]) {
          hp -= ch-'0';
        }
      }
    }
    
    cout << max(0, hp) << endl;
  
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
