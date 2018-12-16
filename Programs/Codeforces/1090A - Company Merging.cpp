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

  int n;
  cin >> n;

  multiset<pl> s;

  for (int i = 0; i < n; ++i) {
    ll sz, mx = 0;
    cin >> sz;
    for (int j = 0; j < sz; ++j) {
      ll m;
      cin >> m;
      mx = max(m, mx);
    }
    s.emplace(mx, sz);
  }

  ll ans = 0;

  while (s.size() >= 2) {
    auto it1 = s.begin(), it2 = next(it1);
    ll mx1 = it1->first, sz1 = it1->second, mx2 = it2->first, sz2 = it2->second;
    s.erase(it1);
    s.erase(it2);
    ans += (mx2 - mx1) * sz1;
    s.emplace(mx2, sz1 + sz2);
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
