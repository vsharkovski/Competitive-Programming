include <bits/stdc++.h>
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
  string s;
  cin >> s;
  int n = s.length();
  int cnt = 0;
  stack<char> stk;
  for (int i = 0; i < n; ++i) {
    if (!stk.empty() && stk.top() == s[i]) {
      ++cnt;
      stk.pop();
    } else {
      stk.push(s[i]);
    }
  }
  if (cnt % 2 == 0) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
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
