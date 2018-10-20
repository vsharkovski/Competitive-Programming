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
const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}















void Solve() {

  int n;
  cin >> n;

  unordered_map<ll, ll> pfcnt;
  unordered_map<ll, ll> acnt;
  
  vector<ll> v(n);
  bool removed[505];
  
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    v[i] = a;
    removed[i] = true;
    ll p = sqrt(a);
    if (p*p == a) {
      ll pp = sqrt(p);
      if (pp*pp == p) { // a = p^4 (5 divs)
        pfcnt[pp] += 4;
      } else { // a = p^2 (3 divs)
        pfcnt[p] += 2;
      }
    } else {
      p = cbrt((long double)a);
      if (p*p*p == a) { // a = p^3 (4 divs)
        pfcnt[p] += 3;
      } else { // a = pq; for below
        removed[i] = false;
      }
    }
  }

//  dbg(v);
  
  for (int i = 0; i < n; ++i) {
    if (removed[i]) continue;
    ll a = v[i]; //always a=pq
    for (int j = 0; j < n; ++j) {
      ll b = v[j];
      if (a == b) continue;
      ll g = gcd(a, b);
      if (g > 1) {
//        dbg(a, b, g, a/g, b/g, removed[i], removed[j], endl);
        pfcnt[g] += 1;
        if (a > g) pfcnt[a/g] += 1;
        removed[i] = true;
        if (removed[j] == false) { //also b=pq
          pfcnt[g] += 1;
          if (b > g) pfcnt[b/g] += 1;
          removed[j] = true;
        }
        break;
      }
    }
  }
  
  for (int i = 0; i < n; ++i) {
    if (!removed[i]) {
      ++acnt[v[i]];
    }
  }
  
  ll ans = 1;
  for (auto p : pfcnt) {
//    dbg(endl, p.first, p.second);
    ans *= p.second+1;
    ans %= mod;
  }
  for (auto a : acnt) {
//    dbg(endl, a.first, a.second);
    // (#p+1)*(#q+1) = (#a+1)^2
    ans *= (a.second+1);
    ans %= mod;
    ans *= (a.second+1);
    ans %= mod;
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
