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
const int mod = 1e9+7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}





const int OFS = 3000;

int n;
int num[32];
int sgn[32];

bool used[6100];
bool visited[32][32][6100];

void F(int i, int p, int x) {
  if (visited[i][p][OFS+x]) return;
  visited[i][p][OFS+x] = 1;
  if (i == n) {
    used[OFS+x] = 1;
    return;
  }
  x += num[i] * sgn[i] * (p % 2 == 0 ? 1 : -1);
  F(i+1, p, x);
  if (sgn[i] == -1) F(i+1, p+1, x);
  if (p > 0)        F(i+1, p-1, x);
}

void Solve() {
  stringstream ss;
  string line;
  char ch;
  int val;
  while (getline(cin, line)) {
    ss.clear();
    ss << line;
    ss >> val;
    num[0] = val;
    sgn[0] = 1;
    n = 1;
    while (ss >> ch >> val) {
      sgn[n] = ch == '+' ? 1 : -1;
      num[n] = val;
      ++n;
    }
    memset(used, 0, sizeof(used));
    memset(visited, 0, sizeof(visited));
    F(0, 0, 0);
    int cnt = 0;
    for (int x = -3000; x <= 3000; ++x)
      if (used[OFS+x]) ++cnt;
    cout << cnt << endl;
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
