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
 
 
 
 
 
 
 

int n;
string a, b;

bool found;
bool taken[65];
string c;

void bf1(int i, bool gomax) { // za pomal
  if (found) return;
  if (i == n) {
    if (c != a) found = 1;
    return;
  }
  if (gomax) { // a[0...i-1] > b[0...i-1]
    int fj = -1;
    for (int j = 0; j < n; ++j) {
      if (!taken[j] && (fj == -1 || b[j] > b[fj])) {
        fj = j;
      }
    }
    if (fj != -1) {
      c[i] = b[fj];
      taken[fj] = 1;
      bf1(i+1, true);
      taken[fj] = 0;
    }
  } else { // a[0...i-1] = b[0...i-1]
    int fj = -1;
    for (int j = 0; j < n; ++j) {
      if (!taken[j]) {
        if (b[j] == a[i]) { // continue the tradition
          c[i] = b[j];
          taken[j] = 1;
          bf1(i+1, false);
          taken[j] = 0;
        } else if (b[j] < a[i] && (fj == -1 || b[j] > b[fj]) && (i != 0 || b[j] > '0')) {
          fj = j;
        }
      }
    }
    if (!found && fj != -1) { // couldn't continue the tradition
      c[i] = b[fj];
      taken[fj] = 1;
      bf1(i+1, true);
      taken[fj] = 0;
    }
  }
}

void bf2(int i, bool gomin) { // za pogolem
  if (found) return;
  if (i == n) {
    found = 1;
    return;
  }
  if (gomin) { // a[0...i-1] < b[0...i-1]
    int fj = -1;
    for (int j = 0; j < n; ++j) {
      if (!taken[j] && (fj == -1 || b[j] < b[fj])) {
        fj = j;
      }
    }
    if (fj != -1) {
      c[i] = b[fj];
      taken[fj] = 1;
      bf2(i+1, true);
      taken[fj] = 0;
    }
  } else { // a[0...i-1] = b[0...i-1]
    int fj = -1;
    for (int j = 0; j < n; ++j) {
      if (!taken[j]) {
        if (b[j] == a[i]) { // continue the tradition
          c[i] = b[j];
          taken[j] = 1;
          bf2(i+1, false);
          taken[j] = 0;
        } else if (b[j] > a[i] && (fj == -1 || b[j] < b[fj])) {
          fj = j;
        }
      }
    }
    if (!found && fj != -1) { // couldn't continue the tradition
      c[i] = b[fj];
      taken[fj] = 1;
      bf2(i+1, true);
      taken[fj] = 0;
    }
  }
}

void Solve() {
  cin >> a >> b;
  n = a.length();
  
  c.assign(n, '.');
  memset(taken, 0, sizeof(taken));
  found = 0;
  bf2(0, false);
  if (found) cout << c << "\n";
  else cout << "0\n";
  
  c.assign(n, '.');
  memset(taken, 0, sizeof(taken));
  found = 0;
  bf1(0, false);
  if (found) cout << c << "\n";
  else cout << "0\n";













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
