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

  int n, k;
  string s;
  cin >> n >> k >> s;

  bool okay[200] = {};
  for (int i = 0; i < n; ++i) {
    okay[int(s[i])] = 1;
  }

  if (n >= k) {
    string t = "";
    int i;
    for (i = 0; i < k; ++i) {
      t += s[i];
    }
    for (i = k-1; i >= 0; --i) {
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (okay[int(ch)] && ch > s[i]) {
          t[i] = ch;
          i = -1;
          break;
        }
      }
      if (i != -1) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (okay[int(ch)]) {
            t[i] = ch;
            break;
          }
        }
      }
    }
    cout << t << endl;
  } else {
    cout << s;
    char minch = 'z', maxch = 'a';
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (okay[int(ch)]) {
        minch = min(ch, minch);
        maxch = max(ch, maxch);
      }
    }
    while (n < k) {
      cout << minch;
      ++n;
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
