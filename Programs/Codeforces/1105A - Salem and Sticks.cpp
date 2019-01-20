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
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ft = 1, fc = 1e9;
  for (int t = 1; t <= 100; ++t) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
      int diff = abs(a[i] - t);
      c += max(0, diff-1);
    }
    if (c < fc) {
      ft = t;
      fc = c;
    }
  }
  cout << ft << ' ' << fc << '\n';


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
