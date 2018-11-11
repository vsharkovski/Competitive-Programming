#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;







struct State {
  int d, u, k, l;
  State(int D, int U, int K, int L) : d(D), u(U), k(K), l(L) {}
  State() {}
  bool operator > (const State &rhs) const {
    return d > rhs.d;
  }
};

int V, K, L;
bool posebna[102];
vector<ii> G[102];
int dist[102][10][452];

void statespacesearch(int sn, int sk, int sl) {
  for (int u = 1; u <= 100; ++u)
    for (int k = 0; k <= 8; ++k)
      for (int l = 0; l <= 450; ++l)
        dist[u][k][l] = 1e9;
  priority_queue<State, vector<State>, greater<State>> pq;
  State ts(0, sn, sk, sl);
  dist[sn][sk][sl] = 0;
  pq.push(ts);
  while (!pq.empty()) {
    ts = pq.top(); pq.pop();
    int d = ts.d, u = ts.u, k = ts.k, l = ts.l;
    if (d > dist[u][k][l]) continue;

    //forcefully turn it off if you have to
    if (posebna[u] && l > 0) {
      l = 0;
    }
    //with auto system already on
    if (l > 0) {
      for (ii &to : G[u]) {
        int v = to.first, w = to.second;
        if (l >= w && d < dist[v][k][l-w]) {
          dist[v][k][l-w] = d;
          pq.emplace(d, v, k, l-w);
        }
      }
      //turn it off
      l = 0;
    }
    //with auto system off
    for (ii &to : G[u]) {
      int v = to.first, w = to.second;
      if (d + w < dist[v][k][l]) {
        dist[v][k][l] = d + w;
        pq.emplace(d+w, v, k, l);
      }
    }
    //if you turn it on
    if (k > 0) {
      --k;
      l = L;
      for (ii &to : G[u]) {
        int v = to.first, w = to.second;
        if (l >= w && d < dist[v][k][l-w]) {
          dist[v][k][l-w] = d;
          pq.emplace(d, v, k, l-w);
        }
      }
    }
  }
}

void Solve() {
  int X, E;
  cin >> V >> X >> K >> L >> E;
  for (int i = 1; i <= X; ++i)
    posebna[i] = 1;
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  statespacesearch(1, K, L);
  int res = 1e9;
  for (int k = 0; k <= K; ++k) {
    for (int l = 0; l <= L; ++l) {
      res = min(res, dist[V][k][l]);
    }
  }
  cout << res << endl;

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
