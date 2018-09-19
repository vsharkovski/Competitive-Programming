#include <bits/stdc++.h>
using namespace std;
// printing
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _dbg(_it, args); }
void _dbg(istream_iterator<string> it){++it;}
template<typename T, typename... Args>
void _dbg(istream_iterator<string> it, T a, Args... args){
  if(*it=="'\\n'" || *it=="\"\\n\"" || *it=="endl"){ cout << "\n";}
  else{ cout << setw(8) << std::left << *it << " = " << setw(4) << std::right << a << "\n";}
  _dbg(++it, args...);}
template<typename T>
ostream& _containerprint(ostream &out, T const &val){ return (out << setw(4) << std::right << val << " ");}
template<typename T1, typename T2>
ostream& _containerprint(ostream &out, pair<T1, T2> const &val){ return (out << "{" << val.first << " " << val.second << "} ");}
template<template<typename, typename...> class TT, typename... Args>
ostream& operator<<(ostream &out, TT<Args...> const &cont){ for(auto&& elem : cont) { _containerprint(out, elem); } return out;}
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






// ids: 0 to n-1

int n;
vi rating, parent;
vi g[5001];

vi opt1, opt2;

void Solve() {

  cin >> n;
  
  rating.resize(n);
  parent.assign(n, -1);
  opt1.assign(n, -1);
  opt2.assign(n, -1);
  
  cin >> rating[0];
  for (int u = 1; u < n; ++u) {
    cin >> rating[u] >> parent[u];
    g[parent[u]].push_back(u);
  }
  
  vi bfsorder;
  queue<int> q;
  vector<bool> visited(n, 0);
  q.push(0);
  visited[0] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    bfsorder.push_back(u);
    for (int v : g[u]) {
      if (visited[v] == 0) {
        visited[v] = 1;
        q.push(v);
      }
    }
  }

  for (int i = n-1; i >= 0; --i) {
    int u = bfsorder[i];
    
    opt1[u] = rating[u]; // zemaj
    opt2[u] = 0; // ne zemaj
    
    for (int v : g[u]) {
      opt1[u] += opt2[v];
      opt2[u] += max(opt1[v], opt2[v]); // ponekogas se isplati da ne se zeme iako moze
    }
      
  }
  
//  dbg(bfsorder, opt1, opt2, endl);
  
  cout << max(opt1[0], opt2[0]) << endl;







  
  
  
  
  
  
  
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
