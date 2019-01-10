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






vector<int> makez(string s) {
  int n = s.length();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i - l], r - i + 1));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      l = i;
      r = i + z[i];
      ++z[i];
    }
  }
  return z;
}

void Main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int len = s.length();
    int ans = len;
    string pref = "";
    for (int x = 1; x <= len; ++x) {
      bool okay = true;
      pref += s[x-1];
      vector<int> z = makez(pref + "#" + s);
      int n = pref.length() + 1 + len;
      for (int i = x + 1; i < n; i += x) {
        if (z[i] != x) {
          okay = false;
          break;
        }
      }
      if (okay) {
        ans = x;
        break;
      }
    }
    cout << ans << '\n';
    if (T > 0) cout << '\n';
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
