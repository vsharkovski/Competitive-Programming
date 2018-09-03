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






void Solve() {

  int n;
  cin >> n;
  vector<vi> g(n+1);
  
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  vi seq(n+1), pos(n+1);
  
  for (int i = 0; i < n; ++i) {
    int u;
    cin >> u;
    seq[i] = u;
    pos[u] = i;
  }
  
  for (int u = 1; u <= n; ++u) {
    sort(all(g[u]), [&](int a, int b) {
      return pos[a] < pos[b];
    });
//    cout << u << ": ";
//    for (int v : g[u]) cout << v << " ";
//    cout << endl;
  }
  
  queue<int> q;
  vi d(n+1, -1);
  
  q.push(1);
  d[1] = 0;
  
  int i = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (seq[i] != u) {
      cout << "No";
      return;
    }
    ++i;
    for (int v : g[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  
  cout << "Yes";
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








