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
 
 
 
 
 
 

typedef pair<ii, int> iii;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
bool wall[301][301]; 
int dp[301][301][4];

void Solve() {
  cin >> R >> C;
  int pr=0, pc=0, kr=0, kc=0;
  
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      char ch;
      cin >> ch;
      wall[r][c] = ch == '#';
      if (ch == 'P') pr = r, pc = c;
      else if (ch == 'K') kr = r, kc = c;
    }
  }

  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      for (int p = 1; p <= 3; ++p)
        dp[r][c][p] = 1e9;
  
  queue<iii> q;
  q.push(iii(ii(pr, pc), 1));
  dp[pr][pc][1] = 0;
  
  while (!q.empty()) {
    iii topp = q.front(); q.pop();
    int r = topp.first.first, c = topp.first.second, p = topp.second;
    for (int d = 0; d < 4; ++d) {
      int r1 = r, c1 = c, p1 = p==3?1:p+1;
      bool ok = 1;
      for (int i = 0; i < p && ok; ++i) {
        r1 += dr[d], c1 += dc[d];
        if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C || wall[r1][c1]) ok = 0;
      }
      if (ok && dp[r1][c1][p1] == 1e9) {
        dp[r1][c1][p1] = dp[r][c][p] + 1;
        q.push(iii(ii(r1, c1), p1));
      }
    }
  }
 
  int ans = 1e9;
  for (int p = 1; p < 4; ++p) ans = min(ans, dp[kr][kc][p]);
  cout << ans << endl;

/*
  cout << "MINDIST:\n";
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      int best = 1e9;
      for (int p = 1; p <= 3; ++p) best = min(best, dp[r][c][p]);
      cout << setw(2);
      if (best==1e9) cout << '.' << ' '; else cout << best << ' ';
    }
    cout << endl;
  } cout << endl;
  
  cout << "WALL:\n";
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cout << setw(2) << wall[r][c] << ' ';
    }
    cout << endl;
  } cout << endl;
 
  for (int p = 1; p <= 3; ++p) {
    cout << "P=" << p << ":\n";
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        cout << setw(2);
        if (dp[r][c][p]==1e9) cout << '.' << ' '; else cout << dp[r][c][p] << ' ';
      }
      cout << endl;
    } cout << endl;
  }
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
