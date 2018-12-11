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
  int n;
  ll s;
  cin >> n >> s;
  vector<ll> v(n);
  ll total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    total += v[i];
  }
  if (total < s) {
    cout << -1;
    return;
  }
  sort(v.begin(), v.end());
  for (int i = n-1; i >= 1; --i) {
    if (v[i] == v[0]) break;
    if (s <= v[i] - v[0]) {
      cout << v[0];
      return;
    } else {
      ll x = v[i] - v[0];
      s -= x;
      v[i] -= x;
    }
  }
  if (s == 0) {
    cout << v[0];
    return;
  }
  ll q = v[0] - s/n - (s % n != 0);
  cout << q << endl;
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
