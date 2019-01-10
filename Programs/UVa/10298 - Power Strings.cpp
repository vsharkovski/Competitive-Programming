#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;







void Main() {
  string s;
  while (cin >> s, s != ".") {
    set<int> divs;
    int n = s.length();
    for (int x = 1; x*x <= n; ++x) {
      if (n % x == 0) {
        divs.insert(x);
        divs.insert(n/x);
      }
    }
    for (int x : divs) {
      bool ok = true;
      for (int i = x; i < n; ++i) {
        if (s[i] != s[i-x]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << n/x << '\n';
        break;
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
