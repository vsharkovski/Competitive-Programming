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





int V, E, numids;
map<string, int> strtoid;
map<int, string> idtostr;
vector<vi> G;
vi dfs_num, dfs_low, S, inS;
int dfscalls;

int getid(string& s) {
  if (strtoid.count(s) == 0) {
    strtoid[s] = numids;
    idtostr[numids] = s;
    ++numids;
  }
  return strtoid[s];
}

void tarjanSCC(int u) {
  dfs_num[u] = dfs_low[u] = dfscalls++;
  S.push_back(u);
  inS[u] = 1;
  for (int v : G[u]) {
    if (dfs_num[v] == -1) {
      tarjanSCC(v);
    }
    if (inS[v]) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }
  if (dfs_low[u] == dfs_num[u]) {
    bool first = true;
    while (1) {
      int v = S.back();
      S.pop_back();
      inS[v] = 0;
      if (first) {
        first = false;
      } else {
        cout << ", ";
      }
      cout << idtostr[v];
      if (v == u) {
        break;
      }
    }
    cout << "\n";
  }
}

void Main() {
  int Case = 1;
  while (cin >> V >> E, V != 0 || E != 0) {
    G.assign(V, vi());
    numids = 0;
    strtoid.clear();
    idtostr.clear();
    for (int i = 0; i < E; ++i) {
      string a, b;
      cin >> a >> b;
      int u = getid(a), v = getid(b);
      G[u].push_back(v);
    }
    dfs_num.assign(V, -1);
    dfs_low.assign(V, 0);
    inS.assign(V, 0);
    dfscalls = 0;
    if (Case > 1) cout << "\n";
    cout << "Calling circles for data set " << Case++ << ":\n";
    for (int u = 0; u < V; ++u) {
      if (dfs_num[u] == -1) {
        tarjanSCC(u);
      }
    }
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
