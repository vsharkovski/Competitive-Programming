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
vector<int> dist;
vector<int> prevmask;
vector<int> prevnode;

void bfs() {
  dist.assign(1 << V, -1);
  prevmask.assign(1 << V, -1);
  prevnode.assign(1 << V, -1);
  queue<int> q;
  dist[(1 << V) - 1] = 0;
  q.push((1 << V) - 1);
  while (!q.empty()) {
    int ts = q.front(); q.pop();
    for (int u = 0; u < V; ++u) {
      int s1 = 0;
      for (int v = 0; v < V; ++v)
        for (int k : G[v])
          if (v != u && (ts & (1 << k)))
            s1 |= (1 << v);
      if (dist[s1] == -1) {
        dist[s1] = dist[ts] + 1;
        prevmask[s1] = ts;
        prevnode[s1] = u;
        q.push(s1);
      }
    }
  }
}

void Solve() {
  int E;
  cin >> V >> E;
  if (E >= V) { // not tree (has cycle)
    cout << "-1\n";
    return;
  }
  G.assign(V, vector<int>());
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bfs();
  if (dist[0] == -1) {
    cout << "-1\n";
    return;
  }
  vector<int> ans;
  int s = 0;
  while (s != (1 << V) - 1) {
    ans.push_back(prevnode[s]);
    s = prevmask[s];
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int u : ans) {
    cout << u+1 << " ";
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
