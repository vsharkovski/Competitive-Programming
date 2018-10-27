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









int R, C;
bool light[5][5];
bool pattern[3][3];
bool pressed[25];
bool done;

inline bool in(int r, int c) {
  return r >= 0 && r <R && c >= 0 && c < C;
}

void flip(int x) {
  int r = x/C, c = x%C;
  for (int i = -1; i <= 1; ++i)
    for (int j = -1; j <= 1; ++j)
      if (in(r+i, c+j) && pattern[i+1][j+1])
        light[r+i][c+j] ^= 1;
}


void bf(int i) {
  if (done) return;
  if (i == R*C) {
    for (int r = 0; r < R; ++r)
      for (int c = 0; c < C; ++c)
        if (light[r][c] == 0)
          return;
    done = 1;
    return;
  }
  int r = i/C, c = i%C;
  pressed[i] = 0;
  bf(i+1);
  if (done) return;
  pressed[i] = 1;
  flip(i);
  if (r == 0 || c == 0 || light[r-1][c-1] == 1) {
    bf(i+1);
  }
  flip(i);
}

void Solve() {
  int CT = 1;
  while (cin >> R >> C, R + C > 0) {
    for (int r = 0; r < 3; ++r) {
      for (int c = 0; c < 3; ++c){
        char ch;
        cin >> ch;
        pattern[r][c] = ch == '*';
      }
    }
    memset(light, 0, sizeof(light));
    memset(pressed ,0, sizeof(pressed));
    done = 0;
    bf(0);
    cout << "Case #" << CT++ << "\n";
    if (done) {
      bool printed = 0;
      for (int i = 0; i < R*C; ++i)  {
        if (pressed[i]) {
          if (printed) cout << " ";
          printed = 1;
          cout << i+1;
        }
      }
      cout << endl;
    } else {
      cout << "Impossible.\n";
    }
  }














}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
//  std::freopen("in.txt", "r", stdin);
//  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
