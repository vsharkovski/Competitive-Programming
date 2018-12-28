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
  vector<int> a(n-1);
  for (int i = 0; i < n-1; ++i) {
    int b;
    cin >> a[i] >> b;
    if (b != n) {
      cout << "NO\n";
      return;
    }
  }
  a.push_back(n);
  sort(a.begin(), a.end());
  vector<int> used(n+1, 0);
  vector<pi> ans;
  int v = a[0];
  used[a[0]] = 1;
  for (int i = 1; i < n; ++i) {
    int u = a[i];
    if (used[u]) {
      for (u = 1; u < a[i]; ++u) {
        if (used[u] == 0) {
          break;
        }
      }
      if (u == a[i]) {
        cout << "NO\n";
        return;
      }
    }
    ans.emplace_back(u, v);
    used[u] = 1;
    v = u;
  }
  cout << "YES\n";
  for (pi& p : ans) {
    cout << p.first << " " << p.second << "\n";
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
