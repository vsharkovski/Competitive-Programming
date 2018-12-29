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
  int n, k;
  int a[100005], t[100005];
  int normal[100005], total[100005];
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  a[0] = t[0] = normal[0] = total[0] = 0;
  for (int i = 1; i <= n; ++i) {
    total[i] = total[i-1] + a[i];
    normal[i] = normal[i-1];
    if (t[i]) {
      normal[i] += a[i];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n-k+1; ++i) {
    ans = max(ans, normal[i-1] + (total[i+k-1] - total[i-1]) + (normal[n] - normal[i+k-1]));
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
