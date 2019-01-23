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
  string s;
  cin >> s;
  string ans = "";
  int mindiff = n;
  vector<char> init = {'R', 'G', 'B'};
  sort(init.begin(), init.end());
  do {
    int diff = 0;
    string t = "";
    for (int i = 0; i < n; ++i) {
      t += init[i % 3];
      if (s[i] != t[i]) {
        ++diff;
      }
    }
    if (diff < mindiff) {
      mindiff = diff;
      ans = t;
    }
  } while (next_permutation(init.begin(), init.end()));
  cout << mindiff << '\n' << ans << '\n';
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
