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
  int n, d;
  cin >> n >> d;
  vi x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int dia = x[j] - x[i];
      int num = i + (n - j - 1);
      if (dia <= d) {
        ans = min(ans, num);
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
