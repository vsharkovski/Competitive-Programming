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
  int n;
  cin >> n;
  vi a(n+2);
  a[0] = 0;
  a[n+1] = 1001;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int o1 = 0;
  for (int i = 0; i <= n+1; ++i) {
    for (int j = i; j <= n+1; ++j) {
      bool ok = 1;
      for (int k = i+1; k <= j && ok; ++k) {
        if (a[k] != 1+a[k-1])
          ok = 0;
      }
      if (ok) {
        o1 = max(o1, j-i-1);
      }
    }
  }
  cout << o1 << endl;






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
