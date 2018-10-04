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











int R, C;
int B, N;

int dp[10][51][51];

int ways(int i, int r, int c) {
  if (i == N) return r*c >= B;
  if (dp[i][r][c] != -1) return dp[i][r][c];
  int ans = 0;
  for (int r1 = 1; r1 < r; ++r1) {
    if (r1*c >= B) {
      ans += ways(i+1, r-r1, c);
      ans %= mod;
      if ((r-r1)*c >= B) {
        ans += ways(i+1, r1, c);
        ans %= mod;
      }
    }
  }
  for (int c1 = 1; c1 < c; ++c1) {
    if (r*c1 >= B) {
      ans += ways(i+1, r, c-c1);
      ans %= mod;
      if (r*(c-c1) >= B) {
        ans += ways(i+1, r, c1);
        ans %= mod;
      }
    }
  }
  return dp[i][r][c] = ans;
}

void Solve() {
  int T;
  cin >> T;
  while (T--) {
  
    cin >> R >> C >> B >> N;
    memset(dp, -1, sizeof(dp));

    int ans = ways(1, R, C);
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
