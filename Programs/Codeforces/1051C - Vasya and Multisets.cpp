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









int n;
int cnt[101];
vi a, res, ids[101];

void assign(int x, bool b) {
//  res[ids[x][cnt[x]-1]] = b;
  for (int i = 0; i < n; ++i) {
    if (a[i] == x && res[i] == -1) {
      res[i] = b;
      break;
    }
  }
  --cnt[x];
}

void Solve() {
  cin >> n;
  
  memset(cnt, 0, sizeof(cnt));
  a.resize(n);
  res.assign(n, -1);
  
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    ++cnt[s];
    a[i] = s;
    ids[s].push_back(i);
  }
  
  int must = 0, can = 0;
  for (int x = 1; x <= 100; ++x) {
    if (cnt[x] == 1) ++must;
    else if (cnt[x] >= 3) ++can;
    else {}
  }

//  dbg(must, can);
  
  if (must % 2 == 1 && can == 0) {
    cout << "NO\n";
    return;
  }

  if (must % 2 == 1) {
    for (int x = 1; x <= 100; ++x) {
      if (cnt[x] == 1) {
        assign(x, 0);
        break;
      }
    }
    for (int x = 1; x <= 100; ++x) {
      if (cnt[x] >= 3) {
        assign(x, 1);
        while (cnt[x]) {
          assign(x, 0);
        }
        break;
      }
    }
    --must;
  }
  
  int num1done = 0;
  for (int x = 1; x <= 100; ++x) {
    if (cnt[x] == 1) {
      bool b = num1done >= must/2;
      assign(x, b);
      ++num1done;
      cnt[x] = 0;
    } else {
      while (cnt[x]) {
        assign(x, 0);
      }
    }
  }
  
//  dbg(must, can, a, res);
  
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    if (res[i]) cout << "B";
    else cout << "A";
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
