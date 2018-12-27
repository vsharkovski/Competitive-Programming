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




void _SOLVE_() {

  int n, m;
  vector<pl> input, d;
  vector<int> pos;
  vector<ll> prefsum, suffsum;
  vector<vector<int>> G;

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    input.emplace_back(a, b);
    d.emplace_back(a - b, i);
  }

  G.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  sort(d.begin(), d.end());

  pos.resize(n);
  for (int i = 0; i < n; ++i) {
    pos[d[i].second] = i;
  }

  suffsum.resize(n);
  suffsum[n-1] = input[d[n-1].second].second; // b
  for (int i = n-2; i >= 0; --i) {
    suffsum[i] = suffsum[i+1] + input[d[i].second].second;
  }

  prefsum.resize(n);
  prefsum[0] = input[d[0].second].first; // a
  for (int i = 1; i < n; ++i) {
    prefsum[i] = prefsum[i-1] + input[d[i].second].first;
  }

  for (int i = 0; i < n; ++i) {
    int p = pos[i];
    ll a = input[i].first, b = input[i].second;
    ll res = 0;
    if (p < n-1) {
      res += suffsum[p+1] + a*(n - p - 1);
    }
    if (p > 0) {
      res += prefsum[p-1] + b*(p);
    }
    for (int j : G[i]) {
      res -= min(input[i].first + input[j].second, input[i].second + input[j].first);
    }
    cout << res << " ";
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
