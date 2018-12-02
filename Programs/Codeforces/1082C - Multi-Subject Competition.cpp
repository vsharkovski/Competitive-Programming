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





void _SOLVE_() {
  int n, m;
  cin >> n >> m;

  vector<vl> groups(m+1);
  vector<vl> prefsums(m+1);
  set<pi> sizes;

  for (int i = 0; i < n; ++i) {
    int s, r;
    cin >> s >> r;
    groups[s].push_back(r);
  }
  for (int i = 1; i <= m; ++i) {
    sizes.emplace(groups[i].size(), i);
    sort(groups[i].rbegin(), groups[i].rend());
    prefsums[i] = groups[i];
    for (int j = 1; j < prefsums[i].size(); ++j) {
      prefsums[i][j] += prefsums[i][j-1];
    }
  }

  ll ans = 0;
  for (int k = 1; k <= n; ++k) {
    ll sum = 0;
    auto it = sizes.lower_bound({k, 0});
    while (it != sizes.end()) {
      ll t = prefsums[it->second][k-1];
      if (t > 0) sum += t;
      ++it;
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
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
