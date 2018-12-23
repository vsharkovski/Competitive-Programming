#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




int V, E, K;
vector<pi> G[100005];
bool special[100005];
int specialsrc;

bool possible(int cost) {
  bool visited[100005];
  queue<int> q;
  int numspecial = 0;
  memset(visited, 0, sizeof(visited));
  visited[specialsrc] = 1;
  q.push(specialsrc);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (special[u]) {
      ++numspecial;
    }
    for (pi& to : G[u]) {
      int v = to.first, w = to.second;
      if (w <= cost && visited[v] == 0) {
        visited[v] = 1;
        q.push(v);
      }
    }
  }
  return numspecial == K;
}

void _SOLVE_() {
  cin >> V >> E >> K;
  memset(special, 0, sizeof(special));
  for (int i = 0; i < K; ++i) {
    int x;
    cin >> x;
    --x;
    special[x] = 1;
    specialsrc = x;
  }
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  int lo = 1, hi = 1e9, mid, ans = 1e9;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (possible(mid)) {
      ans = mid;
      hi = mid-1;
    } else {
      lo = mid+1;
    }
  }
  for (int i = 0; i < K; ++i) {
    cout << ans << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}

/**
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



class DSU {
public:
  vector<int> p, rank;
  DSU(int n) {
    rank.assign(n, 0);
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return p[x] == x ? x : (p[x] = get(p[x]));
  }
  inline bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x != y) {
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) {
          ++rank[y];
        }
      }
      return true;
    }
    return false;
  }
};

int V, E, K;
bool special[100005];
vector<vector<pi>> G; // MST
int ans;

int dfs(int u, int p) {
  int res = special[u];
  for (pi to : G[u]) {
    int v = to.first, w = to.second;
    if (v != p) {
      int hasspecial = dfs(v, u);
      if (hasspecial) {
        ans = max(ans, w);
        res = 1;
      }
    }
  }
  return res;
}

void _SOLVE_() {
  cin >> V >> E >> K;
  memset(special, 0, sizeof(special));
  for (int i = 0; i < K; ++i) {
    int x;
    cin >> x;
    --x;
    special[x] = 1;
  }
  vector<pair<int, pi>> edges;
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.emplace_back(w, pi(u, v));
  }
  sort(edges.begin(), edges.end());
  G.assign(V, vector<pi>());
  DSU dsu(V);
  for (int i = 0; i < E; ++i) {
    int w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
    if (dsu.get(u) != dsu.get(v)) {
      dsu.unite(u, v);
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
  }
  ans = 0;
  for (int i = 0; i < V; ++i) {
    if (special[i]) {
      dfs(i, -1);
      break;
    }
  };
  for (int i = 0; i < K; ++i) {
    cout << ans << " ";
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
**/
