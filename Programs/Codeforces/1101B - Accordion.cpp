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
  cin >> s;
  int n = s.length();
  if (n < 4) {
    cout << -1;
    return;
  }
  int op = -1, cp = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '[') {
      op = i;
      break;
    }
  }
  if (op == -1) {
    cout << -1;
    return;
  }
  for (int i = n-1; i > op; --i) {
    if (s[i] == ']') {
      cp = i;
      break;
    }
  }
  if (cp == -1) {
    cout << -1;
    return;
  }
  int c1p = -1, c2p = -1;
  for (int i = op+1; i < cp; ++i) {
    if (s[i] == ':') {
      c1p = i;
      break;
    }
  }
  if (c1p == -1) {
    cout << -1;
    return;
  }
  for (int i = cp-1; i > c1p; --i) {
    if (s[i] == ':') {
      c2p = i;
      break;
    }
  }
  if (c2p == -1) {
    cout << -1;
    return;
  }
  // [:???:]
  int len = 4;
  for (int i = c1p+1; i < c2p; ++i) {
    if (s[i] == '|') {
      ++len;
    }
  }
  cout << len;

}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
