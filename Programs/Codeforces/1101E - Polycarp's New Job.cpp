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
  int n;
  cin >> n;
  int max1 = 0, max2 = 0;
  while (n--) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      int x, y;
      cin >> x >> y;
      if (x < y) swap(x, y);
      if (x > max1) {
        max1 = x;
      }
      if (y > max2) {
        max2 = y;
      }
    } else {
      int h, w;
      cin >> h >> w;
      if ((max1 <= h && max2 <= w) || (max1 <= w && max2 <= h)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
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
