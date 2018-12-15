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
int a[100005];
bool b[100005];

bool getcurrval(int i, int l, int r) {
  if (a[i] > r && a[i-1] > r && a[i-2] > r && a[i-3] > r && a[i-4] > r && b[i-1] == 1 && b[i-2] == 1 && b[i-3] == 1 && b[i-4] == 1) {
    return 0;
  } else if (a[i] < l && a[i-1] < l && a[i-2] < l && a[i-3] < l && a[i-4] < l && b[i-1] == 0 && b[i-2] == 0 && b[i-3] == 0 && b[i-4] == 0) {
    return 1;
  } else {
    return b[i-1];
  }
}

void _SOLVE_() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    b[i] = ch == '1';
  }
  int l = -1e9, r = 1e9;
  for (int i = 4; i < n; ++i) {
    int curr = getcurrval(i, l, r);
    if (b[i] == 0 && curr == 1) {
      if (a[i] < l && a[i-1] < l && a[i-2] < l && a[i-3] < l && a[i-4] < l) {

      } else if (a[i] > r && a[i-1] > r && a[i-2] > r && a[i-3] > r && a[i-4] > r) {
        l = max({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}) + 1;
      } else {
        r = min({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}) - 1;
      }
    } else if (b[i] == 1 && curr == 0) {
      if (a[i] > r && a[i-1] > r && a[i-2] > r && a[i-3] > r && a[i-4] > r) {

      } else if (a[i] < l && a[i-1] < l && a[i-2] < l && a[i-3] < l && a[i-4] < l) {
        r = min({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}) - 1;
      } else {
        l = max({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}) + 1;
      }
    }
  }
  cout << l << " " << r << endl;
//  for (int i = 0; i < n; ++i) {
//    if (i >= 4) {
//      b[i] = getcurrval(i, l, r);
//      cout << b[i];
//    } else {
//      cout << b[i];
//    }
//  }
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
