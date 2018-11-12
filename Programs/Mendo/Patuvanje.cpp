#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int V;
vector<vector<int>> G;
vector<unordered_set<int>> forbidden;
int dist[3003][3003];

void bfs(int src) {
  memset(dist, -1, sizeof(dist));
  dist[src][src] = 0;
  queue<ii> q;
  q.emplace(src, src);
  while (!q.empty()) {
    ii top = q.front(); q.pop();
    int u = top.first, v = top.second;
    int x = u*V + v;
    for (int k : G[v]) {
      if (forbidden[k].count(x) == 0 && dist[v][k] == -1) {
        dist[v][k] = dist[u][v] + 1;
        q.emplace(v, k);
      }
    }
  }
}

void Solve() {
  int E;
  cin >> V >> E;
  G.assign(V, vector<int>());
  forbidden.assign(V, unordered_set<int>());
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int u, v, k;
    cin >> u >> v >> k;
    forbidden[k].insert(u*V + v);
  }
  bfs(0);
  int res = 1e9;
  for (int v = 0; v < V; ++v) {
    if (dist[v][V-1] != -1) {
      res = min(res, dist[v][V-1]);
    }
  }
  if (res== 1e9) {
    cout << "GRESHKA\n";
  } else {
    cout << res << "\n";
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
