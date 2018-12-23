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





int V, E;
vector<vector<int>> G;
bool woke[30];
int dist[30];
bool inqueue[30];
queue<int> q;
int ans;

void shitinput() {
  int id[200];
  fill(id, id+190, -1);
  int numids = 0;
  for (int i = 0; i < 3; ++i) {
    char ch;
    cin >> ch;
    if (id[ch] == -1) {
      id[ch] = numids;
      ++numids;
    }
    int u = id[ch];
    woke[u] = 1;
    dist[u] = 0;
    q.push(u);
    inqueue[u] = 1;
  }
  for (int i = 0; i < E; ++i) {
    char ch1, ch2;
    cin >> ch1 >> ch2;
    if (id[ch1] == -1) {
      id[ch1] = numids;
      ++numids;
    }
    if (id[ch2] == -1) {
      id[ch2] = numids;
      ++numids;
    }
    int u = id[ch1], v = id[ch2];
    G[u].push_back(v);
    G[v].push_back(u);
  }
}

void _SOLVE_() {
  while (cin >> V >> E) {
    G.assign(V+1, vector<int>());
    fill(woke, woke+V+1, 0);
    fill(dist, dist+V+1, 1001);
    fill(inqueue, inqueue+V+1, 0);
    shitinput();
    while (!q.empty()) {
      int u = q.front(); q.pop();
      inqueue[u] = 0;
      if (woke[u] == 0) {
        int dists[3] = {1000, 1000, 1000};
        for (int v : G[u]) {
          if (woke[v] == 1) {
            for (int i = 0; i < 3; ++i) {
              if (dist[v] <= dists[i]) {
                for (int j = 2; j > i; --j) {
                  dists[j] = dists[j-1];
                }
                dists[i] = dist[v];
                break;
              }
            }
          }
        }
        if (dists[2] < 1000) {
          dist[u] = dists[2] + 1;
          woke[u] = 1;
        }
      }
      if (woke[u] == 1) {
        for (int v : G[u]) {
          if (woke[v] == 0) {
            if (inqueue[v] == 0) {
              inqueue[v] = 1;
              q.push(v);
            }
          }
        }
      }
    }
    ans = 0;
    for (int u = 0; u < V; ++u) {
      ans = max(ans, dist[u]);
    }
    if (ans < 1000) {
      cout << "WAKE UP IN, " << ans << ", YEARS\n";
    } else {
      cout << "THIS BRAIN NEVER WAKES UP\n";
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
  _SOLVE_();
}
