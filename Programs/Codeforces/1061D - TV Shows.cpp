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


const ll mod = 1e9 + 7;

void _SOLVE_() {
  int n;
  ll x, y;
  cin >> n >> x >> y;

  vpl a(n+1);
  vl cost(n+1);
  multiset<pair<pl, int>> s;

  for (int i = 1; i <= n; ++i) {
    ll l, r;
    cin >> l >> r;
    a[i] = pl(l, r);
    s.emplace(pl(r, l), i);
  }
  sort(a.begin(), a.end());

  for (int i = 1; i <= n; ++i) {
    ll l = a[i].first, r = a[i].second;
    cost[i] = x + y * (r - l);
    if (s.empty() || s.begin()->first.first >= l)
      continue;
    auto it = prev(s.lower_bound({pl(l, 0), 0}));
    ll pr = it->first.first;
    if (y * (r - pr) >= cost[i]) continue;
    cost[i] = y * (r - pr);
    s.erase(it);
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += cost[i];
    ans %= mod;
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
