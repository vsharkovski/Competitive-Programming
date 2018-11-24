#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int V, E;
vector<vector<ii>> G;

vector<int> taken;
priority_queue<ii, vector<ii>, less<ii>> pq;

void process(int u) {
  taken[u] = 1;
  for (ii &v : G[u])
    if (taken[v.first] == 0)
      pq.emplace(v.second, v.first);
}

int prim(int src) {
  taken.assign(V, 0);
  process(src);
  int minw = 1e9;
  while (!pq.empty()) {
    ii top = pq.top(); pq.pop();
    int u = top.second, w = top.first;
    if (taken[u] == 0) {
      minw = min(w, minw);
      process(u);
    }
  }
  return minw;
}

void Solve() {
  int T;
  cin >> T;
  for (int TC = 1; TC <= T; ++TC) {
    cin >> V >> E;
    G.assign(V, vector<ii>());
    for (int i = 0; i < E; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
    cout << "Case #" << TC << ": " << prim(0) << endl;
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
