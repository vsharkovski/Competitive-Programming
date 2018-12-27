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

  vector<pi> a(n+1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  vector<int> nxt(n+1, 0);
  nxt[0] = 0;

  for (int i = 1; i <= n; ++i) {
    int x = a[i].first, y = a[i].second;
    if (nxt[i] == x) {
      nxt[x] = y;
    } else if (nxt[i] == y) {
      nxt[y] = x;
    } else if (a[x].first == y || a[x].second == y) {
      nxt[i] = x;
      nxt[x] = y;
    } else {
      nxt[i] = y;
      nxt[y] = x;
    }
  }

  int k = 1;
  for (int i = 0; i < n; ++i) {
    cout << k << " ";
    k = nxt[k];
  }


}

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
