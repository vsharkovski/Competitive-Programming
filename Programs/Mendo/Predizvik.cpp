#include <bits/stdc++.h>
 
#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)
 
using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
 
 
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 
 
 
 
 
 
 
 
 
inline bool uslov(ll x, ll y) {
  if (gcd(x, y) > 1) return false;
  ll t = x*x + y*y, z = floor(sqrt(t));
  return z*z == t;
}
 
int n;
vi a; //val, 

// MAXIMUM CARDINALITY BIPARTITE MATCHING

vi g[160]; //i
bitset<160> visited;
vi match;

int Aug(int l) {
  if (visited[l]) return 0;
  visited[l] = 1;
  for (int r : g[l]) {
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l;
      return 1;
    }
  }
  return 0;
}

void Solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (uslov(a[i], a[j])) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  //MCBM
  int mcbm = 0;
  match.assign(n, -1);
  for (int l = 0; l < n; ++l) {
    visited.reset();
    mcbm += Aug(l);
  }
  cout << mcbm << endl;








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








