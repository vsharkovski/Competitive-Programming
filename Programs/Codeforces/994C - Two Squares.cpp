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
//template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






const int OFS = 100;
int grid[205][205];

void draw1(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  for (int y = y1; y <= y2; ++y)
    for (int x = x1; x <= x4; ++x)
      grid[OFS+y][OFS+x]++;
}

void draw2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  for (int d = 0; d <= x4-x1; ++d) {
    for (int x = x1+d, y = y1-d; x <= x2+d; ++x, ++y) {
      grid[OFS+y][OFS+x]++;
      if (y < y2 && x < x2+d) {
        grid[OFS+y][OFS+x+1]++;
      }
    }
  }
}

void Solve() {
  memset(grid, 0, sizeof(grid));
  ii c[4];

  for (int i = 0; i < 4; ++i)
    cin >> c[i].first >> c[i].second;
  sort(c, c+4, [&](ii &a, ii &b){
    return a.first == b.first ? a.second < b.second : a.first < b.first;});
  sort(c+2, c+4, [&](ii &a, ii &b){
    return a.second > b.second;});
  draw1(c[0].first, c[0].second, c[1].first, c[1].second, c[2].first, c[2].second, c[3].first, c[3].second);

  for (int i = 0; i < 4; ++i)
    cin >> c[i].first >> c[i].second;
  sort(c, c+4, [&](ii &a, ii &b){
    return a.first == b.first ? a.second > b.second : a.first < b.first;});
  sort(c+2, c+4, [&](ii &a, ii &b){
    return a.first == b.first ? a.second > b.second : a.first > b.first;});
  draw2(c[0].first, c[0].second, c[1].first, c[1].second, c[2].first, c[2].second, c[3].first, c[3].second);

  for (int x = -100; x <= 100; ++x) {
    for (int y = -100; y <= 100; ++y) {
      if (grid[OFS+y][OFS+x] > 1) {
        cout << "Yes\n";
        return;
      }
    }
  }

  cout << "No\n";
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
