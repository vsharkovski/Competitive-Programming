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
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pi> segs;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    segs.emplace_back(x, y);
  }
  int ans = 0;
  vector<int> best;
  for (int i = 0; i < n; ++i) {
    int mini = 1e9, maxi = -1e9;
    for (int j = 0; j < m; ++j) {
      int x = segs[j].first, y = segs[j].second;
      if (x <= i && i <= y) {
        for (int k = x; k <= y; ++k) {
          --a[k];
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      mini = min(mini, a[j]);
      maxi = max(maxi, a[j]);
    }
    bool better = (maxi - mini) > ans;
    if (better) {
      best.clear();
      ans = maxi - mini;
    }
    for (int j = 0; j < m; ++j) {
      int x = segs[j].first, y = segs[j].second;
      if (x <= i && i <= y) {
        if (better) {
          best.push_back(j);
        }
        for (int k = x; k <= y; ++k) {
          ++a[k];
        }
      }
    }
  }
  cout << ans << '\n' << best.size() << '\n';
  for (int c : best) cout << c+1 << ' ';
}

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
