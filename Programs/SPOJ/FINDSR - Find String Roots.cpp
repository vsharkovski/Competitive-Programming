#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;





bool ok(string& s, int n, int m) {
  for (int i = m; i < n; ++i) {
    if (s[i] != s[i-m]) {
      return false;
    }
  }
  return true;
}

void Main() {
  string s;
  while (cin >> s, s != "*") {
    int n = s.length();
    vector<int> divs;
    for (int m = 1; m*m <= n; ++m) {
      if (n % m == 0) {
        divs.push_back(m);
        divs.push_back(n/m);
      }
    }
    sort(divs.begin(), divs.end());
    for (int m : divs) {
      if (ok(s, n, m)) {
        cout << n/m << '\n';
        break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
