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



void Main() {
  int n;
  cin >> n;
  vector<ll> a(n), p(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    p[i] = a[i];
    if (i > 0) p[i] += p[i-1];
  }
//  cout << "a: "; for (int i=0;i<n;++i){cout<<a[i]<<' ';}cout<<'\n';
//  cout << "p: "; for (int i=0;i<n;++i){cout<<p[i]<<' ';}cout<<'\n';
  ll ans = 1e17;
  for (int j = 1; j < n-1; ++j) {
    auto it = lower_bound(p.begin(), p.begin()+j, p[j]/2);
    int i = distance(p.begin(), it);
    if (i == j) {
      --i;
    }
    if (it != p.begin()) {
      ll opt1 = abs(p[j] - 2*p[i]);
      ll opt2 = abs(p[j] - 2*p[i-1]);
      if (opt2 < opt1) --i;
    }
    it = lower_bound(p.begin()+j+1, p.end(), (p[n-1] + p[j]) / 2);
    int k = distance(p.begin(), it);
    if (k == n) {
      --k;
    }
    if (k-1 > j) {
      ll opt1 = abs(p[n-1] + p[j] - 2*p[k]);
      ll opt2 = abs(p[n-1] + p[j] - 2*p[k-1]);
      if (opt2 < opt1) --k;
    }
    ll P = p[i];
    ll Q = p[j] - p[i];
    ll R = p[k] - p[j];
    ll S = p[n-1] - p[k];
    ans = min(ans, max({P, Q, R, S}) - min({P, Q, R, S}));
//    cout << "i=" << i << " j=" << j << " k=" << k << "; P=" << P << " Q=" << Q << " R="<<Q<<" S="<<S<<'\n';
  }
  cout << ans << '\n';
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
