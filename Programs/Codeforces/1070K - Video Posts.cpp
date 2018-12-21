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

  int n, k;
  int a[100005];
  int sum = 0;

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum % k != 0) {
    cout << "No\n";
    return;
  }

  int avg = sum / k;
  int curr = 0;
  int len = 0;
  vector<int> ans;

  for (int i = 0; i < n; ++i) {
    curr += a[i];
    ++len;
    if (curr > avg) {
      cout << "No\n";
      return;
    } else if (curr == avg) {
      ans.push_back(len);
      len = 0;
      curr = 0;
    }
  }

  if (curr != 0 || ans.size() != k) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  for (int l : ans) {
    cout << l << " ";
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
