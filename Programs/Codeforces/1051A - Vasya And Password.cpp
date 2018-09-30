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
const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}









bool good(string &s) {
  int x = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (isdigit(s[i])) x |= 1;
    else if (islower(s[i])) x |= 2;
    else x |= 4;
  }
  return x == 7;
}

void Solve() {

  char opt[3] = {'0', 'a', 'A'};

  int T;
  cin >> T;
  while(T--) {
  
    string s;
    cin >> s;
    
    if (good(s)) {
      cout << s << endl;
      continue;
    }
    
    bool done = 0;
    for (int i = 0; i < s.length() && !done; ++i) {
      char cr = s[i];
      for (int j = 0; j < 3; ++j) {
        s[i] = opt[j];
        if (good(s)) {
          cout << s << endl;
          done = 1;
          break;
        }
      }
      s[i] = cr;
    }
    
    if (done) continue;
    
    if (isdigit(s[2])) {
      s[0] = 'a';
      s[1] = 'A';
      cout << s << endl;
    } else if (islower(s[2])) {
      s[0] = '0';
      s[1] = 'A';
      cout << s << endl;
    } else {
      s[0] = 'a';
      s[1] = '0';
      cout << s << endl;
    }
    
    
  
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
