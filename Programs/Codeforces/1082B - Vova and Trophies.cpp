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
  string s;
  cin >> n >> s;

  bool gfirst = s[0] == 'G';
  int currlen = 1;
  vi v;

  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i-1]) {
      v.push_back(currlen);
      currlen = 1;
    } else {
      ++currlen;
    }
  }
  v.push_back(currlen);

  int ans = 0;
  n = v.size();

  for (int i = !gfirst; i < n; i += 2) {
    ans = max(ans, v[i]);
  }
  for (int i = gfirst; i < n-1; i += 2) {
    if (v[i] == 1 && i - 1 >= 0 && i + 1 < n && (i - 3 >= 0 || i + 3 < n)) {
      ans = max(ans, v[i-1] + 1 + v[i+1]);
    }
    if (v[i] == 1 && i - 1 >= 0 && i + 1 < n) {
      ans = max(ans, v[i-1] + v[i+1]);
    }
    if (v[i] > 1 && i - 1 >= 0 && i + 1 < n) {
        ans = max(ans, v[i-1] + 1);
        ans = max(ans, v[i+1] + 1);
    }
  }

  cout << ans << endl;
//  for (int x : v) cout << x << " ";


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
