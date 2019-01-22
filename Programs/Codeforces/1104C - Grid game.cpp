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
  string s;
  cin >> s;
  int n = s.length();
  int cntv = 0, cnth = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (cntv == 0) {
        cout << "1 1\n";
        cntv = 1;
      } else {
        cout << "3 1\n";
        cntv = 0;
      }
    } else {
      if (cnth == 0) {
        cout << "4 3\n";
        cnth = 1;
      } else {
        cout << "4 1\n";
        cnth = 0;
      }
    }
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
