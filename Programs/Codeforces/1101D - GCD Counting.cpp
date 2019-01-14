#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;




int V;
vector<int> a;
vector<vector<int>> G;
int ans;

void getpdivs(map<int, int>& pcnt, int n) {
  if (n % 2 == 0) {
    pcnt[2] = 1;
    while (n % 2 == 0) n /= 2;
  }
  if (n % 3 == 0) {
    pcnt[3] = 1;
    while (n % 3 == 0) n /= 3;
  }
  for (int k = 6; k*k <= n; k += 6) {
    for (int j = k-1; j <= k+1; j += 2) {
      if (n % j == 0) {
        pcnt[j] = 1;
        while (n % j == 0) n /= j;
      }
    }
  }
  if (n > 1) {
    pcnt[n] = 1;
  }
}

void dfs(int u, int parent, map<int, int>& pcnt) {
  getpdivs(pcnt, a[u]);
  map<int, pi> best;
  for (int v : G[u]) {
    if (v != parent) {
      map<int, int> kiddo;
      dfs(v, u, kiddo);
      for (auto& kvp : kiddo) {
        int p = kvp.first, cnt = kvp.second;
        if (pcnt[p] > 0) {
          pi& have = best.count(p) ? best[p] : best[p] = {0, 0};
          if (have.first <= cnt) {
            have.second = have.first;
            have.first = cnt;
          } else if (have.second < cnt) {
            have.second = cnt;
          }
        }
      }
    }
  }
  for (auto& kvp : best) {
    int p = kvp.first, cnt1 = kvp.second.first, cnt2 = kvp.second.second;
    ans = max(ans, cnt1 + 1 + cnt2);
    if (pcnt[p] > 0) {
      pcnt[p] = max(pcnt[p], 1 + cnt1);
    }
  }
}

void Main() {
  cin >> V;
  a.resize(V);
  G.resize(V);
  for (int i = 0; i < V; ++i) {
    cin >> a[i];
    if (a[i] > 1) {
      ans = 1;
    }
  }
  for (int i = 0; i < V-1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  ans = max(ans, 0);
  map<int, int> dummy;
  dfs(0, -1, dummy);
  cout << ans << '\n';
}


int main() {
  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
