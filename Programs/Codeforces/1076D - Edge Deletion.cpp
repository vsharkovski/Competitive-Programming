#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;



typedef pair<ll, int> plli;

int V, E, k;
vector<vector<pair<ii, int>>> G; // ((v, w), i)
vector<ii> edges;
vector<ll> dist;
vector<int> last;
vector<int> ans;

void sssp(int src) {
  dist.assign(V+1, 1e17);
  priority_queue<plli, vector<plli>, greater<plli>> pq;
  dist[src] = 0;
  pq.emplace(0, src);
  while (!pq.empty() && k > 0) {
    plli top = pq.top(); pq.pop();
    ll d = top.first;
    int u = top.second;
    if (d > dist[u]) continue;
    if (last[u] != -1) {
      ans.push_back(last[u]);
      --k;
    }
    for (pair<ii, int> &to : G[u]) {
      int v = to.first.first;
      ll w = to.first.second;
      if (d + w < dist[v]) {
        last[v] = to.second;
        dist[v] = d + w;
        pq.emplace(d + w, v);
      }
    }
  }
}

void Solve() {
  cin >> V >> E >> k;
  G.assign(V+1, vector<pair<ii, int>>());
  last.assign(V+1, -1);
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(ii(v, w), i);
    G[v].emplace_back(ii(u, w), i);
  }
  sssp(1);
  cout << ans.size() << endl;
  for (int i : ans) cout << i+1 << " ";
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
