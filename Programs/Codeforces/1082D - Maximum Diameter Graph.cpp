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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



vector<vi> G;
vi dist;

int dfs(int u) {
  int frth = u;
  for (int v : G[u]) {
    if (dist[v] == -1) {
      dist[v] = dist[u] + 1;
      int k = dfs(v);
      if (dist[k] > dist[frth]) {
        frth = k;
      }
    }
  }
  return frth;
}

void _SOLVE_() {
  int n;
  cin >> n;

  vi a(n+1);
  vpi edges;
  G.assign(n+1, vi());

  vi order(n+1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    order[i] = i;
  }
  sort(order.begin()+1, order.end(), [&](int u, int v){
    return a[u] > a[v];
  });

  for (int i = 2; i <= n; ++i) {
    int u = order[i];
    bool done = 0;
    for (int j = i-1; j >= 1 && !done; --j) {
      int v = order[j];
      if (a[v] > 0) {
        a[v] -= 1;
        a[u] -= 1;
        edges.emplace_back(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
        done = 1;
      }
    }
    if (!done) {
//      cout << "bad: " << u << endl;
//      cout << "d: ";
//      for (int j = 1; j <= n; ++j) cout << d[j] << " ";
//      cout << endl;
//      cout << "edges:\n";
//      for (pi p : edges) cout << p.first << " " << p.second << endl;
      cout << "NO\n";
      return;
    }
    sort(order.begin()+1, order.begin()+i, [&](int u, int v){
      return a[u] < a[v];
    });
  }

  dist.assign(n+1, -1);
  dist[1] = 0;
  int frth = dfs(1);
  dist.assign(n+1, -1);
  dist[frth] = 0;
  int frth2 = dfs(frth);
  int dia = dist[frth2];

  cout << "YES " << dia << "\n" << edges.size() << "\n";
  for (pi& p : edges) {
    cout << p.first << " " << p.second << endl;
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
