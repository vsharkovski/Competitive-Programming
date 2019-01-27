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
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    t = s + "#" + t;
    int slen = s.length(), tlen = t.length();
    vector<int> z(tlen);
    {
      int l = 0, r = 0;
      for (int i = 1; i < tlen; ++i) {
        z[i] = max(0, min(z[i - l], r - i + 1));
        while (i + z[i] < tlen && t[z[i]] == t[i + z[i]]) {
          l = i;
          r = i + z[i];
          ++z[i];
        }
      }
    }
    int best = slen;
    for (int i = slen+1; i < tlen; ++i) {
      if (z[i] > z[best]) {
        best = i;
      }
    }
    for (int i = best + z[best] - 1; i >= best; --i) {
      cout << t[i];
    }
    cout << '\n';
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
