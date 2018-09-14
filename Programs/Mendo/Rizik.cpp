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
 






int n, p, ans = 0;
vi g[100010];
int status[100010];

void dfs(int u, bool first) {
  if (p == 0 || (!first && status[u] != -1)) return;
  if (!first) {
    status[u] = 1;
    ++ans;
    --p;
  }
  for (int v : g[u]) {
    dfs(v, false);
  }
}

void Solve() {
  int b1, b2, m;
  cin >> n >> b1 >> b2 >> p;
  memset(status, -1, sizeof(status));
  vi kosta;
  for (int i = 0; i < b1; ++i) {
    int u;
    cin >> u;
    --u;
    status[u] = 1;
    kosta.push_back(u);
  }
  for (int i = 0; i < b2; ++i) {
    int u;
    cin >> u;
    --u;
    status[u] = 2;
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < b1 && p > 0; ++i) {
    dfs(kosta[i], true);
  }
  cout << ans << endl;
//  for (int u = 0; u < n; ++u) {
//    cout << "status[" << u+1 << "]=" << status[u] << endl;
//  }










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








