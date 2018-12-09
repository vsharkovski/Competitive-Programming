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
  int n, m;
  cin >> n >> m;

  vi x(n), y(m);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> y[i];
  }

  int ans = 0;
  int sumx = 0, sumy = 0;
  int i = 0, j = 0;

  while (i < n || j < m) {
    if (sumx < sumy) {
      while (sumx < sumy) {
        sumx += x[i];
        ++i;
      }
    } else if (sumx > sumy) {
      while (sumy < sumx) {
        sumy += y[j];
        ++j;
      }
    } else {
      ++ans;
      if (i < n) {
        sumx += x[i];
        ++i;
      } else {
        sumy += y[i];
        ++j;
      }
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
