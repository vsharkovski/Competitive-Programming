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



int ans;

int V, E;
vector<vector<int>> G, H; // H is G reversed
vector<int> CC;
vector<int> num, low, stk, instk;
int dfscalls, sccsize;
bool cycle;

void bidfs(int u) {
  num[u] = -1;
  CC.push_back(u);
  for (int v : G[u]) {
    if (num[v] == -2) {
      bidfs(v);
    }
  }
  for (int v : H[u]) {
    if (num[v] == -2) {
      bidfs(v);
    }
  }
}

void tarjanSCC(int u) {
  num[u] = low[u] = dfscalls++;
  stk.push_back(u);
  instk[u] = 1;
  for (int v : G[u]) {
    if (num[v] == -1) {
      tarjanSCC(v);
    }
    if (instk[v]) {
      low[u] = min(low[u], low[v]);
    }
  }
  if (num[u] == low[u]) {
    sccsize = 0;
//    cout << "- SCC: ";
    while (1) {
      int v = stk.back();
      stk.pop_back();
      instk[v] = 0;
      ++sccsize;
//      cout << v << ' ';
      if (v == u) {
        break;
      }
    }
    if (sccsize > 1) {
      cycle = true;
    }
//    cout << '\n';
  }
}

void Main() {
  cin >> V >> E;
  G.assign(V, vector<int>());
  H.assign(V, vector<int>());
  for (int i = 0; i < E; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    H[b].push_back(a);
  }
  ans = 0;
  num.assign(V, -2);
  low.assign(V, 0);
  instk.assign(V, 0);
  dfscalls = 0;
  for (int u = 0; u < V; ++u) {
    if (num[u] == -2) {
      CC.clear();
      bidfs(u);
//      cout << "CC: "; for (int v: CC) cout << v << ' '; cout << '\n';
      cycle = false;
      for (int v : CC) {
        if (num[v] == -1) {
          tarjanSCC(v);
        }
      }
//      cout << "--> cycle: " << cycle << '\n';
      if (cycle) {
        ans += CC.size();
      } else {
        ans += CC.size() - 1;
      }
    }
  }
  cout << ans << '\n';
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
