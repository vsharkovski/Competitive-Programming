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












// Od na mendo naprevarot "Podgotovki za JBOI 2013 (2)"
// ja resiv ne znaejki deka ne moze da se submitne
// mislam deka mi e tocno so 95% sigurnost
// ako imate kontraprimer slobodno pratete






void Solve() {

  int chtoi[200];
  int I = 0;
  for (char ch = 'A'; ch <= 'Z'; ++ch) {
    chtoi[(int)ch] = I;
    ++I;
  }
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    chtoi[(int)ch] = I;
    ++I;
  }

  int m, n;
  cin >> m >> n;
  
  string b, a;
  cin >> b >> a;
  
  if (m > n) {
    cout << 0;
    return;
  }
  
  int optimalcnt[60] = {};
  long long optimalmask = 0;
  
  for (int i = 0; i < m; ++i) {
    int d = chtoi[(int)b[i]];
    ++optimalcnt[d];
    optimalmask |= (1 << d);
  }
  
  int ans = 0;
  int cnt[60] = {};
  long long mask = 0;
  
  for (int i = 0; i < n; ++i) {
    int d = chtoi[(int)a[i]];
    ++cnt[d];
    if (cnt[d] >= optimalcnt[d]) {
      mask |= (1 << d);
    }
    if (i >= m) {
      int g = chtoi[(int)a[i-m]];
      --cnt[g];
      if (cnt[g] < optimalcnt[g]) {
        mask &= ~(1 << g);
      }
    }
    if ((mask & optimalmask) == optimalmask) {
      ++ans;
    }
  }
  
  cout << ans << endl;




















  
  

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
