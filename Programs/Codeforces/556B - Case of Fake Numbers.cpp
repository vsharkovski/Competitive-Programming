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








void Solution() {

  int n;
  cin >> n;

  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int x = 0; x < n; ++x) {
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      int c = i % 2 == 0 ? (a[i] + x) % n : (a[i] - x + n) % n;
      if (c != i) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << "Yes\n";
      return;
    }
  }

  cout << "No\n";



}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}
