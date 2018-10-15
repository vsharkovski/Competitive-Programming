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








int n, m;
int grid[40][40];
bool piece[4][20][20];
bool conf[4][16][20][20];
int idx[4];

void mirx(bool g[20][20]) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n/2; ++j)
      swap(g[i][j], g[i][n-1-j]);
}

void miry(bool g[20][20]) {
  for (int i = 0; i < n/2; ++i)
    for (int j = 0; j < n; ++j)
      swap(g[i][j], g[n-1-i][j]);
}

void rot(bool g[20][20]) {
  for (int i = 0; i < n-1; ++i)
    for (int j = i+1; j < n; ++j)
      swap(g[i][j], g[j][i]);
  mirx(g); //cw => mirx, ccw => miry
}

void makeconfig(int p, int c) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      conf[p][c][i][j] = piece[p][i][j];
}

void print() {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << idx[grid[i][j]] + 1 << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool attempt(bool p0[20][20], bool p1[20][20], bool p2[20][20], bool p3[20][20]) {
  memset(grid, -1, sizeof(grid));
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (p0[i][j]) {
        if (grid[i][j] != -1) return false;
        grid[i][j] = 0;
      }
      if (p1[i][j]) {
        if (grid[i][m-1-j] != -1) return false;
        grid[i][m-1-j] = 1;
      }
      if (p2[i][j]) {
        if (grid[m-1-i][j] != -1) return false;
        grid[m-1-i][j] = 2;
      }
      if (p3[i][j]) {
        if (grid[m-1-i][m-1-j] != -1) return false;
        grid[m-1-i][m-1-j] = 3;
      }
    }
  }
  
  print();
  return true;
}


void Solve() {
  cin >> n;
  m = 2*n-1;
  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        int b;
        cin >> b;
        piece[i][j][k] = b > 0;
      }
    }
    for (int x = 0; x < 2; ++x) {
      for (int y = 0; y < 2; ++y) {
        for (int r = 0; r < 4; ++r) {
          makeconfig(i, x*2*4 + y*4 + r);
          rot(piece[i]);
        }
        miry(piece[i]);
      }
      mirx(piece[i]);
    }
  }
  
  idx[0] = 0; idx[1] = 1; idx[2] = 2; idx[3] = 3;
  
  for (int c0 = 0; c0 < 16; ++c0) {
    for (int c1 = 0; c1 < 16; ++c1) {
      for (int c2 = 0; c2 < 16; ++c2) {
        for (int c3 = 0; c3 < 16; ++c3) {
          do {
            if (attempt(conf[idx[0]][c0], conf[idx[1]][c1], conf[idx[2]][c2], conf[idx[3]][c3])) {
              c0 = c1 = c2 = c3 = 1e9;
              break;
            }
          } while (next_permutation(idx, idx+4));
        }
      }
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
