#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




int V, E;
vector<vi> G, H; // H is G reversed
vector<vi> scc;
vi sccid;

vi num, low, stk, instk;
int calls;

void tarjan(int u) {
  num[u] = low[u] = calls++;
  stk.push_back(u);
  instk[u] = 1;
  for (int v : G[u]) {
    if (num[v] == -1) {
      tarjan(v);
    }
    if (instk[v]) {
      low[u] = min(low[u], low[v]);
    }
  }
  if (num[u] == low[u]) {
    scc.push_back(vi());
    while (1) {
      int v = stk.back();
      stk.pop_back();
      instk[v] = 0;
      scc.back().push_back(v);
      if (v == u) {
        break;
      }
    }
  }
}

void Main() {
  int T, Case = 1;
  cin >> T;
  while (T--) {
    cin >> V >> E;
    G.assign(V, vi());
    H.assign(V, vi());
    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      G[u].push_back(v);
      H[v].push_back(u);
    }
    scc.clear();
    num.assign(V, -1);
    low.assign(V, 0);
    instk.assign(V, 0);
    calls = 0;
    for (int u = 0; u < V; ++u) {
      if (num[u] == -1) {
        tarjan(u);
      }
    }
    sccid.assign(V, 0);
    int ans = 0;
    for (int i = 0; i < scc.size(); ++i) {
      for (int u : scc[i]) {
        sccid[u] = i;
      }
    }
    for (int i = 0; i < scc.size(); ++i) {
      bool alone = true;
      for (int u : scc[i]) {
        for (int v : H[u]) {
          if (sccid[v] != sccid[u]) {
            alone = false;
            break;
          }
        }
        if (!alone) {
          break;
        }
      }
      if (alone) {
        ++ans;
      }
    }
    cout << "Case " << Case++ << ": " << ans << '\n';
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
