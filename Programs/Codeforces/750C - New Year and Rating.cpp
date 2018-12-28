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



int n;
int c[200005];
int d[200005];

int can(ll r) {
  for (int i = 0; i < n; ++i) {
    if (r >= 1900 && d[i] == 2) {
      return -1;
    } else if (r < 1900 && d[i] == 1) {
      return 1;
    }
    r += c[i];
  }
  return 0;
}

void _SOLVE_() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> d[i];
  }
  ll l = -2e9, r = 2e9+1, mid, ans = -2e9-1;
  while (l <= r) {
    mid = (l + r) / 2;
    int res = can(mid);
    if (res >= 0) {
      if (res == 0) {
        ans = mid;
      }
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  if (ans == -2e9-1) {
    cout << "Impossible\n";
  } else if (ans == 2e9+1) {
    cout << "Infinity\n";
  } else {
    ll r = ans;
    for (int i = 0; i < n; ++i) {
      r += c[i];
    }
    cout << r << "\n";
  }
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
