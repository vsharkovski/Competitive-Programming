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



bool ok(int n, vi v, int br) {
  v[0] += br;
  for (int i = 1; i < n; ++i) {
    if (v[i] >= v[0]) {
      int d = v[i] - v[0] + 1;
      if (br < d) {
        return false;
      }
      br -= d;
    }
  }
  return true;
}

void _SOLVE_() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int lo = 0, hi = 100*52, mid, ans;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (ok(n, v, mid)) {
      ans = mid;
      hi = mid-1;
    } else {
      lo = mid+1;
    }
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
