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

  int n, x, y;
  cin >> n >> x >> y;

  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int numsmaller = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= x) {
      ++numsmaller;
    }
  }

  if (x <= y) {
    cout << numsmaller / 2 + (numsmaller % 2);
  } else if (x > y) {
    cout << n << '\n';
  } else {

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
