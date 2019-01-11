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
  int n, k;
  cin >> n >> k;
  vi a(n);
  set<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  set<int> global;
  for (int i = 1; i <= k; ++i) {
    global.insert(i);
  }
  map<int, set<int>> done;
  vi ans;
  for (int i = 0; i < n; ++i) {
    if (!global.empty()) {
      int c = *global.begin();
      global.erase(global.begin());
      ans.push_back(c);
      done[a[i]].insert(c);
    } else {
      bool found = 0;
      for (int c = 1; c <= k; ++c) {
        if (done[a[i]].count(c) == 0) {
          done[a[i]].insert(c);
          ans.push_back(c);
          found = 1;
          break;
        }
      }
      if (!found) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for (int x : ans) cout  << x << ' ';
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
