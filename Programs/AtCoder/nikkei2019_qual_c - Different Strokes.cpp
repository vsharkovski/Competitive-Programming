#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;







void Main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    d[i] = i;
  }
  sort(d.begin(), d.end(), [&](int i, int j) {
    return a[i] + b[i] < a[j] + b[j];
  });
  ll ans = 0;
  int t = 1;
  for (int i = n-1; i >= 0; --i) {
    if (t) {
      ans += a[d[i]];
    } else {
      ans -= b[d[i]];
    }
    t = !t;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
