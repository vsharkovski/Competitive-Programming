#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int V, K;
int T[100005];
bool used[12];
int dist[100005];

void sssp() {
  fill(dist, dist+V+1, 1e9);
  dist[0] = 1;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.emplace(0, 1);
  while (!pq.empty()) {
    ii top = pq.top(); pq.pop();
    int u = top.second, d = top.first;
    if (d > dist[u]) continue;
    if (u > 1 && d + 1 < dist[u-1]) {
      dist[u-1] = d + 1;
      pq.emplace(d + 1, u-1);
    }
    if (u < V && d + 1 < dist[u+1]) {
      dist[u+1] = d + 1;
      pq.emplace(d + 1, u+1);
    }
    if (used[T[u]] == 0) {
      used[T[u]] = 1;
      for (int v = 1; v <= V; ++v) {
        if (v != u && T[v] == T[u] && d + K < dist[v]) {
          dist[v] = d + K;
          pq.emplace(d + K, v);
        }
      }
    }
  }
}

void Solve() {
  cin >> V >> K;
  for (int i = 1; i <= V; ++i) {
    cin >> T[i];
  }
  memset(used, 0, sizeof(used));
  sssp();
  cout << dist[V] << "\n";

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
