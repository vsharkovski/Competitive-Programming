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
  vector<int> h(n), c(n, 0);
  vector<pi> hs;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    hs.emplace_back(h[i], i);
  }
  sort(hs.begin(), hs.end());
  int ans = 0;
  for (int t = 0; t < n; ++t) {
    int tidx = hs[t].second;
    if (c[tidx] < h[tidx]) {
      int incr = h[tidx] - c[tidx];
      ans += incr;
      for (int i = tidx, j = tidx+1; ;) {
        bool did = 0;
        if (i >= 0 && c[i] < h[i]) {
          c[i] += incr;
          --i;
          did = 1;
        }
        if (j < n && c[j] < h[j]) {
          c[j] += incr;
          ++j;
          did = 1;
        }
        if (!did) break;
      }
    }
//    cout << "tidx=" << tidx << "; c: ";
//    for (int z : c) cout << z << ' ';
//    cout << "\n";
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
