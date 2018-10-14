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
 
 
 
 
 
 
 



void Solve() {
  
  vi pomalo, pogolemo;
  vi temp(12), both(12);
  
  for (int x = 1; x <= 12; ++x) {
    pomalo.push_back(x);
    pogolemo.push_back(x);
  }
  
  for (int i = 0; i < 3; ++i) {
    vi v1(4), v2(4);
    char sign;
    for (int j = 0; j < 4; ++j) cin >> v1[j];
    cin >> sign;
    for (int j = 0; j < 4; ++j) cin >> v2[j];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    if (sign != '=') {
      if (sign == '>') swap(v1, v2);
      pomalo   = vi(temp.begin(),
                    set_intersection(pomalo.begin(), pomalo.end(), v1.begin(), v1.end(), temp.begin()));
      pogolemo = vi(temp.begin(),
                    set_intersection(pogolemo.begin(), pogolemo.end(), v2.begin(), v2.end(), temp.begin()));
    } else { // =
      set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), both.begin());
      sort(both.begin(), both.end());
      pomalo   = vi(temp.begin(),
                    set_difference(pomalo.begin(), pomalo.end(), both.begin(), both.end(), temp.begin()));
      pogolemo = vi(temp.begin(),
                    set_difference(pogolemo.begin(), pogolemo.end(), both.begin(), both.end(), temp.begin()));
     }
  }
  
  if (pomalo.size() + pogolemo.size() == 0) {
    cout << "impossible\n";
  } else if (pomalo.size() + pogolemo.size() >= 2) {
    cout << "indefinite\n";
  } else if (pomalo.size() > 0) {
    cout << pomalo[0] << "-\n";
  } else {
    cout << pogolemo[0] << "+\n";
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
