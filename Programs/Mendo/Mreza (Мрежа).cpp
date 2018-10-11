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
//const ll mod = 1e9 + 7;
//template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
//template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 
 
 
 
 
 
 
 
 

 
int r[33000];
int c[33000];
int d[33000]; //reverse c
 
// p1 i p3 se dole, p2 e gore
bool triagolnik(int p1, int p2, int p3) {
  return r[p1] == r[p3] &&
         c[p2] == c[p1] &&
         c[p3] - c[p1] == r[p1] - r[p2];
}
 
bool paralelogram(int p1, int p2, int p3, int p4) {
  return // tradicionalen romb (p1 i p2 gore, p3 i p4 dole)
         (r[p1] == r[p2] &&
          r[p3] == r[p4] &&
        ((c[p1] == c[p3] && c[p2] == c[p4]) || (d[p2] == d[p4] && d[p1] == d[p3])) &&
          r[p1] - r[p3] == c[p2] - c[p1]) ||
         // svrten kako dijamant (pocni levo, clockwise)
         (r[p1] == r[p3] &&
          c[p1] == c[p2] &&
          c[p4] == c[p3] &&
          r[p1] - r[p2] == r[p4] - r[p1]);
}
 
// pocni od najlevoto teme i odi clockwise
bool sestoagolnik(int p1, int p2, int p3, int p4, int p5, int p6) {
  return r[p2] == r[p3] &&
         r[p1] == r[p4] &&
         r[p6] == r[p5] &&
         c[p2] == c[p1] &&
         c[p4] == c[p5] &&
         d[p3] == d[p4] &&
         d[p1] == d[p6] &&
         c[p3] - c[p2] == c[p5] - c[p6] &&
         r[p6] - r[p1] == r[p1] - r[p2] &&
         r[p1] - r[p2] == c[p3] - c[p2];
}
 
void Solve() {
 
  int x = 1;
  for (int row = 1; x < 33000; ++row) {
//    for (int i = 0; i < 14-row; ++i) cout << "   ";
    for (int col = 1; col <= row && x < 33000; ++col) {
      r[x] = row;
      c[x] = col;
      d[x] = row - col;
//      if (x < 107) cout << setw(5) << x << " ";
      ++x;
    }
//    if (x < 107) cout << endl;
  }
//  cout << endl;
 
  int N;
  cin >> N;
  while (N--) {
    int sz;
    cin >> sz;
     
    vi p(sz);
    for (int i = 0; i < sz; ++i) cin >> p[i];
    sort(all(p));
     
//    dbg(p);
     
    bool done = 0;
    if (sz == 3) {
      do {
        if (triagolnik(p[0], p[1], p[2])) {
          cout << "TRIAGOLNIK\n";
          done = 1;
        }
      } while (!done && next_permutation(all(p)));
    } else if (sz == 4) {
      do {
        if (paralelogram(p[0], p[1], p[2], p[3])) {
          cout << "PARALELOGRAM\n";
          done = 1;
        }
      } while (!done && next_permutation(all(p)));
    } else if (sz == 6) {
      do {
        if (sestoagolnik(p[0], p[1], p[2], p[3], p[4], p[5])) {
          cout << "SESTOAGOLNIK\n";
          done = 1;
        }
      } while (!done && next_permutation(all(p)));
    }
    if (!done) cout << "NISTO\n";
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
