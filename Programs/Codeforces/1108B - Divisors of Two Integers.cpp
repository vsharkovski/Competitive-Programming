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
  int cnt[10002] = {};
  int x = -1, y = -1;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    ++cnt[d];
  }
  for (int d = 10000; d >= 1; --d) {
    if (cnt[d] > 0) {
      if (x == -1) {
        x = d;
        --cnt[d];
      } else {
        if (x % d == 0) {
          --cnt[d];
        }
      }
    }
  }
  for (int d = 10000; d >= 1; --d) {
    if (cnt[d] > 0) {
      y = d;
      break;
    }
  }
  cout << x << ' ' << y << '\n';
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
