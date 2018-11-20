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
vector<int> value;
vector<int> sums;

void dfs(int u, int p, int s) {
  sums.push_back(s);
  for (int v : G[u]) {
    if (v != p) {
      dfs(v, u, s + value[v]);
    }
  }
}

void Solve() {
  int Q;
  cin >> V >> Q;
  G.assign(V+1, vector<int>());
  value.resize(V+1);
  for (int u = 1; u <= V; ++u) {
    int val, prv;
    cin >> val >> prv;
    ++prv;
    value[u] = val;
    G[prv].push_back(u);
  }
  for (int u : G[0]) {
    dfs(u, 0, value[u]);
  }
  sort(sums.begin(), sums.end());
  while (Q--) {
    int t;
    cin >> t;
    auto it = upper_bound(sums.begin(), sums.end(), t);
    if (it != sums.begin()) --it;
    if (*it <= t) {
      cout << *it << "\n";
    } else {
      cout << "none\n";
    }
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
