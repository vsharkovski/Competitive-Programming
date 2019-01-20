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
  int n, k;
  string s;
  cin >> n >> k >> s;
  int cnt[200] = {};
  int len;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && s[i] == s[i-1]) {
      ++len;
    } else {
      len = 1;
    }
    if (len == k) {
      ++cnt[s[i]];
      len = 0;
    }
  }
  int ans = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    ans = max(ans, cnt[ch]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
