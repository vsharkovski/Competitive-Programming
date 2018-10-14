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







int N;
int f(int);

inline string b10b3(int x) {
  string s;
  for (int i = 0; i < N; ++i) {
    s += ((x%3)+'0');
    x /= 3;
  }
  reverse(s.begin(), s.end());
  return s;
}

inline int b3b10(string &s) {
  int x = 0;
  for (char ch : s) x = 3*x + (ch-'0');
  for (int m = s.length(); m < N; ++m) x = 3*x;
  return x;
}

int winstate;
int dp[1600000];
int nxtmove[1600000];
int nxtstate[1600000];

inline void update(int state, int i, int state1) {
  int attempt = 1 + f(state1);
  if (attempt < dp[state]) {
    dp[state] = attempt;
    nxtmove[state] = i;
    nxtstate[state] = state1;
  }
}

int f(int state) {
  if (state == winstate) return 0;
  if (dp[state] != -1) return dp[state];
  
  string board = b10b3(state);
  dp[state] = 1e9;
  
  for (int i = 0; i < N; ++i) {
    if (board[i] == '2') {
      if (i+1 < N && board[i+1] == '0') {
        swap(board[i], board[i+1]);
        update(state, i, b3b10(board));
        swap(board[i], board[i+1]);
      }
      else if (i+2 < N && board[i+1] != '0' && board[i+2] == '0') {
        swap(board[i], board[i+2]);
        update(state, i, b3b10(board));
        swap(board[i], board[i+2]);
      }
    }
    else if (board[i] == '1') {
      if (i > 0 && board[i-1] == '0') {
        swap(board[i], board[i-1]);
        update(state, i, b3b10(board));
        swap(board[i], board[i-1]);
      }
      else if (i > 1 && board[i-1] != '0' && board[i-2] == '0') {
        swap(board[i], board[i-2]);
        update(state, i, b3b10(board));
        swap(board[i], board[i-2]);
      }
    }
  }
  
  return dp[state];
}

void Solve() {

  cin >> N;
  
  string pocetok = "";
  int br[3] = {};
  
  for (int i = 0; i < N; ++i) {
    char ch;
    cin >> ch;
    pocetok += ch;
    ++br[int(ch-'0')];
  }
  
  string kraj = "";
  while (br[1]--) kraj += '1';
  while (br[0]--) kraj += '0';
  while (br[2]--) kraj += '2';
  winstate = b3b10(kraj);
  
  memset(dp, -1, sizeof(dp));
  
  int start = b3b10(pocetok);
  int ans = f(start);
  
  cout << ans << endl;

  int state = start;
  for (int i = 0; i < ans; ++i) {
    cout << nxtmove[state]+1 << " ";
    state = nxtstate[state];
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
