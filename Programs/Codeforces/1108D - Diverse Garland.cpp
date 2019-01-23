#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





void Main() {
  int n;
  string s;
  cin >> n >> s;
  string letters = "RGB";
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      ++ans;
      for (char ch : letters) {
        if (ch != s[i-1] && (i+1 == n || ch != s[i+1])) {
          s[i] = ch;
          break;
        }
      }
    }
  }
  cout << ans << '\n' << s << '\n';
}

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
