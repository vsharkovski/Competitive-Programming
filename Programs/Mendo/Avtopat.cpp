#include <bits/stdc++.h>
  
#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)
  
using namespace std;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
  
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
  
 
 
// 19825
 
typedef pair<int, ll> ill;
const ll INF = 1e18;
 
int t1, t2, k, n;
 
vector<vector<ill>> g;
vector<ll> dist;
 
void dfs(int u) {
  for (ii v : g[u]) {
    if (dist[v.first] == -INF) {
      dist[v.first] = dist[u] + v.second;
      dfs(v.first);
    }
  }
}
 
void Solve() {
  cin >> t1 >> t2 >> k >> n;
   
  g.resize(k+1);
  for (int i = 0; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u > v) swap(u, v);
    g[u].push_back(ill(v, w));
    g[v].push_back(ill(u, -w));
  }
 
  dist.assign(k+1, -INF);
  dist[t1] = 0;
  dfs(t1);
   
  if (dist[t2] == -INF) cout << -1 << endl;
  else cout << abs(dist[t2]) << endl;
 
 
 
 
 
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
