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
  string a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt[26] = {};
    ++cnt[a[i]-'a'];
    ++cnt[b[i]-'a'];
    ++cnt[c[i]-'a'];
    int res = 2;
    for (int j = 0; j < 26; ++j) {
      if (cnt[j] == 3) {
        res = min(res, 0);
      }
    }
    for (int j = 0; j < 26; ++j) {
      if (cnt[j] == 2) {
        res = min(res, 1);
      }
    }
    ans += res;
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
