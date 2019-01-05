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

  int n, m;
  cin >> n >> m;

  int bl = 0, br = 1e9;
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    if (r - l < br - bl) {
      bl = l, br = r;
    }
  }

  int mex = br - bl + 1;
  cout << mex << '\n';
  for (int i = 0; i < n; ++i) {
    cout << i % mex << ' ';
  }

}












int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
