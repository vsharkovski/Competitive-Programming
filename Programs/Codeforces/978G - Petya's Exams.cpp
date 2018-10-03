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




















int n, m;
int s[101], d[101], c[101];
vii line[101];
  
struct Comp {
  bool operator()(int i, int j) {
    return d[i] > d[j];
  }
};

void Solve() {

  cin >> n >> m;
  
  for (int i = 1; i <= n; ++i) {
    cin >> s[i] >> d[i] >> c[i];
    line[s[i]].push_back(ii(i, 1));
    line[d[i]].push_back(ii(i, 2));
  }
  
  vi ans;
  
  int progress[101] = {};
  priority_queue<int, vi, Comp> priority;
  
  for (int t = 1; t <= n; ++t) {
//    cout << "t=" << t << endl;
    bool acted = 0;
    
    for (ii &p : line[t]) {
      if (p.second == 1) {
//        cout << "ADDING " << p.first << " TO LIST\n";
        priority.push(p.first);
      } else if (p.second == 2) {
        if (progress[p.first] < c[p.first]) {
//          cout << "IMPOSSIBLE\n";
//          dbg(t, p.first, p.second, progress[p.first]);
          cout << -1; return;
        } else {
//          cout << "TAKING EXAM\n";
          ans.push_back(m+1);
          acted = 1;
        }
      }
    }
    
    if (acted) continue;
    if (priority.empty()) {
      ans.push_back(0);
//      cout << "SLEEPING\n";
    } else {
      int nxt = priority.top();
      ans.push_back(nxt);
      ++progress[nxt];
//      cout << "STUDYING " << nxt << " ; NOW = " << progress[nxt] << " ; NEED = " << c[nxt] << endl;
      if (progress[nxt] == c[nxt]) {
        priority.pop();
//        cout << "POPPED " << nxt << endl;
      }
    }
  
  }

  for (int x : ans) cout << x << " ";











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
