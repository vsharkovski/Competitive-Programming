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

  int T;
  cin >> T;
  while (T--) {

    int n;
    cin >> n;
    vector<pair<int, pi>> segs;
    for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      segs.emplace_back(i, pi(l, r));
    }
    sort(segs.begin(), segs.end(), [&](pair<int, pi>& a, pair<int, pi>&b) {
      return a.second.first == b.second.first ? a.second.second > b.second.second : a.second.first < b.second.first;
    });
    vector<int> t(n);
    t[segs[0].first] = 1;
    bool has2 = false;
    int r = segs[0].second.second;
    for (int i = 1; i < n; ++i) {
      if (segs[i].second.first <= r) {
        t[segs[i].first] = 1;
        r = max(r, segs[i].second.second);
      } else {
        has2 = true;
        t[segs[i].first] = 2;
      }
    }
    if (has2 == false) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n; ++i) {
        cout << t[i] << ' ';
      }
      cout << '\n';
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
