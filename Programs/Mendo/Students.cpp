#include <bits/stdc++.h>
using namespace std;
// printing
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _dbg(_it, args); }
void _dbg(istream_iterator<string> it) {++it;}
template<typename T, typename... Args>
void _dbg(istream_iterator<string> it, T a, Args... args) { cout << setw(8) << std::left << *it << " = " << setw(4) << std::right << a << "\n"; _dbg(++it, args...);}
template<typename T>
ostream& _containerprint(ostream &out, T const &val) {return (out << setw(4) << std::right << val << " ");}
template<typename T1, typename T2>
ostream& _containerprint(ostream &out, pair<T1, T2> const &val) {return (out << "{" << val.first << " " << val.second << "} ");}
template<template<typename, typename...> class TT, typename... Args>
ostream& operator<<(ostream &out, TT<Args...> const &cont) {for(auto&& elem : cont) { _containerprint(out, elem); } return out;}
// typedefs
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
// other
#define endl '\n'
#define all(v) begin(v), end(v)
const double EPS = 1e-9;
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






void Solve() {
  int T;
  cin >> T;
  while (T--) {
  
    int n, m;
    
    int suma = 0, sumb = 0;
    double avga, avgb;
    
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      suma += a[i];
    }
    
    cin >> m;
    vi b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
      sumb += b[i];
    }
    
    avga = double(suma) / double(n);
    avgb = double(sumb) / double(m);
    
    int cnt = 0;
    
//    dbg(n, m, suma, sumb, avga, avgb, '\n');
    
    for (int i = 0; i < n; ++i) {
      double ta = double(suma - a[i]) / double(n-1);
      double tb = double(sumb + a[i]) / double(m+1);
//      dbg(ta, tb, '\n');
      if (ta > avga && tb > avgb) {
        ++cnt;
      }
    }
    for (int i = 0; i < m; ++i) {
      double tb = double(sumb - b[i]) / double(m-1);
      double ta = double(suma + b[i]) / double(n+1);
//      dbg(ta, tb, '\n');
      if (ta > avga && tb > avgb) {
        ++cnt;
      }
    }
  
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
