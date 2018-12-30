#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





void _SOLVE_() {
  map<pi, int> cnt;
  int n;
  cin >> n;
  vpi obe;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    obe.emplace_back(x, y);
  }
  vpi clues;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    clues.emplace_back(a, b);
  }
  for (int i = 0; i < n; ++i) {
    int a = clues[i].first, b = clues[i].second;
    for (int j = 0; j < n; ++j) {
      int x = obe[j].first, y = obe[j].second;
      ++cnt[{x+a, y+b}];
    }
  }
  for (auto& p : cnt) {
    if (p.second == n) {
      cout << p.first.first << ' ' << p.first.second << '\n';
      return;
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
  _SOLVE_();
}
